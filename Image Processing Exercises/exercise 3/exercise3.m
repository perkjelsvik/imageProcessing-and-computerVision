%% Per Arne Kjelsvik s2049201 - Exercise 3
% 53a28242-d88e-4ed6-8356-35942e79a8b1
% This exercise uses several given functions and a given picture. Figures
% from this script are saved to a subfolder 'figures'. The given functions
% used in this script are: 
%
% get_diameters  - Returns diameter of a horizontally aligned bloodvessel
% im_bloodvessel - Generates simulated X-ray image of a bloodvessel 
% ut_edge   - Marr-Hildreth and Canny edge detectors
% ut_gauss  - Apply 2D FIR filter with approx. gaussian PSF 
% ut_levelx - Used by ut_edge for finding level crossings

%% PART I
% Init and define variables
close all
clc
clear variables 

l = 4; % Constant for calculating L 

%% Question 1 - a)
sigma = 5;              % set the width of the Gaussian
L = 2*ceil(sigma*l)+1;  % fill in a constant to define the matrix size
xymax = (L-1)/2;        % the maximum of the x and the y coordinate
xrange = -xymax:xymax;  % the range of x values
yrange = xrange;        % the range of y values
h = fspecial('gaussian', L, sigma); % create the PSF matrix

% visualize as a 3D plot:
% create a RGB matrix to define the colour of the surface plot
C = cat(3, ones(size(h)),ones(size(h)),zeros(size(h)));
% create the surface plot of the gaussian
figure;
surf(xrange,yrange,h,C,'FaceColor','interp','Facelight','phong');
camlight right % add a light at the right side of the scene
xlim([-xymax xymax]); % set appropriate axis limits
ylim([-xymax xymax]);
xlabel('x'); % add axis labels
ylabel('y');
zlabel('h(x,y)');
print -r150 -dpng figures/ex3_1a.png % print the result to file

%% Question 1 - b) 
im = imread('ang2.png');    % read the image from file
sigma = [1 10 20 35];       % fill array with sigma values
figure;                     % figure to place the subplots

for i=1:4 % do 4 times:
    L = 2*ceil(sigma(i)*l)+1; % Calculate L for each sigma
    h = fspecial('gaussian', L, sigma(i)); % create the PSF
    imfiltered = imfilter(im,h,'replicate', 'same'); % apply the filter
    subplot(2,2,i); % define a subplot
    imshow(imfiltered,[]); % show the image
    title(['\sigma = ' num2str(sigma(i))]);% include a plot title
end

print -r150 -dpng figures/ex3_1b.png % print the result to file

%% Question 2 - ab)
sigma   = 1.5;                  % set the width of the Gaussian
L       = 2*ceil(sigma*l)+1;    % calculate appropiate L
N       = ceil((L-1)/2);        % get the size of half of the full range
[x,y]   = meshgrid(-N:N,-N:N);  % get coordinates of a 2D orthogonal grid
xymax   = (L-1)/2;              % the maximum of the x and the y coordinate
xrange  = -xymax:xymax;         % the range of x values
yrange  = xrange;               % the range of y values

% Give expressions for the Gaussian and it's y-derivative
h   = exp(-(x.^2 + y.^2)/(2*sigma^2))/(2*pi*sigma^2); 
hy  = -(exp(-(x.^2 + y.^2)/(2*sigma^2)).*y)/(2*pi*sigma^4);

% visualize as a 3D plot:
% create a RGB matrix to define the colour of the surface plot
C = cat(3, ones(size(hy)),ones(size(hy)),zeros(size(hy)));

% create the surface plot of the gaussian
figure;
surf(xrange,yrange,hy,C,'FaceColor','interp','Facelight','phong');
camlight right % add a light at the right side of the scene
xlim([-xymax xymax]); % set appropriate axis limits
ylim([-xymax xymax]);
xlabel('x'); % add axis labels
ylabel('y');
zlabel('h(x,y)');
print -r150 -dpng figures/ex3_2ab.png % print the result to file

