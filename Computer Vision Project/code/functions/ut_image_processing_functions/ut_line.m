function [lam1,dir, lambdas]=ut_line(varargin)
%ut_line: find line strength and directions using the eigenvalues of the Hessian
%
% [LINE,DIR,LAMBDAS]=UT_LINE(I,SIGMA1,SIGMA2) finds the line strength
% defined by the Hessian matrix. UT_LINE uses Gaussian low-pass filtering to
% find the  derivatives of the input image
%
% I:        input image (gray image).
% SIGMA1:   sigma of the prefilter used to calculate the 2nd derivatives
%           (default: 0.7).
% SIGMA2:   sigma of the prefilter used to calculate the 1st derivatives
%           (default: 2*SIGMA1).
% LINE:     line strength = largest(lambda of Hessian) - 4*mag(gradient).
% DIR:      direction perpendicular on the associated line
% LAMBDAS:  sorted eigenvalues of Hessian.
%
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   Laboratory for Measurements and Instrumentation
%   Robotics and Mechatronics
%   University of Twente, the Netherlands
%   Version 1.0, date: 14-12-2005
%   Version 2.0, date: 08-03-2017
%
% See also: UT_GAUSS, UT_LUCAS_KANADE, UT_HARRIS, UT_EDGE

[I,sigma1,sigma2]=ParseInputs(varargin{:});


% find 2nd derivatis (hessian)
a = ut_gauss(I,sigma1,2,0); % fxx
c = ut_gauss(I,sigma1,0,2); % fyy
b = ut_gauss(I,sigma1,1,1); % fxy

% find eigenvalues
D = a.^2 - 2*a.*c + c.^2 + 4*b.^2;
D = real(D.^0.5);
lam1 = 0.5*(a + c + D);
lam2 = 0.5*(a + c - D);

% sort eigenvalues
ind = find(abs(lam2)>abs(lam1));
lammax = lam1;
lammin = lam2;
lammax(ind) = lam2(ind);
lammin(ind) = lam1(ind);
lambdas = cat(3,lammax,lammin);

% find eigenvector of largest eigenvalue
v = ones(length(lammax(:)),2);
i = find(abs(b)<100*eps);
j = find(abs(b)>=100*eps & abs(lammax)>0);
v(j,2) = (lammax(j) - a(j))./b(j);
v(i,2) = b(i)./(lammax(i)-c(i));

% find direction
dir = atan2(v(:,2),v(:,1))*180/pi;
dir = reshape(dir,size(I));

% find the line strength
lam2 = lam1;
grad = (ut_gauss(I,sigma2,0,1).^2+ut_gauss(I,sigma2,1,0).^2).^0.5;
lam1 = abs(lammax) - 4*grad;

% % local maxima suppression in horizontal and vertical direction
% siz = size(lam1);
% left = circshift(lam1,[1 0]);
% right = circshift(lam1,[-1 0]);
% horz = (left <= lam1) & (right<lam1);
% left = circshift(lam1,[0,1]);
% right = circshift(lam1,[0,-1]);
% vert = (left <= lam1) & (right<lam1);
% alldir = vert | horz;
% alldir(1:end,1) = 0;
% alldir(1:end,end) = 0;
% alldir(1,1:end) = 0;
% alldir(end,1:end) = 0;
% lam1 = lam1.*alldir;
% lam1(find(lam1<0)) = 0;

%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [Iin,sigma1,sigma2] =  ParseInputs(varargin)

narginchk(1,3);
%MSG = NARGCHK(LOW,HIGH,N) returns an appropriate error message if
%    N is not between low and high. If it is, return empty matrix.

Iin = varargin{1};
if ~ismatrix(Iin)
    error('The input image must be a 2-dimensional array');
end

%defaults
sigma1 = 0.7;
sigma2 = 1.4;

if nargin>1
    sigma1 = varargin{2};   %!!!! special braces to make it numerical
    if (sigma1<0.5)
        error('SIGMA1 must be at least 0.5');
    end
    sigma2 = 2.5*sigma1;
end
if nargin>2
    sigma2 = varargin{3};   %!!!! special braces to make it numerical
    if (sigma2<0.5)
        error('SIGMA2 must be at least 0.5');
    end
end

