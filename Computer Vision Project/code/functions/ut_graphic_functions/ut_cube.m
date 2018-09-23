function h = ut_cube(hg, Nx,Ny, pcol, cubeP)
% h = UT_CUBE(hg,Nx,My,plcol,cubeP) creates a cube consisting of 6 walls
% generated with UT_WALL. The cube is centered in the origin, and has unit
% sides. The surfuce color of all sides is defined by the vector pcol,
% which must have size (1,3) or (3,1). The surfuce color is copied 
% to the Cdata. The remaining radiometric properties are defined by the 
% struct cubeP. All struct fields must be a surfuce property name, denoted
% in lower case. E.g. cubeP.facecolor. These fields overwrite their
% defaults (see m-code of UT_WALL). The function returns an array of the 6
% handles of the 6 surfuce objects, i.e. the 6 faces that make up the cube.  
% If the colors of each face need to be different you can use these handles.
% The order of the handles are: front (x=0.5), back (x=-0.5), right(y=0.5),
% left (y=-0.5), up (z=0.5), down (z=-0.5).
% 
% If hg is not empty, it must be the handle to a hgtransform object. In
% that case, the surfuces are parented to hg. This is particularly useful 
% for constructing more complex graphical objects which can be transformed
% with the properties of a hgtransform object.
% See: HGTRANSFORM, UT_WALL, UT_ARROW3, UT_SUPERQUADRIC, UT_GENCYLINDER

if nargin<5, cubeP.dummy=1; end
if isempty(cubeP), cubeP.dummy=1; end

% front face
h = [  ut_wall([], Nx,Ny, pcol, cubeP)];
M = makehgtform('translate',[0.5 0 0])*makehgtform('yrotate',pi/2);
rotate_and_translate_wall(h,M);
% back face
h = [h ut_wall([], Nx,Ny, pcol, cubeP)];
M = makehgtform('translate',[-0.5 0 0])*makehgtform('yrotate',pi/2);
rotate_and_translate_wall(h(end),M);
% right face
h = [h ut_wall([], Nx,Ny, pcol, cubeP)];
M = makehgtform('translate',[0 0.5 0])*makehgtform('xrotate',pi/2);
rotate_and_translate_wall(h(end),M);
% left face
h = [h ut_wall([], Nx,Ny, pcol, cubeP)];
M = makehgtform('translate',[0 -0.5 0])*makehgtform('xrotate',pi/2);
rotate_and_translate_wall(h(end),M);
% up face
h = [h ut_wall([], Nx,Ny, pcol, cubeP)];
M = makehgtform('translate',[0 0 0.5]);
rotate_and_translate_wall(h(end),M);
 % down face
h = [h ut_wall([], Nx,Ny, pcol, cubeP)];
M = makehgtform('translate',[0 0 -0.5]);
rotate_and_translate_wall(h(end),M);


if ~isempty(hg)
    for i=1:6
        set(h(i),'Parent',hg);
    end
end
end

function rotate_and_translate_wall(h,M)
X = get(h,'Xdata');
Y = get(h,'Ydata');
Z = get(h,'Zdata');
Nb = length(X(:));
[Nx,Ny] = size(X);
Xh = [X(:)'; Y(:)'; Z(:)'; ones(1,Nb)];
Xh = M*Xh;
Xh(1,:) = Xh(1,:)./Xh(4,:);
Xh(2,:) = Xh(2,:)./Xh(4,:);
Xh(3,:) = Xh(3,:)./Xh(4,:);
Xh(4,:) = [];
Xh=reshape(Xh',Nx,Ny,3);
set(h,'Xdata',Xh(:,:,1));
set(h,'Ydata',Xh(:,:,2));
set(h,'Zdata',Xh(:,:,3));
end



