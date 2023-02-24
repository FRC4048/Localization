
function amcl_test() %#codegen

    fprintf("Starting\n");
    mapSub = rossubscriber('/map',"nav_msgs/OccupancyGrid","DataFormat","struct");
    laserSub = rossubscriber("/scan","sensor_msgs/LaserScan","DataFormat","struct");
    fprintf("Found /scan and /map topics\n");
%     map = binaryOccupancyMap(100,100);
    map = rosReadBinaryOccupancyGrid(receive(mapSub));
    fprintf("reveived map\n");
    odometryModel = odometryMotionModel;
    odometryModel.Noise = [0.2 0.2 0.2 0.2];
    

    rangeFinderModel = likelihoodFieldSensorModel;
    rangeFinderModel.SensorLimits = [0.45 8];
    rangeFinderModel.Map = map;
    


    % Query the Transformation Tree (tf tree) in ROS.
    fprintf("waiting for tf Tree");
    tftree = rostf("DataFormat","struct");
    fprintf("found transformationTree")
    waitForTransform(tftree,'base_link','base_scan');
    fprintf("Found tf transformation between base_link and base_scan");
    sensorTransform = getTransform(tftree,'base_link', 'base_scan');
  
    % Get the euler rotation angles.
    laserQuat = [sensorTransform.Transform.Rotation.W sensorTransform.Transform.Rotation.X ...
        sensorTransform.Transform.Rotation.Y sensorTransform.Transform.Rotation.Z];
    laserRotation = quat2eul(laserQuat, 'ZYX');


    % Setup the |SensorPose|, which includes the translation along base_link's
    % +X, +Y direction in meters and rotation angle along base_link's +Z axis
    % in radians.
    rangeFinderModel.SensorPose = ...
        [sensorTransform.Transform.Translation.X sensorTransform.Transform.Translation.Y laserRotation(1)];


    
    odomSub = rossubscriber('/imu',"geometry_msgs/Point","DataFormat","struct");
    %create ros publisher named debug and msg oject to send data
    [debug,msg] = rospublisher('/my_msg_epic',"geometry_msgs/PointStamped","DataFormat","struct");
    [odom_vis_pub,odom_vis_msg] = rospublisher('/odomVis',"geometry_msgs/PointStamped","DataFormat","struct");
    amcl = monteCarloLocalization;

    amcl.UseLidarScan = true;
    amcl.MotionModel = odometryModel;
    amcl.SensorModel = rangeFinderModel;
    
    amcl.UpdateThresholds = [0.2,0.2,0.2];
    amcl.ResamplingInterval = 1;
    
    amcl.ParticleLimits = [500 5000];
    amcl.GlobalLocalization = false;
    amcl.InitialCovariance = eye(3)*0.5;

    amcl.InitialPose = [0,0,0];

    while (1)
        % Receive laser scan and odometry message.
        [scanMsg,status,statustext] = receive(laserSub,10);
        odompose = odomSub.LatestMessage;
        if(status)
            % Only keep lidar data between angle 200 and 350 (rest is obstructed)
             scan = rosReadLidarScan(scanMsg);
             scan2 = removeInvalidData(scan,'AngleLimits',[deg2rad(200), deg2rad(350)]);
            
            % Compute robot's pose [x,y,yaw] from odometry message.    
            pose = [odompose.X, odompose.Y odompose.Z];

            % send odom data back to ros with a frame id so we can see it in rviz           
            odom_vis_msg.X = odompose.X;
            odom_vis_msg.Y = odompose.Y;
            odom_vis_msg.Z = 0;
            odom_vis_msg.Header.FrameId = 'odomVis';
            send(odom_vis_pub,odom_vis_msg)
            
            % Update estimated robot's pose and covariance using new odometry and
            % sensor readings.
            [isUpdated,estimatedPose, estimatedCovariance] = amcl(pose, scan2);
            % Set the message object values(x,y,z) created by the publisher to the
            % x,y,and yaw of the estimated pos
            msg.Point.X = estimatedPose(1); %pos x
            msg.Point.Y = estimatedPose(2); %pos y
            msg.Point.Z = 0; %pos yaw
            msg.Header.FrameId = 'matlab_msg';
            send(debug,msg);
            fprintf("estimated pose = (%f,%f,%f)\n",estimatedPose(1),estimatedPose(2),estimatedPose(3));
        end
      

    end

end
   

