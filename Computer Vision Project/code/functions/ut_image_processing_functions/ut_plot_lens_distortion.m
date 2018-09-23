function ut_plot_lens_distortion(cameraParams,imsize)
% ut_plot_lens_distortion(camparameters,ny,nx)
% camparameters:    object of class cameraParameters
% imsize:           image size: [nrow, ncol] 
%
% A script to run in conjunction with computer vision toolbox to plot the distortion models.
%
% This is a slightly modified version of the script plot_CCT_distortion.m written by Mr. Oshel
% Thank you Mr. Oshel for your contribution!


K = cameraParams.IntrinsicMatrix';
k = cameraParams.RadialDistortion;
if length(k)==2, k(3)=0; end
if cameraParams.EstimateTangentialDistortion, k(4:5) = cameraParams.TangentialDistortion; else k(4:5)=0; end
nx = imsize(2);
ny = imsize(1);


[mx,my] = meshgrid(0:nx/20:(nx-1),0:ny/20:(ny-1));
[nnx,nny]=size(mx);
px=reshape(mx',nnx*nny,1);
py=reshape(my',nnx*nny,1);
rays=inv(K)*[px';py';ones(1,length(px))];
x=[rays(1,:)./rays(3,:);rays(2,:)./rays(3,:)];


title2=strcat('Complete Distortion Model');


figure;

% radial distortion
r2 = x(1,:).^2 + x(2,:).^2;
r4 = r2.^2;
r6 = r2.^3;
cdist = 1 + k(1) * r2 + k(2) * r4 + k(3) * r6;
xd1 = x .* (ones(2,1)*cdist);

% tangential distortion:
a1 = 2.*x(1,:).*x(2,:);
a2 = r2 + 2*x(1,:).^2;
a3 = r2 + 2*x(2,:).^2;
delta_x = [k(4)*a1 + k(5)*a2 ;    k(4) * a3 + k(5)*a1];
xd = xd1 + delta_x;
xdh = [xd; ones(1,nnx*nny)];
p2 = K*xdh;
px2 = p2(1,:)./p2(3,:);
py2 = p2(2,:)./p2(3,:);
dx=px2'-px;
dy=py2'-py;
Q=quiver(px+1,py+1,dx,dy);
hold on;
plot(K(1,3),K(2,3),'o');
plot((nx-1)/2+1,(ny-1)/2+1,'x');
dr=reshape(sqrt((dx.*dx)+(dy.*dy)),nny,nnx)';
[C,h]=contour(mx,my,dr,0.5:0.5:10,'k');
if isempty(C)
    [C,h]=contour(mx,my,dr,0.05:0.01:0.5,'k');
end
clabel(C,h);
title(title2);

axis ij;
axis([1 nx 1 ny])
axis equal;
axis tight;

position=get(gca,'Position');
shr = 0.9;
position(1)=position(1)+position(3)*((1-shr)/2);
position(2)=position(2)+position(4)*(1-shr)+0.03;
position(3:4)=position(3:4)*shr;
set(gca,'position',position);
set(gca,'fontsize',8,'fontname','clean')

line1=sprintf('Principal Point               = (%0.6g, %0.6g)',K(1,3),K(2,3));
line2=sprintf('Focal Length                 = (%0.6g, %0.6g)',K(1,1),K(2,2));
line3=sprintf('Radial coefficients         = (%0.4g, %0.4g, %0.4g)',k(1),k(2),k(3));
line4=sprintf('Tangential coefficients  = (%0.4g, %0.4g)',k(4),k(5));
line10=sprintf('Skew                              = %0.4g',K(1,2));


axes('position',[0 0 1 1],'visible','off');
th=text(0.11,0,{line2,line1,line10,line3,line4},'horizontalalignment','left','verticalalignment','bottom','fontsize',8,'fontname','clean');
hold off

