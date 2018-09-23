%% Per Arne Kjelsvik s2049201 - Exercise 2
% f3b96841-3676-45b9-8958-2bc1fab85b9a
close all
clc
clear variables 

% Some helpful functions given in exercise text
%{
imageSet - Define collection of images (use imageDatastore instead?)
affine2d - An affine2d object encapsulates a 2-D affine geometric transf.
cpselect - Control point selectrion tool (graphical interface)
projective2d - A projective2d object encapsulates a 2-D projective geotran.
estimateGeometricTransform - Estimate from matching point pairs
vision.AlphaBlender - Combine and/or overlay images, highlight pixels
imwarp- Apply geoemtric transformation to image
imref2d - Reference 2-D image to world coordinates 
%}

%% Question 1
images = imageSet('imfolder');
im1 = read(images,1);

%% Question 2
%{
Tinv = [a d g; b e h; c f i]; 
[up vp wp] = [x y w] * Tinv; 
                                 
u = (a*x+b*y+c)/(g*x+h*y+i);                             
v = (d*x + e*y + f)/(g*x + h*y + i)             
u = up/wp;                                                          
v = vp/wp;
%}

%% Question 3
%{
for n=1:4
    for m=n+1:4
        [p{n,m},p{m,n}] = cpselect(read(images,n),...
            read(images,m),'Wait',true);
    end
end
%}
load psets

%% Question 4
tform2 = estimateGeometricTransform(p{2,1},p{1,2}, 'projective');
im2 = read(images, 2);
im2w = imwarp(im2,tform2);
figure;
imshow(im2w);
%imwrite(im2w,'im2w.jpg');

%% Question 5
tform1 = projective2d(eye(3));          %Identity
im1 = imwarp(im1,tform1);
ImageSize = size(im1);

[xlims(1,:),ylims(1,:)] = outputLimits(tform1,...
    [1 ImageSize(2)],[1 ImageSize(1)]);
[xlims(2,:),ylims(2,:)] = outputLimits(tform2,...
    [1 ImageSize(2)],[1 ImageSize(1)]);

% Find the minimum and maximum output limits 
xMin = min([1; xlims(:)]);
xMax = max([ImageSize(2); xlims(:)]);

yMin = min([1; ylims(:)]);
yMax = max([ImageSize(1); ylims(:)]);

% Width and height of stitched image.
width = round(xMax - xMin);
height = round(yMax - yMin);

% Initialize the "empty" stitch.
imstitch = zeros([height width 3], 'like', im1);

% Use |imwarp| to map images into the panorama and use
% |vision.AlphaBlender| to overlay the images together.

blender = vision.AlphaBlender('Operation', 'Binary Mask', ...
    'MaskSource', 'Input port');  

% Create a 2-D spatial reference object defining the size of the stitch.
XWorldLimits = [xMin xMax];
YWorldLimits = [yMin yMax];
imref = imref2d([height width], XWorldLimits, YWorldLimits);

% Create the stitched image.
im1W = imwarp(im1, tform1, 'OutputView', imref);
mask1 = imwarp(true(size(im1,1),size(im1,2)), tform1, 'OutputView', imref);
imstitch = step(blender, imstitch, im1W, mask1);
im2W = imwarp(im2, tform2, 'OutputView', imref);
mask2 = imwarp(true(size(im2,1),size(im2,2)), tform2, 'OutputView', imref);
imstitch = step(blender, imstitch, im2W, mask2);

figure;
imshow(imstitch);
%imwrite(imstitch, 'imstitch.jpg');

%% Question 6
% Initialize all the transforms to the identity matrix.
numImages = numel(images.Files);
tform(numImages) = projective2d(eye(3));

% Find the chain of transforms: 1 --> 2 --> 3 --> 4
tform(2) = estimateGeometricTransform(p{2,1},p{1,2}, 'projective');
tform(3) = estimateGeometricTransform(p{3,2},p{2,3}, 'projective');
tform(4) = estimateGeometricTransform(p{4,3},p{3,4}, 'projective');


% Find the transforms and points to image 1
P = cell(4);
P(1,:) = p(1,:);

tform1(2) = tform(2);
for n=3:numImages
    [P{n-1,n}(:,1), P{n-1,n}(:,2)] = transformPointsForward(...
        tform1(n-1),p{n-1,n}(:,1),p{n-1,n}(:,2));
    tform1(n) = estimateGeometricTransform(p{n,n-1},P{n-1,n},'projective');
    [P{n,n-1}(:,1), P{n,n-1}(:,2)] = transformPointsForward(...
        tform1(n),p{n,n-1}(:,1),p{n,n-1}(:,2));
end


%% Question 7
[xlims(3,:),ylims(3,:)] = outputLimits(...
    tform1(3),[1 ImageSize(2)],[1 ImageSize(1)]);
[xlims(4,:),ylims(4,:)] = outputLimits(...
    tform1(4),[1 ImageSize(2)],[1 ImageSize(1)]);

% Find the minimum and maximum output limits 
xMin = min([1; xlims(:)]);
xMax = max([ImageSize(2); xlims(:)]);

yMin = min([1; ylims(:)]);
yMax = max([ImageSize(1); ylims(:)]);

% Width and height of stitched image.
width = round(xMax - xMin);
height = round(yMax - yMin);

