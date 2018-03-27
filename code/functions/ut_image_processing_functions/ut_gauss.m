function [Iout]=ut_gauss(varargin)
%ut_gauss	- 2-D filtering using Gaussian masks 
%
%   H = UT_GAUSS(I,SIGMA,DX,DY) filters the data in image I with a 2-D FIR
%   filter whose PSF closely approximates a Gaussian function or one of its
%   derivatives. The width (scale; standard deviation) of the Gaussian is
%   SIGMA (default SIGMA=2).
%
%   Different types of masks can be specified by parameters DX,DY:
%
%       DX   - number of diferentiations in x direction
%       DY   - number of diferentiations in y direction
%
%   Default: DX=0,DY=0.
%
%   - DX+DY must be less or equal to 2.
%   - The size of the mask is 2*ceil(4*SIGMA)+1.
%   - The elements of the PSF are obtained by area sampling of the
%     continuous function, rather than impulse sampling. (Area sampling is
%     equivalent to impulse sampling preceded by a prefilter. The prefilter
%     prevents large aliasing errors that would otherwise occur if SIGMA is 
%     too small (say, smaller than 1.5). However, the prefilter also introduces a
%     resolution error that becomes noticeable if SIGMA is smaller than,
%     say, 0.7. The response of the prefilter is a rectangular function with unit width).
%   - UT_GAUSS uses IMFILTER with the replication option on.
%
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   Laboratory for Measurements and Instrumentation
%   University of Twente, the Netherlands
%   Version 1.0, date: 25-10-2004
%
%  See also IMFILTER
[Iin,sigma,typein]=ParseInputs(varargin{:});

winsiz = ceil(4*sigma);
n=2*winsiz+1;


%gaussian
if strcmp(typein,'normal')
    kernel=create_gauss_kernel(sigma,n,winsiz);
    Iout=imfilter(double(Iin),double(kernel),'replicate','conv');
    Iout=imfilter(double(Iout),double(kernel'),'replicate','conv');
end

%gauss-dx
if strcmp(typein,'dx')
    kernel=create_gauss_kernel(sigma,n,winsiz);
    Iout=imfilter(double(Iin),double(kernel'),'replicate','conv');
    kernel=create_gauss_kernel_x(sigma,n,winsiz);
    Iout=imfilter(double(Iout),double(kernel),'replicate','conv');
end

%gauss-dxdx
if strcmp(typein,'dxdx')
    kernel=create_gauss_kernel(sigma,n,winsiz);
    Iout=imfilter(double(Iin),double(kernel'),'replicate','conv');
    kernel=create_gauss_kernel_xx(sigma,n,winsiz);
    Iout=imfilter(double(Iout),double(kernel),'replicate','conv');
end

%gauss-dy
if strcmp(typein,'dy')
    kernel=create_gauss_kernel(sigma,n,winsiz);
    Iout=imfilter(double(Iin),double(kernel),'replicate','conv');
    kernel=create_gauss_kernel_x(sigma,n,winsiz);
    Iout=imfilter(double(Iout),double(kernel'),'replicate','conv');
end

%gauss-dydy
if strcmp(typein,'dydy')
    kernel=create_gauss_kernel(sigma,n,winsiz);
    Iout=imfilter(double(Iin),double(kernel),'replicate','conv');
    kernel=create_gauss_kernel_xx(sigma,n,winsiz);
    Iout=imfilter(double(Iout),double(kernel'),'replicate','conv');
end

%gauss-dxdy
if strcmp(typein,'dxdy')
    kernel=create_gauss_kernel_x(sigma,n,winsiz);
    Iout=imfilter(double(Iin),double(kernel),'replicate','conv');
    Iout=imfilter(double(Iout),double(kernel'),'replicate','conv');
end


%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [Iin,Sigma,typein] =  ParseInputs(varargin)
narginchk(1,4)
%MSG = NARGCHK(LOW,HIGH,N) returns an appropriate error message if
%    N is not between low and high. If it is, return empty matrix.

Iin = varargin{1};

%defaults
typein = 'normal';
Sigma=2;

methods = {'normal','dx','dxdx';'dy','dxdy','err';'dydy','err','err'};

if nargin>1
    Sigma=varargin{2};%!!!! special braces to make it numerical
end
if nargin>2
    if nargin==4
        i = varargin{3};
        j = varargin{4};
        if ((j>2)|(i>2)|(j<0)|(i<0)|(round(i)~=i)|(round(j)~=j))
            typein='err';
        else
            typein = methods{j+1,i+1};
        end
        if strcmp(typein,'err')
            disp('DX+DY must be less or equal to 2.');
            error(['Invalid input string: ',num2str(varargin{3}),',',num2str(varargin{4}),'.']);
        end
    else
        error(['If DX is specified DY must be specified!!!']);
    end
end


if Sigma<0
    error('Sigma must be positive');
end
return

%--------------------------------------------------------------------------
%   Subfunction create_gauss_kernel
%--------------------------------------------------------------------------
function kernel=create_gauss_kernel(sigma,n,winsiz)
kernel=zeros(1,n);
c = 1.0/(sigma*sqrt(2));
for i=1:winsiz+1
    hulp(i) = erf((i-1+0.5)*c)-erf((i-1-0.5)*c);
end
accu = hulp(1);
for i=2:winsiz+1
    accu = accu+(2.0*hulp(i));
end

for i=1:winsiz
    kernel(winsiz+1-i) = (hulp(i+1)/accu);
    kernel(winsiz+1+i) = (hulp(i+1)/accu);
end
kernel(winsiz+1) = (hulp(1)/accu);
return


%--------------------------------------------------------------------------
%   Subfunction create_gauss_kernel_x
%--------------------------------------------------------------------------
function kernel=create_gauss_kernel_x(sigma,n,winsiz)
c =  1.0/(sigma*sqrt(2.0*pi));
sigma2=sigma^2;
kernel=zeros(1,n);

for i=1:n
    x=i-winsiz-1;
    x1 = x - 0.5;
    x2 = x + 0.5;
    kernel(i)= c*(exp(-0.5*x2*x2/sigma2)-exp(-0.5*x1*x1/sigma2));
end
return


%--------------------------------------------------------------------------
%   Subfunction create_gauss_kernel_xx
%--------------------------------------------------------------------------
function kernel=create_gauss_kernel_xx(sigma,n,winsiz)
c =  1.0/(sigma^3*sqrt(2.0*pi));
sigma2=sigma^2;
kernel=zeros(1,n);
for i=1:n
    x=i-winsiz-1;
    x1 = x - 0.5;
    x2 = x + 0.5;
    if (i==1)
        kernel(i)= c*(-x2*exp(-0.5*x2*x2/sigma2));
    else
        if (i==n)
            kernel(i)= c*(x1*exp(-0.5*x1*x1/sigma2));
        else
            kernel(i)= c*(x1*exp(-0.5*x1*x1/sigma2)-x2*exp(-0.5*x2*x2/sigma2));
        end
    end
end
return
