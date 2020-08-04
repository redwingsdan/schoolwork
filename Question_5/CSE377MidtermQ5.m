%Daniel Peterson - 109091561

img = imread('brain.tech.jpg'); %read image
img2 = rgb2gray(img);   %convert to grayscale
smoothed_img = imgaussfilt(img2, 0.5); %smooth image by sigma 0.5
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'brain.tech-smoothed.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, 5);%smooth image by sigma 5
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'brain.tech-smoothed2.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, 10);%smooth image by sigma 10
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'brain.tech-smoothed3.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, [1,7.5]);%smooth image by sigma x=1, y=7.5
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'brain.tech-smoothed4.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, [7.5,1]);%smooth image by sigma x=7.5, y=1
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'brain.tech-smoothed5.jpg', 'jpg');%write image

img = imread('heart.jpg'); %read image
img2 = rgb2gray(img);   %convert to grayscale
smoothed_img = imgaussfilt(img2, 0.5);%smooth image by sigma 0.5
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'heart-smoothed.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, 5);%smooth image by sigma 5
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'heart-smoothed2.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, 10);%smooth image by sigma 10
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'heart-smoothed3.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, [1,7.5]);%smooth image by sigma x = 1, y = 7.5
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'heart-smoothed4.jpg', 'jpg');%write image
smoothed_img = imgaussfilt(img2, [7.5,1]);%smooth image by sigma x = 7.5, y = 1
figure,
imshow(smoothed_img); %show image
imwrite(smoothed_img,'heart-smoothed5.jpg', 'jpg'); %write image

%The filter sharpens an image by adding the image
%F to the data which is removed when smoothing an
%image. If the smoothed image data is removed from 
%the original image, then that data can be re-added
%to the original image to sharpen along the edges.

%Each of the images is smoothed with 5 different
%sigma values, the greater the sigma, the more
%smoothing occurs. The first sigma value is 0.5,
%which sharpens the image because its value is less
%than 1. The next value is 5, which is noticibly
%blurry, and the following value is 10, which is
%even blurrier. These two blurred images are
%uniformly blurred across both the x and y axes. The
%next filter is a sigma of 1 in the x direction and a
%sigma of 7.5 in the y direction. The resulting image
%is blurred but only the features in the x direction are
%suppressed. The opposite is true for the fifth filter, as
%it is a sigma of 7.5 in the x direction and 1 in the y
%direction. The resulting image is blurred, but only the
%features in the y direction are suppressed.