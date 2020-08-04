%Daniel Peterson - 109091561

img = imread('brain.tech.jpg'); %name of the input image
img2 = rgb2gray(img);   %convert to grayscale
img3 = histeq(img2);    %create histogram
figure,
imshow(img3);           %display image
imwrite(img3, 'brain.tech-histEq.jpg', 'jpg'); %write image

img = imread('heart.jpg'); %name of the input image
img2 = rgb2gray(img);   %convert to grayscale
img3 = histeq(img2);    %create histogram
figure,
imshow(img3);           %display image
imwrite(img3, 'heart-histEq.jpg', 'jpg'); %write image

%The grayscale values are evenly distributed in a histogram
%equalized image. The average pixel value is used and there is
%a certain step value in between each increment of pixel colors.
%As the step value increases, so does the intensity of each
%pixel represented by the value on the histogram
%Ideally, each step value will have an equal number of
%pixels at each intensity.