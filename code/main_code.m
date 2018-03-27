% 3D Face Reconstruction
% Course: Image Processing & Computer Vision

% Authors: Per Arne s....... & Tiago Machado s2041596

%%
clear variables
close all
clc

stereoCameraCalibrator('calibrationSession1_LM')
stereoCameraCalibrator('calibrationSession1_LR')
stereoCameraCalibrator('calibrationSession1_MR')
stereoCameraCalibrator('calibrationSession2_LM')
stereoCameraCalibrator('calibrationSession2_LR')
stereoCameraCalibrator('calibrationSession2_MR')

images = imageSet('test');
imLeft = read(images,1);
imMiddle = read(images,2);
imRight = read(images,3);

[J1,J2] = rectifyStereoImages(imLeft,imMiddle,stereoParams1_LM,'OutputView','full');
disparityMap = disparity(rgb2gray(J1),rgb2gray(J2),'BlockSize',15,'DisparityRange',[-6 10]);
imshow(disparityMap,[-6 10])
figure,
imshow(stereoAnaglyph(J1,J2))