figure; % Convolute the image with the gaussian
imfiltered = conv2(im,hy);
imshow(imfiltered,[]); % show the image
imwrite(mat2gray(imfiltered), 'figures/ex3_2_imfilteredGray.jpg');

%% Question 3
% Use ut_gauss to calculate the derivatives and apply to test image
sigma = 3;
fx = ut_gauss(im,sigma,1,0);   
fy = ut_gauss(im,sigma,0,1);    
fxx = ut_gauss(im,sigma,2,0);   
fyy = ut_gauss(im,sigma,0,2);
fxy = ut_gauss(im,sigma,1,1);

% Save the results to file
imwrite(mat2gray(fx), 'figures/ex3_3_fx.jpg');
imwrite(mat2gray(fy), 'figures/ex3_3_fy.jpg');
imwrite(mat2gray(fxx), 'figures/ex3_3_fxx.jpg');
imwrite(mat2gray(fyy), 'figures/ex3_3_fyy.jpg');
imwrite(mat2gray(fxy), 'figures/ex3_3_fxy.jpg');

%% Question 4
% Calculate gradient magnitude of test image with the found derivatives
grad_magnitude = sqrt(fx.^2+fy.^2);
imwrite(mat2gray(grad_magnitude), 'figures/ex3_4_gradient_magnitude.jpg');

% Calculate laplacian of test image with the found derivatives
laplacian = fxx+fyy;
imwrite(mat2gray(laplacian), 'figures/ex3_4_laplacian.jpg');

%% Question 5 - abc)
% Create binary image from thresholding laplacian
imBinary = laplacian >= 0; % positive laplacian values set as 1
imwrite(mat2gray(imBinary), 'figures/ex3_5abc_imBinary.jpg');

SE = strel('diamond',1); % structuring element with 4-neighborhood
imBinarySE = imerode(imBinary,SE);
imZeroCrossings = imBinary-imBinarySE;
imwrite(imZeroCrossings, 'figures/ex3_5abc_imZeroCrossings.jpg');

%% Question 5 - de)
% Create binary image from thresholding laplacian
imBinaryNeg = laplacian < 0;
imwrite(mat2gray(imBinaryNeg), 'figures/ex3_5de_imBinaryNeg.jpg');

SE = strel('diamond',1); % structuring element with 4-neighborhood
imBinaryNegSE = imerode(imBinaryNeg,SE);
imZeroCrossingsNeg = imBinaryNeg-imBinaryNegSE;
imwrite(imZeroCrossingsNeg, 'figures/ex3_5de_imZeroCrossingsNeg.jpg');

%% Question 5 - f)
% Combine the two found zero crossings
imZeroCombined = imZeroCrossings | imZeroCrossingsNeg;
imwrite(imZeroCombined, 'figures/ex3_5f_imZeroCombined.jpg');

skeleton = bwmorph(imZeroCombined, 'skel'); % Skeletonize image
imwrite(skeleton, 'figures/ex3_5f_skeletonized.jpg');

%% Question 6
grad_magnitude = sqrt(fx.^2+fy.^2); % gradient magnitude
mask = grad_magnitude.*imZeroCombined; % mask with Marr-Hildreth from Q5
figure; imshow(mask, []);

% Compared masked gradient magnitude to suitable treshold T 
mask = mat2gray(mask); % To have values from 0 to 1
%{
% I used the code below to find a suitable treshold. I then commented this
% code out and kept using the T I found from visual inspection the first
% time. The treshold I chose is 0.18

T = 0;
k = 1;
fprintf('Press a button to increase treshold with 0.01 more\n');
fprintf('Click mouse when satisfied with the treshold T\n');
while k>0
    T = T+0.01;
    figure(1);
    imshow(mask>T, []);
    title(['T = ', num2str(T), ...
        ' (keypress = increase; mouseclick = finish)']);
    k = waitforbuttonpress;
end
%}

