function h = ut_disk2p(hg,R, N,r1,r2,pcol, patchP)
% h = UT_DISK_2P(hg,R, N,r1,r2,pcol, patchP) creates an N-sided disk with radius R.
% The parametric surface will consist of a series of N-sided polygons.
% The center of the disk is at the 3D vector r1. The disk points in the direction
% of the 3D-vector r2-r1. The color is defined by pcol.
%
% The patch color is copied to the Cdata property. The remaining radiometric
% properties are defined by the struct patchP. All struct fields must be
% a patch property name, denoted in lower case. E.g. patchP.facecolor.
% These fields overwrite their defaults (see m-code). The function returns
% the handle to the patch object.
%
% If hg is empty, this argument is ignored.
% If hg is not empty, it must be the handle of a hgtransform object.
% In that case, the patch is parented to hg. This is particularly useful
% for constructing more complex graphical objects which can be transformed
% with the properties of a hgtransform object.
% See: HGTRANSFORM, UT_CUBE, UT_WALL, UT_CYLINDER2P

if nargin<7, patchP.dummy=1; end
if isempty(patchP), patchP.dummy=1; end

% Set up an array of angles for the polygon.
theta = linspace(0,2*pi,N+1);
if size(r1,1)==1, r1=r1'; end
if size(r2,1)==1, r2=r2'; end

if length(R) == 1
   R = [R R]; 
end

V = zeros(3, N+1);                  % Preallocate memory.
V(2,:) = R(1)*cos(theta);
V(3,:) = R(2)*sin(theta);

v=(r2-r1)/sqrt((r2-r1)'*(r2-r1));   % Normalized vector;
%cylinder axis described by: r(t)=r1+v*t for 0<t<1
% R2= [1 0 1]'; 
R2 = rand(3,1);                       %linear independent vector (of v)
x2=v-R2/(R2'*v);                    %orthogonal vector to v
x2=x2/sqrt(x2'*x2);                 %orthonormal vector to v
x3=cross(v,x2);                     %vector orthonormal to v and x2
x3=x3/sqrt(x3'*x3);

R = [v x2 x3];

V = R*V + r1*ones(1,N+1);

C = zeros(1,N+1,3);
C(:,:,1) = pcol(1);
C(:,:,2) = pcol(2);
C(:,:,3) = pcol(3);
h = patch('Vertices',V','Faces',(1:N+1),'cdata',C);
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
