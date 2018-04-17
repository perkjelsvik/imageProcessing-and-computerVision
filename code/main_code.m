% 3D Face Reconstruction
% Course: Image Processing & Computer Vision
% University of Twente
% April, 2018

% Authors: Per Arne s2049201 & Tiago Machado s2041596


clear variables % Clear variables in workspace
close all       % Close all images/graphs/plots
clc             % Clear Command Window

% Initialize paths to data, functions and images
addpath('data');
addpath('test');
addpath(genpath('functions'));

%% Reading images

images = imageSet('test');
im_left = im2double(read(images,1));
im_middle = im2double(read(images,2));
im_right = im2double(read(images,3));

%% Camera Calibration

% The code for stereo calibrating the camera
%{
stereoCameraCalibrator('data/calibration/calibrationSession1_LM.mat') % then load stereoParams
stereoCameraCalibrator('data/calibration/calibrationSession1_MR.mat') % then load stereoParams
%}

% Load stereo camera calibrated parameters
load('data/stereoParams_subject1_calib1.mat');

showExtrinsics(stereoParams_LM); % show extrinsic parameters
showExtrinsics(stereoParams_MR); % show extrinsic parameters

%% Stereo rectification
load('data/masks.mat'); % load mask_left, mask_middle and mask_right

[imLeft_rect2, imMiddleLeft_rect2] = rectifyStereoImages(im_left, ...
    im_middle, stereoParams_LM,'OutputView','full');
    
[imMiddleRight_rect2, imRight_rect2] = rectifyStereoImages(im_middle, ...
    im_right, stereoParams_MR, 'OutputView','full');

mask_left = cat(3, mask_left, mask_left, mask_left);
im_left(imcomplement(mask_left)) = 0;

mask_middle = cat(3, mask_middle, mask_middle, mask_middle);
im_middle(imcomplement(mask_middle)) = 0;

mask_right = cat(3, mask_right, mask_right, mask_right);
im_right(imcomplement(mask_right)) = 0;

[imLeft_rect, imMiddleLeft_rect] = rectifyStereoImages(im_left, ...
    im_middle, stereoParams_LM,'OutputView','full');
    
[imMiddleRight_rect, imRight_rect] = rectifyStereoImages(im_middle, ...
    im_right, stereoParams_MR, 'OutputView','full');