T = 0.18; % Found from visual insepction
edgeMap = mask>T;
figure; imshow(edgeMap, []);
imwrite(edgeMap, 'figures/ex3_6_edgeMap.jpg');

marker = mask>0.28;
hysteresis = imreconstruct(marker, edgeMap);
figure; imshow(hysteresis,[]);
imwrite(hysteresis, 'figures/ex3_6_hysteresis.jpg');

%% Question 7
%{
% Below is the code I used to find appropiate values for the ut_edge
% function, both for canny and mildreth. This was a simple trial-and-error
% method where I visually inspected the results. There might be better
% solutions from combinations I did not try, but the results I ended up 
% with seems to be quite good compared to the other variations I tried. 

test = 0;
k = 1;
for k=0:0.01:10
    test = test+0.01;
    utCanny = ut_edge(im, 'm', 's', test, 'h', [0.04 0.03]);
    figure(4);
    imshow(utCanny, []);
    title(['test = ', num2str(test)]);
    pause(0.01)
    %k = waitforbuttonpress;
end

%}

% ut_edge canny detector (values found from trial-and-error)
utCanny = ut_edge(im, 'c', 's', 2.2, 'h', [0.05 0.01]);
imwrite(utCanny, 'figures/ex3_7_UTCanny.jpg');

% ut_edge Marr-Mildreth detector (values found from trial-and-error)
utMarrHildreth = ut_edge(im, 'm', 's', 2.75, 'h', [0.06 0.03]);
imwrite(utMarrHildreth, 'figures/ex3_7_UTMarrHildreth.jpg');

%% PART II
answer=input('Part I complete, do you want to run part II? [y/n]: ','s');
if answer=='n'
    return % Stop script here. Will keep part I variables in workspace
end
fprintf('Clearing all variables and closing all figures...\n');

% Init and and define variables
clear variables
close all
fprintf('Ready to run part II now!\n');

pix2mm = 0.04;   % Constant to convert pixels to mm

%% Question 8
D = 2; %[mm]
agniogram = im_bloodvessel(D);  % Generate simulated x-ray of bloodvessel
sigma = 1;
[~, ~]= get_diameters(agniogram, sigma, 'c'); % will return diam=[], suc=0

%% Question 9
D = 2; %[mm]
agniogram = im_bloodvessel(D);  % Generate simulated x-ray of bloodvessel
sigma = 5;
[diam, ~]= get_diameters(agniogram, sigma, 'c'); % suc=1

% Plot the found diameters against the columns in the image
figure; 
plot(diam.*pix2mm,'lineWidth', 2); grid on; hold on;
plot(ones(1,size(diam,1)).*(mean(diam)*pix2mm),'r--', 'LineWidth', 2); 
title('Estimation of diameters (\sigma =5)', 'FontSize', 16); hold off;
legend({'Diameter', 'Mean'},'FontSize',18,'Location','best');
xlabel('Column in image', 'FontSize', 14); 
ylabel('Diameter [mm]', 'FontSize', 14);
print -r150 -dpng figures/ex3_9_agniogram.png % print the plot to file


%% Question 10
stdDiam = std(diam).*pix2mm;
meanDiam = mean(diam)*pix2mm;

figure;
imshow(agniogram,[]);

%% Question 11
N = 10;
D = 1.55;
sigma = 4;
suc = zeros(1,N);
for i=1:N
    [~,suc(i)]=get_diameters(im_bloodvessel(D),sigma,'c');
end
sucRate = sum(suc)/N;

%% Question 12
N = 10;
D = 1.55;
sigma = 4;
suc = zeros(1,N);
diameters = [];
for i=1:N
    [diam,suc(i)]=get_diameters(im_bloodvessel(D),sigma,'c');
    if suc(i)==1
       diameters = cat(1,diameters,diam);
    end
end
stdDiameters = std(diameters);
meanDiameters = mean(diameters);
sucRate = sum(suc)/N;

