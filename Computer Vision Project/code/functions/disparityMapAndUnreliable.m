function [disparityMap, unreliable] = disparityMapAndUnreliable(im_left, im_right, mask, subNumPair)
% This is a function to create disparity maps for the different subjects
% It is specalised for the different image pairs possible, but they all
% have similiar operations performed to them 
im_left = rgb2gray(im_left);
im_right = rgb2gray(im_right);
mask = rgb2gray(mask);

% Procedure: 
%{
    Define disparity range
    Make disparity map
    Mask out the background
    Median filter the disparity map to smoothen the results
%}

switch subNumPair
    case 11 % Subject 1, LM image pair
        disparityRange = [276,340];
        disparityMap = disparity(im_left,im_right,'DisparityRange',...
            disparityRange, 'ContrastThreshold',0.9, ...
            'UniquenessThreshold',5,'DistanceThreshold',15,'BlockSize',5);
        disparityMap(imcomplement(mask > 0)) = 0;
        disparityMap = medfilt2(disparityMap, [30 30],'symmetric');
    case 12 % Subject 1, MR image pair
        disparityRange = [276,340];
        disparityMap = disparity(im_left,im_right,'DisparityRange',...
            disparityRange, 'ContrastThreshold',0.9, ...
            'UniquenessThreshold',5,'DistanceThreshold',15,'BlockSize',5);
        disparityMap(imcomplement(mask > 0)) = 0;
        disparityMap = medfilt2(disparityMap, [30 30],'symmetric');
    
    case 21 % Subject 2, LM image pair
        disparityRange = [292 372];
        disparityMap = disparity(im_left,im_right,'DisparityRange',...
            disparityRange, 'ContrastThreshold',0.6, ...
            'UniquenessThreshold',1,'DistanceThreshold',5,'BlockSize',11);
        disparityMap(imcomplement(mask > 0)) = 0;
        disparityMap = medfilt2(disparityMap, [100 100], 'symmetric');
    case 22 % Subject 2, MR image pair 
        disparityRange = [292 372];
        disparityMap = disparity(im_left,im_right,'DisparityRange',...
            disparityRange, 'ContrastThreshold',0.6, ...
            'UniquenessThreshold',1,'DistanceThreshold',10,'BlockSize',9);
        disparityMap(imcomplement(mask > 0)) = 0;
        disparityMap = medfilt2(disparityMap, [100 100], 'symmetric');
    
    case 31 % Subject 3, LM image pair
        disparityRange = [430-16*7 430];
        disparityMap = disparity(im_left,im_right,'DisparityRange',...
            disparityRange, 'ContrastThreshold',1, ...
            'UniquenessThreshold',5,'DistanceThreshold',100,'BlockSize',15);
        disparityMap(imcomplement(mask > 0)) = 0;
        disparityMap = medfilt2(disparityMap, [100 100],'symmetric');
    case 32 % Subject 3, MR image pair 
        disparityRange = [426-16*5 426];
        disparityMap = disparity(im_left,im_right,'DisparityRange',...
            disparityRange, 'ContrastThreshold',1, ...
            'UniquenessThreshold',5,'DistanceThreshold',100,'BlockSize',17);
        disparityMap(imcomplement(mask > 0)) = 0;
        disparityMap = medfilt2(disparityMap, [80 80],'symmetric');
end

% Remove holes in the disparity map
disparityMap = imfill(disparityMap,'holes');

% Plot Disparity map
figure;
imshow(disparityMap,disparityRange);
colormap(gca,jet);
colorbar;

% Remove unreliable points from the disparity map
unreliable = ones(size(disparityMap));
unreliable(find(disparityMap~=0)) = 0;
unreliable(find(disparityMap==-realmax('single'))) = 1; 

end