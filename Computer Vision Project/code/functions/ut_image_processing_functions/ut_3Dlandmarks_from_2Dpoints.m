function [Xpost, Cpost] = ut_3Dlandmarks_from_2Dpoints(varargin)
%function [Xpost, Cpost] = ut_3Dlandmarks_from_2Dpoints(p,sigma,K,wRc,wtc,Xprior,Cprior)
%
%MMSE estimation of 3D points from corresponding image points
%
% INPUTS:
% p:            2xN array with N detected image points in pixel coordinates
% sigma:        standard uncertainty of the localization error in pixel coordinates
% K:            3x3 calibration matrix
% wRc:          3x3 rotation matrix of camera wrt world coordinate system
% wtc:          3x1 vector denoting the origin of the camera in world coordinates
% Xprior:       3xN array with N 3D landmarks in world coordinates,
%               representing the prior knowledge (expectations) of the landmark positions
% Cprior:       3x3xN array with N 3x3 covariance matrices defining the
%               uncertainties of the prior knowledge (given in world coordinates)
% OUTPUTS:
% Xpost:        3xN array with N 3D landmarks in world coordinates,
%               representing the posterior knowledge (expectations) of the landmark positions
% Cpost:        3x3xN array with N 3x3 covariance matrices defining the
%               uncertainties of the posterior knowledge (given in world coordinates)
%
% The matrices and vector are in non-transposed form. That is, the
% transformation from camera to world coordinates is: wX = wRc*cX + wtc.
%
% MMSE estimation assumes the availability of prior knowledge about the 3D
% positions of the landmarks. This prior knowledge is represented by an
% expectations Xprior, and covariance matrices. The function uses the
% linearity of the projection if this is expressed in homogeneous
% coordinates. This keeps assures that the estimation is linear, and it
% allows the calculation of not only the posterior expectations, but also
% the posterior covariance matrices.
%
% USAGE:
% The function processes just one image at a time. In dual camera systems,
% or multiple camera systems, the routine needs to called iteratively. The
% system is initiated with the first camera by:
%
% [Xpost, Cpost] = ut_3Dlandmarks_from_2Dpoints(p,K,wR1,wt1)
%
% in which wR1 and wt1 is the pose of this camera. The image of second
% camera is then successively called by:
%
% Xprior = Xpost;
% Cprior = Cpost;
% [Xpost, Cpost] = ut_3Dlandmarks_from_2Dpoints(p,K,wRc,wtc,Xprior,Cprior)
%
% In the firs call, the Xprior and Cprior are initialized with Xprior equal
% to cXprior = [0; 0; 1000], and a covariance matrix Cprior = 1e6*eye(3).
% For most applications, the Cprior is so large, that cXprior does not
% effect the result if two or more cameras are processed.
%
% The results can be visualized in 3D with ut_plotcov3
%
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   Robotics and Mechatronics
%   University of Twente, the Netherlands
%   Version 1.0, date: 06-04-2017
%
%   See also UT_PLOTCOV3


[p,sigma,K,wRc,wtc,Xprior,Cprior,Np]=ParseInputs(varargin{:});

k1T = K(1,:);
k2T = K(2,:);
k3T = K(3,:);

cRw = wRc';
ctw = -cRw*wtc;

Xpost = zeros(3,Np);
if Np==1, Cpost = zeros(3); else Cpost = zeros(3,3,Np); end
for n=1:Np
    h1 = (p(1,n)*k3T-k1T)*cRw;
    h2 = (p(2,n)*k3T-k2T)*cRw;
    H = [h1;h2];
    z1 = k1T*ctw-k3T*ctw*p(1,n);
    z2 = k2T*ctw-k3T*ctw*p(2,n);
    z = [z1;z2];
    Cpred = Cprior(:,:,n);
    Xpred = Xprior(:,n);
    cXpred = cRw*Xpred + ctw;
    
    % first estimate
    Cn = sigma^2*cXpred(3)^2*eye(2);          % measurement noise
    S = H*Cpred*H' + Cn;
    K = Cpred*H'/S;
    Xp = Xpred + K*(z - H*Xpred);
    % second estimate
    cXpred = cRw*Xp + ctw;
    Cn = sigma^2*cXpred(3)^2*eye(2);          % measurement noise
    S = H*Cpred*H' + Cn;
    K = Cpred*H'/S;
    Xpost(:,n) = Xpred + K*(z - H*Xpred);
    Cpost(:,:,n) = Cpred - K*S*K';
end



end


%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [p,sigma,K,wRc,wtc,Xprior,Cprior,N] =  ParseInputs(varargin)

narginchk(5,7);

%% read p
p = double(varargin{1});
if ndims(p)>2
    error('improper format of p');
end
[nr,N] = size(p);
if nr~=2
    error('improper format of p');
end

sigma = double(varargin{2});


%% read K
K = double(varargin{3});
if ~ismatrix(K)
    error('improper format of K');
end
[nr,nc] = size(K);
if nr~=3 | nc~=3
    error('improper format of K');
end

%% read wRc
wRc = double(varargin{4});
if ~ismatrix(wRc)
    error('improper format of wRc');
end
[nr,nc] = size(wRc);
if nr~=3 | nc~=3
    error('improper format of wRc');
end

%% read wtc
wtc = double(varargin{5});
if ndims(wtc)>2
    error('improper format of wtc');
end
[nr,nc] = size(wtc);
if nr~=3 | nc~=1
    error('improper format of wtc');
end

%% initialize Xprior
if nargin==5
    cXprior = [0;0;400];
    wXprior = wRc*cXprior+wtc;
    Xprior = repmat(wXprior,[1,N]);
    Cprior = reshape(repmat(eye(3,3)*1e10,[1, N]),3,3,N);
else
    if nargin~=7, error('wrong number of input variables'); end
    %% read Xprior
    Xprior = double(varargin{6});
    if ndims(Xprior)>2
        error('improper format of Xprior');
    end
    [nr,nc] = size(p);
    if nr~=2
        error('improper format of Xprior');
    end
    if nc~=N
        error('Xprior inconsistent with p')
    end
    %% read Cprior
    Cprior = double(varargin{7});
    M = ndims(Cprior);
    if M==2
        if N>1, error('improper format of Cprior'); end
        [nr,nc] = size(Cprior);
        if nr~=3 | nc~=3, error('improper format of Cprior'); end
    else
        if M==3
            [nr,nc,ns] = size(Cprior);
            if nr~=3 | nc~=3, error('improper format of Cprior'); end
            if ns~=N, error('improper format of Cprior'); end
        else
            error('improper format of Cprior');
        end
    end
end
end

