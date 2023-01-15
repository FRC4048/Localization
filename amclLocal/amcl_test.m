function amcl_test() %#codegen

    mapSub = rossubscriber('/my_map',"nav_msgs/OccupancyGrid","DataFormat","struct");
    laserSub = rossubscriber("/scan","sensor_msgs/LaserScan","DataFormat","struct");
%     map = binaryOccupancyMap(100,100);
    map = rosReadBinaryOccupancyGrid(receive(mapSub));
    odometryModel = odometryMotionModel;
    odometryModel.Noise = [0.2 0.2 0.2 0.2];
    

    rangeFinderModel = likelihoodFieldSensorModel;
    rangeFinderModel.SensorLimits = [0.45 8];
    rangeFinderModel.Map = map;
    


    % Query the Transformation Tree (tf tree) in ROS.
    
    tftree = rostf("DataFormat","struct");
    waitForTransform(tftree,'base_link','base_scan');
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


    
    odomSub = rossubscriber('/odom',"nav_msgs/Odometry","DataFormat","struct");
    %create ros publisher named debug and msg oject to send data
    [debug,msg] = rospublisher('/my_msg_epic',"geometry_msgs/Point","DataFormat","struct");
    
    amcl = monteCarloLocalization;
    amcl.UseLidarScan = true;
    
    amcl.MotionModel = odometryModel;
    amcl.SensorModel = rangeFinderModel;
    
    amcl.UpdateThresholds = [0.2,0.2,0.2];
    amcl.ResamplingInterval = 1;
    
    amcl.ParticleLimits = [500 5000];
    amcl.GlobalLocalization = false;
%     amcl.InitialPose = ExampleHelperAMCLGazeboTruePose;
    amcl.InitialCovariance = eye(3)*0.5;

    while (1)
        % Receive laser scan and odometry message.
        [scanMsg,status,statustext] = receive(laserSub,10);
        odompose = odomSub.LatestMessage;
        if(status)
             cart = rosReadCartesian(scanMsg);
             scan = lidarScan(cart);
               % Create lidarScan object to pass to the AMCL object.
            % For sensors that are mounted upside down, you need to reverse the
            % order of scan angle readings using 'flip' function.
            
            % Compute robot's pose [x,y,yaw] from odometry message.
            odomQuat = [odompose.Pose.Pose.Orientation.W, odompose.Pose.Pose.Orientation.X, ...
                odompose.Pose.Pose.Orientation.Y, odompose.Pose.Pose.Orientation.Z];
            odomRotation = quat2eul(odomQuat);
            pose = [odompose.Pose.Pose.Position.X, odompose.Pose.Pose.Position.Y odomRotation(1)];
            
            % Update estimated robot's pose and covariance using new odometry and
            % sensor readings.
            [isUpdated,estimatedPose, estimatedCovariance] = amcl(pose, scan);
            % Set the message object values(x,y,z) created by the publisher to the
            % x,y,and yaw of the estimated pos
            msg.X = estimatedPose(1); %pos x
            msg.Y = estimatedPose(2); %pos y
            msg.Z = estimatedPose(3); %pos yaw
            send(debug,msg);
            
            % Drive robot to next pose.
          %  wander(wanderHelper);
        end
      

    end
    %}

    i = 0;
    while (i < 5)
        scan = receive(laserSub);
%         fprintf("OUTPUT=%",scan);
        if ~isempty(scan)
            fprintf("ANGLE MIN = %f\n",scan.AngleMin);
            i = i + 1;
        else
            fprintf("Received empty message..\n");
        end
    end

end
   

