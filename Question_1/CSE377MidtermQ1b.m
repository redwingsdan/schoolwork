%Daniel Peterson - 109091561

img = imread('brain.tech.jpg'); %name of the input image
img2 = rgb2gray(img);   %convert to grayscale
lowerThreshold = 115;   %set the lower threshold for the image
upperThreshold = 155;   %set the upper threshold for the image
mask= img2 < lowerThreshold;     %apply the lower threshold to the image
invertMask = img2 > upperThreshold; %apply the upper threshold to the image
img2(mask) = 0;      %sets the lower values to 0
img2(invertMask) = 0; %sets the upper values to 0
imagesc(img2);          %display the image
imwrite(img2, 'brain.tech-thresh.jpg', 'jpg'); %write the image

%The tumor is a middle grayscale value so the brightest and darkest
%pixels must be masked. The remaining values are the ones in the middle
%which represent the tumor