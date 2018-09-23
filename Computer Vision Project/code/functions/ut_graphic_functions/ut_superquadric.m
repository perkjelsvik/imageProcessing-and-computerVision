function h = ut_superquadric(hg, Nlong, Nlat, Scale, Lnorm, pcol, patchP)
% h = UT_SUPERQUADRIC(hg, Nlong, Nlat, Scale, Lnorm, pcol, surfP) creates
% a superquadric surface object centered at the origin. The scale in the X,
% Y and Z direction of the object is given by the 3D vector Scale. If Scale
% is a scalar, the scale is equal in all the three directions.
%
% The superquadric is further defined by the Lnorm. This norm is either
% applied to each component differently (if Lnorm is a 3D vector), or
% commonly applied to all components (if Lnorm is a scalar). The
% superquadric is defined by the equation: 
%
% (X/Scale(1)).^Lnorm(1)+(Y/Scale(2)).^Lnorm(2)+(Z/Scale(3)).^Lnorm(3)=1
% 
% in case both Scale and Lnorm are 3D vectors.
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

if length(Scale)==1, Scale = [Scale Scale Scale]; end
if length(Lnorm)==1, Lnorm = [Lnorm Lnorm Lnorm]; end

c = @(w,m) sign(cos(w)).* abs(cos(w)).^m;
s = @(w,m) sign(sin(w)).* abs(sin(w)).^m;


u = linspace(-pi,pi,Nlong);
v = linspace(-pi/2,pi/2,Nlat);
u(:,end) = u(:,1);

[u,v] = meshgrid(u,v);
X = Scale(1) * c(v,2/Lnorm(1)) .* c(u,2/Lnorm(1));
Y = Scale(2) * c(v,2/Lnorm(2)) .* s(u,2/Lnorm(2));
Z = Scale(3) * s(v,2/Lnorm(3));
X(1,:) = 0;
X(end,:) = 0;
Y(1,:) = 0;
Y(end,:) = 0;

Cdata = zeros([size(Z) 3]);
Cdata(:,:,1) = pcol(1); Cdata(:,:,2) = pcol(2);  Cdata(:,:,3) = pcol(3);

holdstate = ishold;
hold on
h = surf(X,Y,Z,Cdata);
if holdstate, hold on; else hold off; end;

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
