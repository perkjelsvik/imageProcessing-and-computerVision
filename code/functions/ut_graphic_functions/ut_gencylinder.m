function h = ut_gencylinder(hg, Fcross, Zval, Nlong, Nlat, pcol, surfP)
% h = UT_GENCYLINDER(hg, Fcross, Zval, Nlong, Nlat, pcol, surfP) creates
% a surface object in the current axes of the type 'generalized cylinger'.
% This object is based on a spinal chord that runs along the Z-axis from [0 0 -1] to
% [0 0 +1]. The surface is defined with two parametric variables u and v,
% defined on a meshgrid of -pi<=u<=pi with Nlong number of points, and
% -1<=v<=1 with % Nlat number of points. That is:
%  [u,v] = meshgrid(linspace(-pi,pi,Nlong),linspace(-1,1,Nlat));
% The generalized cylinder is then given by:
%
%   X = real(Fcross(u,v));
%   Y = imag(Fcross(u,v));
%   Z = Zval(v);
%
% Fcross is a function handle that produces the coordinates X,Y of
% a slice at a lattitude of v, and along the longitude range of u. Zval is a
% function handle that produces the height for a certain lattitude v. If
% Zval is empty, then Zval(v)=v is assumed.
%
% Example:
%
% Fcross = @(u,v) (1-v.^2).^0.5.*(cos(u).*sin(2*u)+1i.*sin(u).*sin(2*u));
% Zval = @(v) v;            % or just: Zval=[] in this case
%
% produces a four-leafed rose.
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
if nargin<7, surfP.dummy=1; end
if isempty(surfP), surfP.dummy=1; end

if isempty(Zval), Zval = @(v) v;  end

[u,v] = meshgrid(linspace(-pi,pi,Nlong),linspace(-1,1,Nlat));
u(:,end) = u(:,1);

F = Fcross(u,v);
X = real(F);
Y = imag(F);
Z = Zval(v);

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
