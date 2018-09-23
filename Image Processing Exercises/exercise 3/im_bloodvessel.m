function [im]=im_bloodvessel(D)
% im_bloodvessel(D)  - generation of a simulated X-ray image of a bloodvessel
%
% IM = IM_BLOODVESSEL produces a 250x1000 image that is a simulation of an
% angiogram, i.e. an X-ray picture of a blood vessel. The simulated vessel
% is aligned horizontally. D is the diameter of the blood vessel (unit: mm).  
% The components of the  model of the X-ray imager are:
% a) Quantum mottle (Poisson noise): 2500 effective quanta/mm^2.
% b) An OTF of an image intensifier selected such that the FWHM (full width
%    half maximum) of the corresponding LSF is 0.3 mm.
% c) Sensor noise modelled as white Gaussian noise.
%
% The pixel width is 0.04 mm. Thus the image area is 10x20 mm.
%
% At each recall of the function different noise realizations are produced.

if nargin~=1
    error('Wrong number of input arguments')
end
D = D/1000;         % unit: from mm to meter
N = 250;            % number of rows
M = 1000;           % number of columns
delta = 40e-6;      % pixel distance (m)
R = D/2;            % radius
mu0 = 0.2 * 1000;   % absorption coefficient (1/m)

%% ideal image:
x = linspace(0,(N-1)*delta,N);
x = x - x(end)/2;
h1 = ones(N,1);
i = find(x.^2 < R^2);
h1(i) = exp(-2*mu0*sqrt((R^2)- x(i).^2));       % the profile
im = repmat(h1,[1 M]);                          % repeat the profile


%% add poisson noise (quantum mottle)
Nquant_per_pel = 20;%4; %10
a = Nquant_per_pel;
im = a*im;      % conversion to density of quanta per pixel
im =  (sqrt(im).*randn(size(im)) + im);

%% image intensifier
f_ii = 2 * 1000;
fdelta = 1/(delta*2);
[u,v] = freqspace([N,M],'meshgrid');
u = u*fdelta;
v = v*fdelta;
OTF = fftshift(exp(-sqrt(u.^2 + v.^2)/f_ii));
IM = fft2(im);
IM = IM.*OTF;
im = real(ifft2(IM));

%% add sensor noise
im = (im + 0.05*randn(size(im)))/(1.25*Nquant_per_pel);
