function [ wRc,wtc,s,cnt ] = ut_ortho_iteration( varargin )
%[ wRc,wtc ] = ut_ortho_iteration(p,K,wX) 
% Find pose of camera from a few 3D landmarks
%
% INPUTS:
% p:            2xN array with N detected image points in pixel coordinates
% K:            3x3 calibration matrix
% wX:           3xN array with N 3D landmarks in world coordinates,
%               associated with the N detected image points p
% OUTPUTS:
% wRc:          Rotation matrix representing the orientation of the camera wrt world coordinates
% wtc:          Translation vector representing the origin of the camera in world coordinates
%
% The matrices and vector are in non-transposed form. That is, the
% transformation from camera to world coordinates is: wX = wRc*cX + wtc,
% and from homogeneous 3D camera coordinates to pixel coordinates is p=K*cX.
%
% [wRc,wtc ] = ut_ortho_iteration(p,K,wX,wRcinit) uses the rotation matrix
% wRcinit to start the algorithm. Otherwise, this initial rotation matrix is
% roughly estimated from p, K and wX.
%
%   Ref: Lu et al: "Fast and Globally Convergent Pose Estimation from Video Images, 2000
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   Robotics and Mechatronics
%   University of Twente, the Netherlands
%   Version 1.0, date: 11-04-2017


[p,K,X,cRwinit]=ParseInputs(varargin{:});
p = cart2hom(p')';
x = K\p;
N = length(x);
if nargin==3            % no initial rotation matrix
    cRwinit = eye(3);
%     [d,Z,transform] = procrustes(x',X','scaling',true,'reflection',false);
%     cRwinit = transform.T';
end

cRw = cRwinit;
F = zeros(3,3,length(x));
G = zeros(3,3);
for i=1:N;
    F(:,:,i) = x(:,i)*x(:,i)'/norm(x(:,i))^2;
    G = G + F(:,:,i);
end
G = N*eye(3) - G;
q = zeros(size(x));

cnt = 1;
tprev = -1e10*[1;1;1];
ctw = -tprev;
while norm(tprev-ctw)>1e-4
    tprev = ctw;
    ctw = zeros(3,1);
    for i=1:N
        ctw = ctw + (F(:,:,i) - eye(3))*cRw*X(:,i);
    end
    ctw = G\ctw;
    for i=1:N
        q(:,i) = F(:,:,i)*(cRw*X(:,i)+ctw);
    end
    qmean = mean(q,2);
    xmean = mean(X,2);
    qcent = q - qmean*ones(1,N);
    xcent = X - xmean*ones(1,N);
    M = qcent*xcent';
    [U,S,V] = svd(M);
    cRw = U*V';
    if det(cRw)<0, cRw=U*diag([1 1 -1])*V'; end
    cnt = cnt+1;
end

wRc = cRw';
wtc = -wRc*ctw;
s = diag(S);
end

%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [p,K,X,cRwinit] =  ParseInputs(varargin)

narginchk(3,4);

%% read p
p = double(varargin{1});
if ~ismatrix(p)
    error('improper format of p');
end
[nr,N] = size(p);
if nr~=2
    error('improper format of p');
end
if N<3
    error('number of points should be at least 3');
end



%% read K
K = double(varargin{2});
if ~ismatrix(K)
    error('improper format of K');
end
[nr,nc] = size(K);
if nr~=3 || nc~=3
    error('improper format of K');
end

%% read X
X = double(varargin{3});
if ~ismatrix(X)
    error('improper format of X');
end
[nr,Nx] = size(X);
if nr~=3
    error('improper format of p');
end
if Nx~=N
    error('X should have the same size as p');
end


%% get cRwinit
if nargin==4
    wRcinit = double(varargin{4});
    if ~ismatrix(wRcinit)
        error('improper format of wRcinit');
    end
    [nr,nc] = size(wRcinit);
    if nr~=3 || nc~=3
        error('improper format of wRcinit');
    end
    cRwinit = wRcinit';
else
    cRwinit = eye(3);
end
    
end


