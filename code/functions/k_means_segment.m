function [segmentedImage] = k_means_segment(im)
% This function is based on the Matlab Example:
%   'Color-Based Segmentation Using K-Means Clustering'
% This example can be opened with the command
%   openExample('images/KMeansSegmentationExample')

%% Convert Image from RGB Color Space to L*a*b* Color Space
lab_face = rgb2lab(im);  % Convert image to L*a*b* color space

%% Classify the Colors in 'a*b*' Space Using K-Means Clustering
ab = lab_face(:,:,2:3);  % Extract tha a*b* values
nrows = size(ab,1);
ncols = size(ab,2);
ab = reshape(ab,nrows*ncols,2);
nColors = 3;             % Skin colour, hair colour, background colour
n = 3;                   % Repeat clustering n times to avoid local minima

% Run k-means clustering algorithm
[cluster_idx, cluster_center]= kmeans(ab,nColors,'Distance', ...
    'sqeuclidean', 'Replicates', n);

%% Label Every Pixel in the Image Using the Results from KMEANS
pixel_labels = reshape(cluster_idx,nrows,ncols);
%imshow(pixel_labels,[]), title('image labeled by cluster index');

%% Create Images that Segment the Face Image by Color.
segmented_images = cell(1,nColors);
rgb_label = repmat(pixel_labels,[1 1 3]);

for k = 1:nColors
    color = im;
    color(rgb_label ~= k) = 0;
    segmented_images{k} = color;
    %figure; 
    %imshow(segmented_images{k}), title(['objects in cluster ' num2str(k)]);
end

%% Segment the Face into a Separate Image
% Sort the clusters based on mean values
mean_cluster_value = mean(cluster_center,2);
[~, idx] = sort(mean_cluster_value);
skin_cluster_num = idx(3);

L = lab_face(:,:,1);                      % Extract the L* values
skin_idx = find(pixel_labels == skin_cluster_num);
L_skin = L(skin_idx);
is_light_skin = imbinarize(rescale(L_skin));

face_labels = repmat(uint8(0),[nrows ncols]);
face_labels(skin_idx(is_light_skin==false)) = 1;
face_labels = repmat(face_labels,[1 1 3]);

face = im;
face(face_labels ~= 1) = 0;               % Enhancing face
face_masked = face | segmented_images{3}; % Make binary mask 
face_masked = face_masked(:,:,1);         % Resize to two-dimensional

% Perform morphological operations to isolate the face
% The operations performed here were found by trial-and-error
% They gave generally acceptable results for the different subjects
seed = imerode(face_masked,strel('disk',12));
face_masked = imreconstruct(seed,face_masked);
face_masked = imopen(face_masked, strel('disk',10));
face_masked = imclose(face_masked, strel('disk',40));
seed = imerode(face_masked,strel('disk',24));
face_masked = imreconstruct(seed,face_masked);
segmentedImage = face_masked;

figure; imshow(face_masked), title('face_b');
end