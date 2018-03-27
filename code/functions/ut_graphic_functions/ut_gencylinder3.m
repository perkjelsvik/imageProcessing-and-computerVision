function h = ut_gencylinder3(hg, Fcross, Xv, Yv, Zv, Nlong, Nlat, pcol, surfP)
% h = UT_GENCYLINDER(hg, Fcross, X,Y,Z, Nlong, Nlat, pcol, surfP) creates
% a surface object in the current axes of the type 'generalized cylinder'.
% This object is based on a spinal chord [X(t),Y(t),Z(t)]. The parameter t
% runs for 0 to 1. For each t, there is a plane that is orthogonal to the
% tangent X1(t) = [X'(t),Y'(t),Z'(t)] of the chord. The generalized cylinder is
% defined by a cross section Fcross(u,t) in the orthogonal plane at t.
% In order to specify the orientation of the 2D coordinate system in that
% plane, the second derivative X2(t)=[X"(t), Y"(t), Z"(t)] is used. Hence,
% define: x(t)=cross(X1(t), X2(t)), and y(t)=cross(x(t),X1(1)), and use the
% normalized versions of these 2 vectors: xn(t) and yn(t).

% The two parametric variables u and t, are defined on a meshgrid of
% -pi<=u<=pi with Nlong number of points, and 0<=t<=1 with Nlat number
% of points. That is:
%  [u,t] = meshgrid(linspace(-pi,pi,Nlong),linspace(0,1,Nlat));
% The generalized cylinder is then given by:
%
%   Xgencyl(u,v) = real(Fcross(u,t))*xn(t) + imag(Fcross(u,v))*yn(t);
%
% Fcross is a function handle that produces the coordinates X,Y of
% a slice at a lattitude of t, and along the longitude range of u. X,Y and Z are a
% function handles that produces the spinal chord for a certain parameter t.
%
% Example:
%
% Fcross = @(u,t) (cos(u)+1i.*sin(u));
% Xv = @(t) 4*sin(2*pi*4*t);
% Yv = @(t) 4*cos(2*pi*4*t);
% Zv = @(t) 10*t-5;
%
% produces a helix spring.
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
%      UT_SUPERQUADRIC
if nargin<9, surfP.dummy=1; end
if isempty(surfP), surfP.dummy=1; end

if isempty(Zv), Zv = @(v) v;  end

%% uniform resample the curve
N = 10000;       % number of steps on the chord
t = linspace(0,1,N);
X = Xv(t);      Y = Yv(t);      Z = Zv(t);
dX = diff(X);   dY = diff(Y);   dZ = diff(Z);
ds = (dX.^2 +dY.^2 + dZ.^2).^0.5;
s =[0 cumsum(ds)];  % arc length
s=s/s(end);
t = interp1(s,linspace(0,1,N),linspace(0,1,N));

%% find the orthogonal planes
X = Xv(t);  Y = Yv(t);  Z = Zv(t);
dX = gradient(X);           dY = gradient(Y);           dZ = gradient(Z);
dX2 = gradient(dX);         dY2 = gradient(dY);         dZ2 = gradient(dZ);
dX = [dX; dY; dZ];
dX2 = [dX2; dY2; dZ2];
x = cross(dX,dX2);
y = cross(x,dX);
x = x./(ones(3,1)*sum(x.^2).^0.5);
y = y./(ones(3,1)*sum(y.^2).^0.5);



%% produce the 2D grid folded in 3D space
i=round(linspace(1,N,Nlat));
t = t(i);
x = x(:,i);
y = y(:,i);
[u,v] = meshgrid(linspace(-pi,pi,Nlong),t);
u(:,end) = u(:,1);

X = Xv(v);      Y = Yv(v);      Z = Zv(v);
F = Fcross(u,v);
X = X + real(F).*(x(1,:)'*ones(1,Nlong)) + imag(F).*(y(1,:)'*ones(1,Nlong));
Y = Y + real(F).*(x(2,:)'*ones(1,Nlong)) + imag(F).*(y(2,:)'*ones(1,Nlong));
Z = Z + real(F).*(x(3,:)'*ones(1,Nlong)) + imag(F).*(y(3,:)'*ones(1,Nlong));

Cdata = zeros([size(Z) 3]);
Cdata(:,:,1) = pcol(1); Cdata(:,:,2) = pcol(2);  Cdata(:,:,3) = pcol(3);
h = surf(X,Y,Z,Cdata);
if isfield(surfP,'facecolor'),         set(h,'Facecolor',surfP.facecolor);               else set(h,'Facecolor','interp');      end;
if isfield(surfP,'facealpha'),         set(h,'facealpha',surfP.facealpha);               else set(h,'facealpha',1);             end;
if isfield(surfP,'edgecolor'),         set(h,'Edgecolor',surfP.edgecolor);               else set(h,'edgecolor','none');        end;
if isfield(surfP,'facelighting'),      set(h,'facelighting',surfP.facelighting);         else set(h,'facelighting','gouraud');  end;
if isfield(surfP,'ambientstrength'),   set(h,'ambientstrength',surfP.ambientstrength);   else set(h,'ambientstrength',0.2);     end;
if isfield(surfP,'diffusestrength'),   set(h,'diffusestrength',surfP.diffusestrength);   else set(h,'diffusestrength',0.5);     end;
if isfield(surfP,'specularstrength'),  set(h,'specularstrength',surfP.specularstrength); else set(h,'specularstrength',0.5);    end;
if isfield(surfP,'specularexponent'),  set(h,'specularexponent',surfP.specularexponent); else set(h,'specularexponent',25);     end;

if ~isempty(hg)
    set(h,'Parent',hg);
end
end
