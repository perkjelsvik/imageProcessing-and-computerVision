function h = ut_plotcov3(hg, Nlong, Nlat, xmean, Cmatrix, pcol, patchP)
% h = UT_PLOTCOV3(hg, Nlong, Nlat,  xmean, Cmatrix, pcol, patchP) creates
% an ellipsoid defined by the vector xmean and the matrix Cmatrix.
% xmean must be a 3x1 or 1x3 vector. It defines the center of the
% ellipsoid, and as such it can be regarded the mean of a Gaussian
% distribution. Cmatrix is the associated 3x3 covariance matrix.
%
% The ellipsoid is defined by the equation: xmean'*inv(Cmatrix)*xmean=1.
% The ellipsoid is obtained by calculation of the principal components:
% the eigenvectors define the orientation of the ellipsoid, and the
% associated squre roots of the eigenvalues define the scale in the
% principal directions. Finally, the figure is translated towards xmean.
%
% The number of surface elements is defined by Nlong and Nlat; i.e. the
% number of meridians and the number of parallels (longitude and
% lattitude).
%
% The patch color is defined by the vector pcol, which must have size (1,3)
% or (3,1). The patch color is copied to the Cdata. The remaining
% radiometric properties are defined by the struct surfP. All struct
% fields must be  a surface property name, denoted in lower case. E.g.
% surfP.facecolor. These fields overwrite their defaults (see m-code). The
% function returns the handle to the surface object.
%
% If hg is empty, this argument is ignored.
% If hg is not empty, it must be the handle of a hgtransform object.
% In that case, the patch is parented to hg. This is particularly useful
% for constructing more complex graphical objects which can be transformed
% with the properties of a hgtransform object.
% See: HGTRANSFORM, UT_CUBE, UT_WALL, UT_ARROW3, UT_DISK2P, UT_CYLINDER2P

if nargin<7, patchP.dummy=1; end
if isempty(patchP), patchP.dummy=1; end

[n,m] = size(xmean);
if n*m~=3,     error('ut_plotcov3: wrong input format xmean'); end
if m==3, xmean = xmean'; end
[n,m] = size(Cmatrix);
if n~=3 || m~=3,     error('ut_plotcov3: wrong input format Cmatrix'); end

[U,L,V]=svd(Cmatrix);
L = diag(L);
if min((imag(L)))~=0, error('ut_plotcov3: Cmatrix is degenerated, e.g. not symmetric'); end
if min(((L)))<=0, error('ut_plotcov3: Cmatrix is degenerated, e.g. rank<3'); end

hellips = ut_superquadric(hg,Nlong,Nlat, sqrt(L), 2,pcol,patchP);
set(hellips,'backfacelighting','lit');
set(hellips,'facelighting','phong');
h = hgtransform;
set(hellips,'parent',h);
M = eye(4);
M(1:3,4) = xmean;
if det(U)<0, U(:,3)=-U(:,3); end
M(1:3,1:3) = U;
set(h,'Matrix',M);
if ~isempty(hg)
    set(h,'Parent',hg);
end
end


