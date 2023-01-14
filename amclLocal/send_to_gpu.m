% Clear everything before starting
clear; 
cfg = coder.config("exe");
cfg.Hardware = coder.hardware("Robot Operating System (ROS)");
cfg.Hardware.DeployTo = 'Remote Device';
cfg.Hardware.BuildAction = 'Build and load';
cfg.Hardware.RemoteDeviceAddress = '10.11.6.38';
cfg.Hardware.RemoteDeviceUsername = 'bzeliger';
cfg.Hardware.RemoteDevicePassword = 'Redshift';
cfg.Hardware.ROSFolder = '/opt/ros/melodic';
cfg.HardwareImplementation.ProdHWDeviceType = "Generic->Custom";
cfg.HardwareImplementation.ProdLongLongMode = true; % Use 'long long' for Int64 or Uint64 data types
codegen amcl_test -config cfg
