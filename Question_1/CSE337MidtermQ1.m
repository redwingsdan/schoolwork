%Daniel Peterson - 109091561

img = imread('heart.jpg'); %name of the input image
img2 = rgb2gray(img);   %convert to grayscale
bright=img2*1.4;        %scale the brightness to make the chambers more pronounced
threshold = 230;        %set the threshold for the image
mask= bright > threshold;     %apply the threshold to the image
img2(~mask) = 0;        %make the non-bright values(the non-chambers) dark
%this line could be img2(mask) = 255 to keep the background in tact
imagesc(img2);          %display the image
imwrite(img2, 'heart-thresh.jpg', 'jpg'); %write the image

%The heart chambers are shown as the bright yellow spots. They are very
%bright relative to the rest of the image and therefore only a lower
%threshold is needed to segment the chambers from the rest of the image