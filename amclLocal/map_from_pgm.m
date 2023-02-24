image = imread('testMap.pgm');
imageNorm = double(image)/255;
imageOccupancy = 1 - imageNorm;
map = binaryOccupancyMap(imageOccupancy,30*56);
show(map)