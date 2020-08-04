%Daniel Peterson - 109091561

img = imread('heart.jpg'); %read in image
img2 = rgb2gray(img);       %convert to grayscale
filtered_image = edge(img2, 'log', [], 1); %detect edges with sigma 1
figure,
imshow(filtered_image); %show image
imwrite(filtered_image, 'heart-log.jpg', 'jpg'); %write image
filtered_image2 = edge(img2, 'log', [], 3);%detect edges with sigma 3
figure,
imshow(filtered_image2);%show image
imwrite(filtered_image2, 'heart-log2.jpg', 'jpg');%write image
filtered_image3 = edge(img2, 'log', [], 10);%detect edges with sigma 10
figure,
imshow(filtered_image3);%show image
imwrite(filtered_image3, 'heart-log3.jpg', 'jpg');%write image

img = imread('brain.tech.jpg');%read in image
img2 = rgb2gray(img);            %convert to grayscale
filtered_image = edge(img2, 'log', [], 1); %detect edges with sigma 1
figure,
imshow(filtered_image);%show image
imwrite(filtered_image, 'brain.tech-log.jpg', 'jpg');%write image
filtered_image2 = edge(img2, 'log', [], 5); %detect edges with sigma 5
figure,
imshow(filtered_image2);%show image
imwrite(filtered_image2, 'brain.tech-log2.jpg', 'jpg');%write image
filtered_image3 = edge(img2, 'log', [], 10); %detect edges with sigma 10
figure,
imshow(filtered_image3);%show image
imwrite(filtered_image3, 'brain.tech-log3.jpg', 'jpg');%write image

%These are three different images for each the heart
%and the brain with the same LoG filter using different
%values for sigma. The first image for each uses a very
%low sigma value which results in excess edges because
%sigma determines the degree of smoothing which will take
%place in the image. The more smoothing, the more similar
%each pixel will look to the ones next to it. A low sigma
%will likely keep all pixels different from the ones nearby
%which will result in edges being detected when there is a
%large enough contrast. If there is too much smoothing, then
%the pixels will be too similar and there will never be any 
%edges detected. This can be seen in the last image for each
%as there are very few edges detected. The middle images
%for each represent some of the best sigma values for the
%respective images as the images are smoothed enough to get
%minor differences away, but not too much that the contrast
%completely disappears. These images have the best edge detection
%due to this. We can conclude that choosing a good sigma value is
%quite important to edge detection.