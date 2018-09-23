%% demo line detection and morph - F. van der Heijden
clear variables
close all

%% include ut functions in the path
path('../ut_image_processing_functions',path)

%% read image
im = im2double(imread('boot.tif'));
imshow(im,[],'InitialMagnification',200);

%% enhance lines
sigma_hessian = 1;
[~, ~, imeigv] = ut_line(im,sigma_hessian);	% get eigenvalues Hessian matrix

imeigmax = imeigv(:,:,1);                   % get largest eigenval of the two
imeigmax(imeigmax<0) = 0;                   % only looking for dark lines
figure;
imshow(imeigmax,[],'InitialMagnification',200);

%% detect lines
imline = imeigmax>0.02;                     % detect line elements
figure;
imshow(imline,[],'InitialMagnification',200);

%% find line segments with minimum length 
len = 20;
imacc = zeros(size(im));
figure;
for deg=0:3:180                           % loop through all angles
    bline = strel('line',len,deg);      % create a structuring element
    subplot(1,2,1);
    imdir = imdilate(imerode(imline,bline),bline); % apply opening
    imshow(imdir);
    title([num2str(deg) ' degrees']);
    subplot(1,2,2)
    imacc = imacc + imdir;              % accumulate all found segments
    imshow(imacc,[]);
    title('accumulator')
    drawnow
end
figure;
imskel = bwmorph(imacc>0,'skel','Inf');% skeltonize the results
%% show image with a color overlay
ind = find(imskel>0);
imred = im;
imred(ind) = 1;                        % show line elements in red  
imgreen = im;
imgreen(ind) = 0;
imcol = cat(3,imred,imgreen,imgreen);
figure;
imshow(imcol,[],'InitialMagnification',200);

%% detect some bifurcations
bhit = [0 1 0; 0 1 1;1 1 0;0 1 0];    % create the hit mask
bmiss = [1 0 1; 0 0 0; 0 0 0;1 0 1];  % create the miss mask
figure;
imshow(bhit-bmiss,[],'InitialMagnification',3000); % show
imhitmiss = bwhitmiss(imskel,bhit,bmiss);         % apply
imhitmiss = imdilate(imhitmiss,ones(5));          % dilate the dots

%% show image with a color overlay
ind = find(imhitmiss);
imred(ind) = 0;
imgreen(ind) = 1;
imblue = imgreen;
imblue(ind) = 0;
imcol = cat(3,imred,imgreen,imblue);             % show the dots in green
figure;
imshow(imcol,[],'InitialMagnification',200);




