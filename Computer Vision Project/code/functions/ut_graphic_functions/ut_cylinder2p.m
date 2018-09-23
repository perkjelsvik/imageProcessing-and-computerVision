function h = ut_cylinder2p(hg, R, N,r1,r2,pcol,patchP)
% h = UT_CYLINDER2P(hg, R, N,r1,r2,pcol,surfP) creates a N-sided cylinder
% surface object with varying radii along the axis of the cylinder.
% The surface consists of a series of N-sided polygons with successive
% radii given by the array R. The axis of the cylinder runs from the 3D
% vectors r1 to r2. The color is given by pcol. The patch color is copied
% to the Cdata. The remaining radiometric properties are defined by the
% struct surfP. All struct fields must be a surf property name, denoted in
% lower case. E.g. surfP.facecolor. These fields overwrite their defaults
% (see m-code). The function returns the handle to the patch object.
% 
% If hg is empty, this argument is ignored.
% If hg is not empty, it must be the handle of a hgtransform object.
% In that case, the surface is parented to hg. This is particularly useful
% for constructing more complex graphical objects which can be transformed
% with the properties of a hgtransform object.
% See: HGTRANSFORM, UT_CUBE, UT_DISK2P, UT_WALL

if nargin<7, patchP.dummy=1; end
if isempty(patchP), patchP.dummy=1; end

% Set up an array of angles for the polygon.
theta = linspace(0,2*pi,N);

m = length(R);                 % Number of radius values
% supplied.

if m == 1                      % Only one radius value supplied.
    R = [R; R];                % Add a duplicate radius to make
    m = 2;                     % a cylinder.
end


X = zeros(m, N);             % Preallocate memory.
Y = zeros(m, N);
Z = zeros(m, N);

v=(r2-r1)/sqrt((r2-r1)*(r2-r1)');    %Normalized vector;
%cylinder axis described by: r(t)=r1+v*t for 0<t<1
R2=rand(1,3);       %linear independent vector (of v)
x2=v-R2/(R2*v');    %orthogonal vector to v
x2=x2/sqrt(x2*x2'); %orthonormal vector to v
x3=cross(v,x2);     %vector orthonormal to v and x2
x3=x3/sqrt(x3*x3');

r1x=r1(1);r1y=r1(2);r1z=r1(3);
r2x=r2(1);r2y=r2(2);r2z=r2(3);
x2x=x2(1);x2y=x2(2);x2z=x2(3);
x3x=x3(1);x3y=x3(2);x3z=x3(3);

time=linspace(0,1,m);
for j = 1 : m
    t=time(j);
    X(j, :) = r1x+(r2x-r1x)*t+R(j)*cos(theta)*x2x+R(j)*sin(theta)*x3x;
    Y(j, :) = r1y+(r2y-r1y)*t+R(j)*cos(theta)*x2y+R(j)*sin(theta)*x3y;
    Z(j, :) = r1z+(r2z-r1z)*t+R(j)*cos(theta)*x2z+R(j)*sin(theta)*x3z;
end

C = zeros([size(Z),3]);
C(:,:,1) = pcol(1);     C(:,:,2) = pcol(2);     C(:,:,3) = pcol(3);
h = surf(X,Y,Z,C);
if isfield(patchP,'facecolor'),         set(h,'Facecolor',patchP.facecolor);               else set(h,'Facecolor','interp');      end;
if isfield(patchP,'facealpha'),         set(h,'facealpha',patchP.facealpha);               else set(h,'facealpha',1);             end;
if isfield(patchP,'edgecolor'),         set(h,'Edgecolor',patchP.edgecolor);               else set(h,'edgecolor','none');        end;
if isfield(patchP,'facelighting'),      set(h,'facelighting',patchP.facelighting);         else set(h,'facelighting','gouraud');  end;
if isfield(patchP,'ambientstrength'),   set(h,'ambientstrength',patchP.ambientstrength);   else set(h,'ambientstrength',0.2);     end;
if isfield(patchP,'diffusestrength'),   set(h,'diffusestrength',patchP.diffusestrength);   else set(h,'diffusestrength',0.5);     end;
if isfield(patchP,'specularstrength'),  set(h,'specularstrength',patchP.specularstrength); else set(h,'specularstrength',0.5);    end;
if isfield(patchP,'specularexponent'),  set(h,'specularexponent',patchP.specularexponent); else set(h,'specularexponent',25);     end;

if ~isempty(hg)
    set(h,'Parent',hg);
end
end


