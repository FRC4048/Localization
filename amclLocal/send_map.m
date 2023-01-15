% Clear matlab memory
clear
% if ros is intitalized in matlab stop it
rosshutdown
% IP adress of ros server
ipaddress = 'http://10.11.6.38:11311';
% connect to ros server
rosinit(ipaddress);
% setup publisher for map
[mapPublisher,msg] = rospublisher('/my_map',"nav_msgs/OccupancyGrid","DataFormat","struct");
% load the map 
load officemap.mat
% populate ros message with map data
msg = rosWriteBinaryOccupancyGrid(msg,map);
% send the data to ros
send(mapPublisher,msg);