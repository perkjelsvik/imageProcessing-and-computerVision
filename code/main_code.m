% 3D Face Reconstruction
% Course: Image Processing & Computer Vision
% University of Twente
% April, 2018

% Authors: Per Arne s2049201 & Tiago Machado s2041596


clear variables % Clear variables in workspace
close all       % Close all images/graphs/plots
clc             % Clear Command Window

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

mask_left = cat(3, mask_left, mask_left, mask_left);
im_left(imcomplement(mask_left)) = 0;

mask_middle = cat(3, mask_middle, mask_middle, mask_middle);
im_middle(imcomplement(mask_middle)) = 0;

mask_right = cat(3, mask_right, mask_right, mask_right);
im_right(imcomplement(mask_right)) = 0;

[imMiddleLeft_rect, imLeft_rect] = rectifyStereoImages(im_middle, im_left, stereoParams_LM,...
    'OutputView','full');
    
[imRight_rect,imMiddleRight_rect] = rectifyStereoImages(im_right,im_middle,stereoParams_MR,...
    'OutputView','full');

%% 3D landmarks from 2D ploints
[movingreg, p]= registerImages(imRight_rect, imMiddleRight_rect);
p = p';
k = stereoParams_MR.CameraParameters1.IntrinsicMatrix';
wR1 = stereoParams_MR.RotationOfCamera2';
wt1 = stereoParams_MR.TranslationOfCamera2';
sigma = stereoParams_MR.MeanReprojectionError;
[Xpost, Cpost] = ut_3Dlandmarks_from_2Dpoints(p,sigma,k,wRc,wtc);
Xprior = Xpost; 
Cprior = Cpost;
[Xpost, Cpost] = ut_3Dlandmarks_from_2Dpoints(p,sigma,k,wRc,wtc, Xprior, Cprior);

xmean = mean(Xpost,2);
CMatrix = cov(Xpost');
pcol = [0.8 0.3 0.2];
patchP = patch(Xpost(1,:),Xpost(2,:),pcol);
Nlong=41; 
Nlat = 41;
hg = [];
figure;
h = ut_plotcov3(hg, Nlong,Nlat,xmean,Cmatrix,pcol,patchP); grid on;

%% Facial (easily recognizable) Features 
xyDIF = abs(featuresMiddle-featuresRight);
disparity_Fpoints = sqrt(xyDIF(:,1).^2 + xyDIF(:,2).^2);

xyDIF = abs(featuresMiddle-featuresLeft);
disparity_Fpoints_2 = sqrt(xyDIF(:,1).^2 + xyDIF(:,2).^2);

max_disp_Fpoints = round(max(disparity_Fpoints));
min_disp_Fpoints = round(min(disparity_Fpoints));

max_disp_Fpoints_2 = round(max(disparity_Fpoints_2));
min_disp_Fpoints_2 = round(min(disparity_Fpoints_2));

% Disparity Map for facial feature points

disparity_fpoints = zeros(m,n);
disparity_fpoints2 = zeros(m2,n2);

for i = 1:53
    disparity_fpoints(uint8(featuresMiddle(i,2)),uint8(featuresMiddle(i,1))) = ...
        disparity_Fpoints(i);
    disparity_fpoints2(uint8(featuresMiddle(i,2)),uint8(featuresMiddle(i,1))) = ...
        disparity_Fpoints2(i);
end

%Determine disparity ranges according to featrue points disparities
range = [min_disp_Fpoints,max_disp_Fpoints];
range2 = [min_disp_Fpoints_2,max_disp_Fpoints_2];
