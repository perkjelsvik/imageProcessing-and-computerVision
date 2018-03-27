function h = ut_coordsystem(hg,scale,lwidth,axescol,surfP)
% h = ut_coordsystem(hg,scale,linewidth,linecol,surfP)
% draws the three axes of a coordinate system.  The parameter 'scale' is
% the length of the axes. If scale>0, the axes start at the origin. If
% scale<0, the axes on the negative side are also drawn.

% linewidth is the radii of the axes. axescol is the color of the axes. 
% The remaining radiometric properties are defined by the struct surfP. All 
% struct fields must be a patch property name, denoted in lower case; 
% e.g. surfP.facecolor. These fields overwrite their defaults (see m-code). 
% The function returns the handle(s) to the three surf objects.
%
% If hg is empty, this argument is ignored.
% If hg is not empty, it must be the handle of a hgtransform object.
% In that case, the patch is parented to hg. This is particularly useful
% for constructing more complex graphical objects which can be transformed
% with the properties of a hgtransform object.
% See: HGTRANSFORM, UT_CUBE, UT_WALL, UT_CYLINDER2P

if scale>0, b = 0; else b = scale; scale = -scale; end
h = ut_arrow3(hg,[b 0 0],[scale 0 0],lwidth,axescol,lwidth*6,lwidth*2,axescol,1,surfP);
h = [h ut_arrow3(hg,[0 b 0],[0 scale 0],lwidth,axescol,lwidth*6,lwidth*2,axescol,1,surfP)];
h = [h ut_arrow3(hg,[0 0 b],[0 0 scale],lwidth,axescol,lwidth*6,lwidth*2,axescol,1,surfP)];
if isempty(hg)
    h = [h text(abs(scale)-lwidth*2, 0, lwidth*4,'X')];
    h = [h text(0, abs(scale)-lwidth*2, lwidth*4,'Y')];
    h = [h text(0, lwidth*4, abs(scale)-lwidth*2,'Z')];
else
    h = [h text(abs(scale)-lwidth*2, 0, lwidth*4,'X','parent',hg)];
    h = [h text(0, abs(scale)-lwidth*2, lwidth*4,'Y','parent',hg)];
    h = [h text(0, lwidth*4, abs(scale)-lwidth*2,'Z','parent',hg)];
end
