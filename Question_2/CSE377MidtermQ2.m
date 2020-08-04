%Daniel Peterson - 109091561

%Hough transforms use points in the parameter 
%space to represent lines from the image and 
%represents points in the image as sinusoids
%in the parameter space. The points where these
%sinusoids intersect represent co-linear points
%which are points on the same line. This is used
%to detect edges in an image, as lines consist of
%co-linear points. This transform is very efficient
%in detecting lines and circles, but is much less
%efficeient when detecting other things because of
%image size and number of parameters increases.
%Images with a lot of noise cause the hough transform
%much more issues than an image without noise.