%% 3D landmarks from 2D ploints LM
[movingreg_LM]= registerImages_LM(imLeft_rect, imMiddleLeft_rect);
%{
p_lm = round(movingreg_LM.FixedMatchedFeatures.Location');
k = stereoParams_LM.CameraParameters1.IntrinsicMatrix';
wR1 = stereoParams_LM.RotationOfCamera2';
wt1 = stereoParams_LM.TranslationOfCamera2';
sigma = stereoParams_LM.MeanReprojectionError;
[Xpost_LM, Cpost_LM] = ut_3Dlandmarks_from_2Dpoints(p_lm,sigma,k,wR1,wt1);
Xprior = Xpost_LM; 
Cprior = Cpost_LM;
[Xpost_LM, Cpost_LM] = ut_3Dlandmarks_from_2Dpoints(p_lm,sigma,k,wR1,wt1, Xprior, Cprior);

xmean = mean(Xpost_LM,2);
CMatrix = cov(Xpost_LM');
pcol = [0.8 0.3 0.2];
patchP = patch(Xpost_LM(1,:),Xpost_LM(2,:),pcol);
Nlong=41; 
Nlat = 41;
hg = [];
figure;
h = ut_plotcov3(hg, Nlong,Nlat,xmean,CMatrix,pcol,patchP); grid on;
%}

%% 3D landmarks from 2D ploints RM
[movingreg_MR]= registerImages_MR(imMiddleRight_rect,imRight_rect);
%{
p_mr = round(movingreg_MR.FixedMatchedFeatures.Location');
k = stereoParams_MR.CameraParameters1.IntrinsicMatrix';
wR1 = stereoParams_MR.RotationOfCamera2';
wt1 = stereoParams_MR.TranslationOfCamera2';
sigma = stereoParams_MR.MeanReprojectionError;
[Xpost_MR, Cpost_MR] = ut_3Dlandmarks_from_2Dpoints(p_mr,sigma,k,wR1,wt1);
Xprior = Xpost_MR; 
Cprior = Cpost_MR;
[Xpost_MR, Cpost_MR] = ut_3Dlandmarks_from_2Dpoints(p_mr,sigma,k,wR1,wt1, Xprior, Cprior);

xmean = mean(Xpost_MR,2);
CMatrix = cov(Xpost_MR');
pcol = [0.8 0.3 0.2];
patchP = patch(Xpost_MR(1,:),Xpost_MR(2,:),pcol);
Nlong=41; 
Nlat = 41;
hg = [];
figure;
h = ut_plotcov3(hg, Nlong,Nlat,xmean,CMatrix,pcol,patchP); grid on;
%}

%% Disparity map
disparityRange = [270 350];
%disparityRange = [292-6,344+6];
%map_MR = disparity(rgb2gray(imLeft_rect2),rgb2gray(imMiddleLeft_rect2), ...
%    'DisparityRange',[0,256],'ContrastThreshold',0.8);
h = fspecial('gaussian',50);
SE = strel('disk',10);

unreliable_LM = disparity(rgb2gray(imfilter(imclose(imLeft_rect2,SE),h)),...
    rgb2gray(imfilter(imdilate(imMiddleLeft_rect2,SE),h)) ,'DisparityRange',...
    disparityRange, 'ContrastThreshold',0.7,'UniquenessThreshold',6,...
    'DistanceThreshold',15,'BlockSize',9,'method', 'blockmatching');
unreliable_LM = imclose(unreliable_LM, SE);
unreliable_LM(imcomplement(rgb2gray(imLeft_rect) > 0)) = 0;
figure;
imshow(unreliable_LM,disparityRange);
colormap(gca,jet); colorbar;
%%
h = fspecial('gaussian',50);
SE = strel('disk',10);
map_LM = disparity(rgb2gray(imfilter(imclose(imLeft_rect2,SE),h)),...
    rgb2gray(imfilter(imdilate(imMiddleLeft_rect2,SE),h)),'DisparityRange',...
    disparityRange, 'ContrastThreshold',0.7,'UniquenessThreshold',6,...
    'DistanceThreshold',15,'BlockSize',9);
map_LM(imcomplement(rgb2gray(imLeft_rect) > 0)) = 0;
%map_LM = imclose(map_LM, SE);
%map_LM = imfill(map_LM, 'holes');
%map_LM = imgaussfilt(map_LM,1);
figure;
imshow(map_LM,disparityRange);
colormap(gca,jet);
colorbar;
%%
disparityRange = [270 350];
%map_MR = disparity(rgb2gray(imLeft_rect2),rgb2gray(imMiddleLeft_rect2), ...
%    'DisparityRange',[0,256],'ContrastThreshold',0.8);
map_MR = disparity(rgb2gray(imMiddleRight_rect2),rgb2gray(imRight_rect2) ...
    ,'DisparityRange',disparityRange, 'ContrastThreshold',0.7, ...
    'UniquenessThreshold',6, 'DistanceThreshold',13,'BlockSize',9);
map_MR(imcomplement(rgb2gray(imMiddleRight_rect) > 0)) = 0;
figure;
imshow(map_MR,disparityRange);
colormap(gca,jet);
colorbar;

%% 3D point cloud
xyzPoints_LM = reconstructScene(map_LM,stereoParams_LM);
xyzPoints_MR = reconstructScene(map_MR,stereoParams_MR);

%TR_LM = create_3D_mesh(map_LM, xyzPoints_LM, unreliable_LM, imMiddleLeft_rect);
%TR_LM = create_3D_mesh(map_MR, xyzPoints_MR, unreliable_MR);
