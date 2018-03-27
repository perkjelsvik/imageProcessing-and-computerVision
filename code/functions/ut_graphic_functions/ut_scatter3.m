function hall = ut_scatter3(points,color,R)
%% UT_SCATTER3 shows a 3D scatter diagram using 3D spheres instead of marks
% syntax: hall = ut_scatter3(points,color,R)
% points:   a 3xK array containing K 3D points
% color:    the color specification (red,green, and blue)
% R:        the radius of the spheres
% hall:     the handle to a hgtransform object which is the parent of all spheres
% SEE: hgtransform, ut_superquadric

K = size(points,2);

p.ambientstrength = 0.5;
p.facealpha = 1;
p.facelighting = 'phong';
p.facecolor = 'interp';
hold on

hall = hgtransform;
for k=1:K
    h(k) = hgtransform;
    set(h(k),'Parent',hall);
    
    ut_superquadric(h(k),50,50,R,2,color,p);
    M=makehgtform('translate',points(:,k));
    set(h(k),'matrix',M);
end