%% Question 13 - Calculation
Sigma = 40;
N= 5; % Number of times every sigma is tried
D = 1.5;
stdDiamCanny    = zeros(2,Sigma);
sucCanny        = zeros(2,Sigma);
sucRateCanny    = zeros(2,Sigma);
biasDiamCanny   = zeros(2,Sigma);
stdDiamMildreth = zeros(2,Sigma);
sucMildreth     = zeros(2,Sigma);
sucRateMildreth = zeros(2,Sigma);
biasDiamMildreth= zeros(2,Sigma);

for i=1:2 % Run once for diameter D = 1.5 mm, and once for D = 3 mm
    for sigma=1:Sigma
        diamCanny = [];
        diamMildreth =[];
        sucCanny = zeros(1,N);
        sucMildreth = zeros(1,N);

        for n=1:N
            % Run with Canny operator
            [diam,sucCanny(n)]=get_diameters(...
                im_bloodvessel(D),sigma,'c');
            if sucCanny(n)==1
                diamCanny = cat(1,diamCanny,diam);
            end
            
            % Run with Mildreth operator
            [diam,sucMildreth(n)]=get_diameters(...
                im_bloodvessel(D),sigma,'m');
            if sucMildreth(n)==1
                diamMildreth = cat(1,diamMildreth,diam);
            end
        end
        
        % Find the standard deviation, bias and success rate of Canny
        stdDiamCanny(sigma,i) = std(diamCanny)*pix2mm;
        biasDiamCanny(sigma,i) = D - mean(diamCanny)*pix2mm;
        sucRateCanny(sigma,i) = sum(sucCanny)/N;
        
        % Find the standard deviation, bias and success rate of Mildreth
        stdDiamMildreth(sigma,i) = std(diamMildreth)*pix2mm;
        biasDiamMildreth(sigma,i) = D - mean(diamMildreth)*pix2mm;
        sucRateMildreth(sigma,i) = sum(sucMildreth)/N;
    end
    D = 3;
end

%% Question 13 - Plotting
sigma = 1:40; % Redefine sigma to be of sequence 1,2,...,40
figure;
plot(sigma, sucRateCanny(:,1), sigma, sucRateMildreth(:,1), ...
    sigma, sucRateCanny(:,2), sigma, sucRateMildreth(:,2), ...
    'LineWidth',3); 
title('Success rate Canny and Mildreth'); grid on;
xlabel('\sigma','FontSize',22);
ylabel('Success Rate');
legend({'Canny (1.5 mm)', 'Mildreth (1.5 mm)', ...
    'Canny (3 mm)', 'Mildreth (3 mm)'}, ...
    'FontSize',14,'Location','east');
print -r150 -dpng figures/ex3_13_sucRate.png % print the plot to file

figure;
plot(sigma, stdDiamCanny(:,1), sigma, stdDiamMildreth(:,1), ...
    sigma, stdDiamCanny(:,2), sigma, stdDiamMildreth(:,2), ...
    'LineWidth',3); 
title('Standard deviation Canny and Mildreth'); grid on;
xlabel('\sigma','FontSize',22);
ylabel('Standard deviation [mm]');
legend({'Canny (1.5 mm)', 'Mildreth (1.5 mm)', ...
    'Canny (3 mm)', 'Mildreth (3 mm)'}, ...
    'FontSize',14,'Location','north');
print -r150 -dpng figures/ex3_13_std.png % print the plot to file

figure;
plot(sigma, biasDiamCanny(:,1), sigma, biasDiamMildreth(:,1), '--', ...
    sigma, biasDiamCanny(:,2), sigma, biasDiamMildreth(:,2), '--', ...
    'LineWidth',3); 
xlabel('\sigma','FontSize',22); grid on;
title('Bias Canny and Mildreth');
ylabel('Bias [mm]');
legend({'Canny (1.5 mm)', 'Mildreth (1.5 mm)', ...
    'Canny (3 mm)', 'Mildreth (3 mm)'}, ...
    'FontSize',14,'Location','southwest');
print -r150 -dpng figures/ex3_13_bias.png % print the plot to file
