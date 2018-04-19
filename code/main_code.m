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

% LM represent Left -> Middle
% MR represent Middle -> Right

%% Reading images
images = imageSet('test'); % Create a indexed imageSet of the subject
subNum = 0; %0, 1, 2 represents subject 1, 2, 3
im_left = im2double(read(images,1+3*subNum));
im_middle = im2double(read(images,2+3*subNum));
im_right = im2double(read(images,3+3*subNum));

%% Camera Calibration

% Use the Stereo Camera Calibrator from the Computer Vision Toolbox 
% to find Extrinsic and Intrisic parameters for the cameras
%{
stereoCameraCalibrator('data/calibration/calibrationSession1_LM.mat') 
stereoCameraCalibrator('data/calibration/calibrationSession1_MR.mat') 
%}

% Load stereo camera calibrated parameters
load('data/stereoParams_subject1_calib1.mat');
%load('data/stereoParams_subject1_calib2.mat');

figure; showExtrinsics(stereoParams_LM); % show extrinsic parameters of LM
figure; showExtrinsics(stereoParams_MR); % show extrinsic parameters of MR

%% Stereo rectification
% Rectify the images of the subject Left -> Middle -> Right
[imLeft_rect_full, imMiddleLeft_rect_full] = rectifyStereoImages(...
    im_left, im_middle, stereoParams_LM,'OutputView','full');
    
[imMiddleRight_rect_full, imRight_rect_full] = rectifyStereoImages(...
    im_middle, im_right, stereoParams_MR, 'OutputView','full');

% Use K-means clustering to extract a mask of the face of the subject
% This is based mostly on the Matlab Example:
%       'Color-Based Segmentation Using K-Means Clustering'
% The masks found with the method has been saved to .mat-files that we load
%{
[mask_left] = k_means_segment(im_left);
[mask_middle] = k_means_segment(im_middle);
mask_middle2 = mask_middle;
[mask_right] = k_means_segment(im_right);
%}

% Load masks of the subject found through k-means clustering
load('data/masks_subject1_calib1.mat'); % load left, middle, and right mask
%load('data/masks_subject1_calib2.mat'); % load left, middle, and right mask
%load('data/masks_subject2_calib1.mat'); % load left, middle, and right mask
%load('data/masks_subject3_calib1.mat'); % load left, middle, and right mask

mask_left = cat(3, mask_left, mask_left, mask_left);
im_left_masked = im_left;
im_left_masked(imcomplement(mask_left)) = 0;

mask_middle = cat(3, mask_middle, mask_middle, mask_middle);
im_middle_masked = im_middle;
im_middle_masked(imcomplement(mask_middle)) = 0;

mask_right = cat(3, mask_right, mask_right, mask_right);
im_right_masked = im_right;
im_right_masked(imcomplement(mask_right)) = 0;

% Stereo rectify the masked images as well for disparity maps later
[imLeft_rect, imMiddleLeft_rect] = rectifyStereoImages(im_left_masked, ...
    im_middle_masked, stereoParams_LM,'OutputView','full');
        
[imMiddleRight_rect, imRight_rect] = rectifyStereoImages(im_middle_masked, ...
    im_right_masked, stereoParams_MR, 'OutputView','full');

%% Stereo matching between two images using Registration Estimator App
% Used the Registration Estimator app to verify that matched points are on
% epipolar lines. Exported the results as a function (for subject 1). Not
% used further. 
[movingReg_LM]= registerImages_LM(imLeft_rect, imMiddleLeft_rect);
[movingReg_MR]= registerImages_MR(imMiddleRight_rect,imRight_rect);

%% Disparity map
% Create disparity map for the two image pairs
[map_LM, unreliable_LM] =  disparityMapAndUnreliable(imLeft_rect_full, ...
    imMiddleLeft_rect_full, imLeft_rect, 11 +subNum*10);
[map_MR, unreliable_MR] =  disparityMapAndUnreliable(imMiddleRight_rect_full, ...
imRight_rect_full, imMiddleRight_rect, 12 +subNum*10);

%% 3D point clouds
% Create point clouds for LM and MR
xyzPoints_LM = reconstructScene(map_LM,stereoParams_LM);
xyzPoints_MR = reconstructScene(map_MR,stereoParams_MR);

% Complete PointCloud Registration Algorithm
%{
    Denoise(LM)     &   Denoise(MR)     - pcdenoise
    Downsample(LM)  &   Denoise(MR)     - pcdownsample
    Rigid Transformation LM & MR        - pcregrigid
        Match Points between LM & MR
        Remove incorrect matches (Outlier filter)
        Recover rotation and translation (minimize error)
        Check if algorithm stops
    Align LM and MR                     - pctransform
    Merge LM and MR                     - pcmerge
%}

pc_LM = pointCloud(xyzPoints_LM);
pc_LM = pcdenoise(pc_LM);
pc_LM = pcdownsample(pc_LM, 'nonuniformGridSample', 15);
pc_MR = pointCloud(xyzPoints_MR);
pc_MR = pcdenoise(pc_MR);
pc_MR = pcdownsample(pc_MR, 'nonuniformGridSample', 15);
[tform,pc_MR,rmse]= pcregrigid(pc_MR, pc_LM, 'Extrapolate',true);
pc = pcmerge(pc_LM, pc_MR, 1);
figure;
pcshow(pc);

%% Create 3D meshes from point clouds
% Function based on UT syllabi
TR_LM = create_3D_mesh(map_LM, xyzPoints_LM, ...
    unreliable_LM, imLeft_rect);
TR_MR = create_3D_mesh(map_MR, xyzPoints_MR, ...
    unreliable_MR, imMiddleRight_rect);