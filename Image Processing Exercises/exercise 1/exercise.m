% Per Arne Kjelsvik s2049201 - Exercise 1
%% Question 1
clc
close all
clear variables

im = im2double(imread('car_dis.png'));  % Read image, convert to double
IM = fft2(im);                          % Element (1,1) is origin
IM_shift = fftshift(IM);                % Element (129,129) is origin

figure;
imshow(log(abs(IM_shift)+10), []);      % Plot log of magnitude, +10 for           
title('Log-magnitude spectrum', ...     % better visualization
    'FontSize', 26, 'Interpreter', 'latex');
xlabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex'); 
ylabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex');
print -r150 -dpng Imlogmag.png   

figure;
imshow(im)                              % Display the image

%% Question 2
% b) Matlab expression and numerical result of index of origin
[row,col]= find(IM(1,1) == IM_shift);   % Find origin in shifted spectrum

% c) Wavelength of harmonic function
Delta   = 1;
lambda  = 7*Delta;
rho     = 1/lambda;

%% Question 3
PSF = fspecial('average', [7 1]);       % 'average' for averaging filter
imfil = imfilter(im,PSF, 'replicate');  % 'replicate' used to handle edges

IMfil = fft2(imfil);                    % FFT of filtered image
IMfil_shift = fftshift(IMfil);          % Shift spectrum to center

figure;
imshow(log(abs(IMfil_shift)+2), []);
title('Log-magnitude spectrum', ...
    'FontSize', 26, 'Interpreter', 'latex');
xlabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex'); 
ylabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex');
print -r150 -dpng IMfillogmag.png

figure;
imshow(imfil);
imwrite(imfil,'imfil.jpg');

%% Question 4
OTF = psf2otf(PSF,[256,256]);           
OTF_shift = fftshift(OTF);

figure;
imshow(abs(OTF_shift));
imagesc(abs(OTF_shift),[0 1]); colormap(gray);
title('Magnitude of OTF', ...
    'FontSize', 26, 'Interpreter', 'latex');
xlabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex'); 
ylabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex');
print -r150 -dpng OTF.png

% b) Inspect the imaginary part of the otf
max(abs(imag(OTF(:))));                 % Imaginary part equal to 0

%% Question 5
s       = 9;                            % Size of rectangular side, odd
[N,M]   = size(im); 
H       = ones(size(im));                     
coff    = col - 1/2*N;                  % Column offset to distortion
roff    = ceil(row -(1/2*N-1/7*N));     % Row offset to distortion

% a) Matlab expressions for rstart, rend, cstart, cend
rstart  = ceil(row-roff-s/2);
cstart  = ceil(col+coff-s/2);
rend    = floor(row-roff+s/2);
cend    = floor(col+coff+s/2);

% b) Extend code so that symmetry requirments of H is met
% Could have used H.*flip(H) for easier calculation, but chose to do as
% below for perfect symmetry
H(rstart:rend, cstart:cend) = 0;
H(rstart+2*roff:rend+2*roff, cstart-2*coff:cend-2*coff) = 0;

% c) Apply the filter to the image
IM_H_shift = IM_shift.*H;           
IM_H = ifftshift(IM_H_shift);
im_H = ifft2(IM_H);

% d) Make graphical representations of the new OTF and log-magnitude
figure;
imshow(im_H);
imwrite(im_H,'car_dis_h.png');

figure;
imshow(log(abs(IM_H_shift)+10),[]);
title('Log-magnitude spectrum', ...
    'FontSize', 26, 'Interpreter', 'latex');
xlabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex'); 
ylabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex');
print -r150 -dpng logmagOTF.png

max(abs(imag(im_H(:))))

figure;
imshow(H);
imagesc(H,[0 1]); colormap(gray);
title('Magnitude of OTF', ...
    'FontSize', 26, 'Interpreter', 'latex');
xlabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex'); 
ylabel('Frequency [Hz]', 'FontSize', 22, 'Interpreter', 'latex');
print -r150 -dpng OTF_manual.png