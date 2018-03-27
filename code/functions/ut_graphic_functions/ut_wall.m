function h = ut_wall(hg, Nx,Ny, pcol, surfP)
% h = UT_WALL(hg,Nx,My,plcol,surfP) creates a flat square surface object
% with corners located at (-0.5,-0.5,0), (0.5,-0.5,0), (0.5,0.5,0) and
% (-0.5,0.5,0) spanned by a meshgrid of size (Nx,Ny). The surface color is
% defined by the vector pcol, which must have size (1,3) or (3,1). The
% surface color is copied to the Cdata. The remaining radiometric
% properties are defined by the struct surfP. All struct fields must be 
% a surface property name, denoted in lower case. E.g. surfP.facecolor.
% These fields overwrite their defaults (see m-code). The function returns
% the handle to the surface object.
% 
% If hg is empty, this argument is ignored. If hg is not empty, it must be
% the handle of a hgtransform object. In that case, the patch is parented
% to hg. This is particularly useful for constructing more complex
% graphical objects which can be transformed with the properties of a
% hgtransform object. 
% See: HGTRANSFORM, UT_CUBE, UT_ARROW3, UT_SUPERQUADRIC, UT_GENCYLINDER

if nargin<5, surfP.dummy=1; end
if isempty(surfP), surfP.dummy=1; end

[X,Y] = meshgrid(linspace(-0.5,0.5,Nx),linspace(-0.5,0.5,Ny));
Z = zeros(size(X));
Cdata = zeros(Nx,Ny,3);
Cdata(:,:,1)=pcol(1); Cdata(:,:,2)=pcol(2); Cdata(:,:,3)=pcol(3); 
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