% Initialize the "empty" stitch.
imstitch = zeros([height width 3], 'like', im1);

% Use |imwarp| to map images into the panorama and use
% |vision.AlphaBlender| to overlay the images together.

blender = vision.AlphaBlender('Operation', 'Binary Mask', ...
    'MaskSource', 'Input port');  

% Create a 2-D spatial reference object defining the size of the stitch.
XWorldLimits = [xMin xMax];
YWorldLimits = [yMin yMax];
imref = imref2d([height width], XWorldLimits, YWorldLimits);

% Create the stitched image.
for n = 1:numImages
    
    I = read(images, n);   
   
    % Transform I into the panorama.
    warpedImage = imwarp(I, tform1(n), 'OutputView', imref);
                  
    % Generate a binary mask.    
    mask = imwarp(true(size(I,1),size(I,2)), tform1(n), ...
        'OutputView', imref);
    
    % Overlay the warpedImage onto the panorama.
    imstitch = step(blender, imstitch, warpedImage, mask);
end

figure;
imshow(imstitch);
%imwrite(imstitch, 'imstitch4.jpg');

%% Question 8
% Finding all the neccesary transforms (note that some are repeated from
% question 6. This is simply because this provides neater code)
index = [1 3 4; 1 2 4; 1 2 3];
for n=2:numImages
    for m=2:numImages
        P{n,index(n-1,m-1)} = transformPointsForward(...
            tform1(n),p{n,index(n-1,m-1)});
    end
end

% Calculating the differences between the points and image-pairs RMS

e = zeros(1,4);
E = zeros(4);
for n=1:4
    for m=n+1:4
        for K=1:4
            e(K) = norm(P{m,n}(K,:) - P{n,m}(K,:));   
        end
    end
    E(n,m) = sqrt((1/K)*sum(e.^2));
end

% Overall RMS
RMS = sqrt((1/6)*(sum(sum(E.^2))));

%% Question 9
% Select landmarks to help the transformation! 
%{
 I selected points inside the map, but close to the edge of the map. 
 I chose: (53°5', 5°5'), (53°5', 5°20'), (53°20', 5°5'), (53°20', 5°20')
 getpts is a bit hard to use due to not being able to zoom, so I manually
 inspected the points afterwards and adjusted two of the points as needed.

 Result:
 
        (53°5', 5°5')   | X: 392.7    Y: 2006.2     | xy(1,:)
        (53°5', 5°20')  | X: 1180     Y: 2035       | xy(2,:)   
        (53°20', 5°5')  | X: 306.9    Y: 682.5      | xy(3,:)   
        (53°20', 5°20') | X: 1199     Y: 695        | xy(4,:)
%}

% Select points and save them
%{ 
figure; imshow(imstitch);
[landX, landY] = getpts;
xy=[landX,landY];
hold on; plot(xy(:,1), xy(:,2),'rx','MarkerSize',20)
xy(2,:) = [1180 2035];
xy(4,:) = [1199 695];
save xy xy  
%}

% We need to calculate what the points our 4 points *should* be. That means
% that we can for example take our xy(1,1) and calculate the distance we
% need to go in x- and y-direction for the map to be geometrically correct.
% We do this by seeing how many squares apart our points are, and take the
% cosd of the latitude

scale=15;           % Grid squares between the points
lat = 53;           % ~Latitude of the points
minutes = [5 20];   % Minutes of the points
pixelSize=100;      % The pixel size we want of the Nm
load xy;    

xAdj = [...
    xy(1,1); xy(1,1)+pixelSize*cosd(lat+(minutes(1)/60))*scale; 
    xy(1,1); xy(1,1)+pixelSize*cosd(lat+(minutes(2)/60))*scale];
yAdj = [...
    xy(1,1); xy(1,1); 
    xy(1,1)-pixelSize*scale; xy(1,1)-100*scale];
xyAdj = [xAdj, yAdj];

% Perform the geomtrical transform and crop the image
mapTform = estimateGeometricTransform(xy, xyAdj, 'projective');
% imMap = imcrop(imwarp(imstitch, mapTform));
imMap = imread('imMap.jpg');
figure; imshow(imMap);
%imwrite(imMap, 'imMap.jpg');

%% Question 12
%{
A tform class stores its parameters in a 3x3 matrix tform.T
If tform is of type affine2d: alpha = tform.T(1:6)
If tform is of type projective2d: alpha = tform.T(1:6)
%}
alpha1 = tform1(2).T(1:8)';
alpha2 = tform1(3).T(1:8)';
alpha3 = tform1(4).T(1:8)';
beta = [alpha1 alpha2 alpha3]';

[RMS2, E2] = bundle_adjustment(beta,p);

%% Question 13
options = optimset('MaxFunEvals',1000000,'MaxIter',1000000);
f = @(x)bundle_adjustment(x,p);
beta_opt = fminsearch(f,beta);

[RMS_opt,E_opt, P2] = bundle_adjustment(beta_opt,p);

%% Question 14
% I was not able to finish this code in time, but I started with this. 
tform1(1).T(1:8) = beta_opt(1,:);
tform1(2).T(1:8) = beta_opt(2,:);
tform1(3).T(1:8) = beta_opt(3,:);