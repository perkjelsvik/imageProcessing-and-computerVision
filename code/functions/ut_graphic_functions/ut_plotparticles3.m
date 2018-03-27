function h = ut_plotparticles3(hg, Nlong, Nlat, x, w, pcol, patchP)
% h = UT_PLOTPART3(hg, Nlong, Nlat,  x, w, pcol, patchP) plots
% a cloud of particles defined by the postions x. Each particle is plotted
% as a sphere with radia indicated by w. x must be a 3xN vector containing
% N particles. w is a 1xN vector. 
%
% The number of surface elements of each sphere is defined by Nlong and
% Nlat; i.e. the number of meridians and the number of parallels (longitude
% and lattitude).
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

[n,m] = size(x);
if n~=3,     error('ut_plotpart3: wrong input format x'); end
[u,v] = size(w);
if v~=m || u~=1,     error('ut_plotpart3: wrong input format w'); end

h =zeros(m,1);
for n=1:m
    h(n) = hgtransform;
    ut_superquadric(h(n),Nlong,Nlat, w(n), 2,pcol,patchP);
    set(h(n),'Matrix',[eye(3) x(:,n); zeros(1,3) 1]);
    if ~isempty(hg), set(h(n),'Parent',hg); end
end
end


