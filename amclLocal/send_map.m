% Clear matlab memory
clear

% if ros is intitalized in matlab stop it
rosshutdown
% IP adre
% ss of ros server
ipaddress = 'http://10.40.48.95:11311';
% connect to ros server
rosinit(ipaddress);
% setup publisher for map
[mapPublisher,msg] = rospublisher('/map',"nav_msgs/OccupancyGrid","DataFormat","struct");
% load the map 

%load officemap.mat
% image = imread('testMap.pgm');
% imageNorm = double(image)/255;
% imageOccupancy = 1 - imageNorm;
% map = binaryOccupancyMap(imageOccupancy,30*56);
% populate ros message with map data
map = binaryOccupancyMap(2048,2048);
msg = rosWriteBinaryOccupancyGrid(msg,map);
% send the data to ros
send(mapPublisher,msg);
fprintf("SentMap\n");