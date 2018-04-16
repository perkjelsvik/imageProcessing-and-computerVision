% 3D Face Reconstruction
% Course: Image Processing & Computer Vision
% University of Twente
% April, 2018

% Authors: Per Arne s....... & Tiago Machado s2041596


clear variables % Clear variables in workspace
close all       % Close all images/graphs/plots
clc             % Clear Command Window

%% Reading images

images = imageSet('test');
imLeft = im2double(read(images,1));
imMiddle = im2double(read(images,2));
imRight = im2double(read(images,3));

%% Camera Calibration

stereoCameraCalibrator('calibrationSession1_LM.mat') % then load stereoParams
stereoCameraCalibrator('calibrationSession1_MR.mat') % then load stereoParams

showExtrinsics(stereoParams_LM); % show extrinsic parameters
showExtrinsics(stereoParams_MR); % show extrinsic parameters

%% Face Detection

%To detect Face
FDetect = vision.CascadeObjectDetector;

%Returns Bounding Box values based on number of objects
BB = step(FDetect,imRight);

figure,
imshow(imRight); hold on
for i = 1:size(BB,1)
    rectangle('Position',BB(i,:),'LineWidth',5,'LineStyle','-','EdgeColor','r');
end
title('Face Detection');
hold off;

%% Segmentating the face

maskRight = faceSegmentation(imRight,'right');
% maskMiddle = faceSegmentation(imMiddle,'middle');
% maskLeft = faceSegmentation(imLeft,'left');

%% Stereo Rectification

% Middle + Right Images/Masks rectification
[imRight_rec,imMiddle_rec] = rectifyStereoImages(imRight,imMiddle,...
stereoParams1_MR,'OutputView','full');
figure, imshowpair(imRight_rec,imMiddle_rec,'montage');

[maskRight_rec,maskMiddle_rec] = rectifyStereoImages(maskRight,maskMiddle, ...
stereoParams1_MR,'OutputView','full');
figure, imshowpair(maskRight_rec,maskMiddle_rec,'montage');

[m,n,k] = size(imRight_rec); % size of the rectified images


% Left + Middle Images/Masks rectification
[imLeft_rec,imMiddle_rec2] = rectifyStereoImages(imLeft,imMiddle, ...
stereoParams1_LM,'OutputView','full');
figure, imshowpair(imLeft_rec,imMiddle_rec2,'montage');

[maskLeft_rec,maskMiddle_rec2] = rectifyStereoImages(maskLeft,maskMiddle, ...
stereoParams1_LM,'OutputView','full');
figure, imshowpair(maskLeft_rec,maskMiddle_rec2,'montage');

[m2,n2,k2] = size(imMiddle_rec2); % size of the rectified images


%% Facial (easily recognizable) Features 

faceDetector = vision.CascadeObjectDetector; % Face detector

% Right image
bboxes = step(faceDetector, imRight);
% Select face
faceRight = imRight(bboxes(1,2)-170:bboxes(1,2)+90+bboxes(1,4),bboxes(1,1):bboxes(1,1)+40+bboxes(1,3));
ftrsRight = detectHarrisFeatures(faceRight); % Detect SURF features
% Saving the features and coordinates in matrixes
[featuresRight, pointsRight] = extractFeatures(faceRight, ftrsRight);
figure,imshow(faceRight), hold on, plot(ftrsRight) % Plot facial features

% Left image
bboxes = step(faceDetector, imLeft);
% Select face
faceLeft = imLeft(bboxes(1,2)-130:bboxes(1,2)+10+bboxes(1,4),bboxes(1,1)-40:bboxes(1,1)+bboxes(1,3));
ftrsLeft = detectHarrisFeatures(faceLeft); % Detect SURF features
% Saving the features and coordinates in matrixes
[featuresLeft, pointsLeft] = extractFeatures(faceLeft, ftrsLeft);
figure,imshow(faceLeft), hold on, plot(ftrsLeft) % Plot facial features

% Middle image
bboxes = step(faceDetector, imMiddle);
% Select face
faceMiddle = imMiddle(bboxes(1,2)-130:bboxes(1,2)+20+bboxes(1,4),bboxes(1,1):bboxes(1,1)+bboxes(1,3)+20);
ftrsMiddle = detectHarrisFeatures(faceMiddle); % Detect SURF features
% Saving the features and coordinates in matrixes
[featuresMiddle, pointsMiddle] = extractFeatures(faceMiddle, ftrsMiddle);
figure,imshow(faceMiddle), hold on, plot(ftrsMiddle) % Plot facial features


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
