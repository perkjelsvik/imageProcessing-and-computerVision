function h = ut_draw_camera(K,pixsize,R,T,col,camlabel,axlength)
% h = ut_draw_camera(K,pixsize,R,T,col,camlabel,axlength) 
% draws a camera in the current axis with the following properties:
% K:        camera calibration matrix
% pixsize:  size of a pixel (square pixels are assumed)
% R:        wRc: orientation of camera
% T:        wtc: position of camera
% col:      color
% camlabel: list of 6 strings added to:
%           - focal point
%           - image axes
%           - camera coordinate axes
% axlength: length of the axes
%
% h:        handle to hgtransform of the object        


h = hgtransform('parent',gca);
P.facealpha = 0.8;
K = K*pixsize;

% draw the focus
hf = ut_superquadric(h,50,50,0.1*K(1,3),2,col,P);
ht = text(0,0,0,camlabel{1},'interpreter','latex','fontsize',12);
set(ht,'parent',h);

% draw the image plane
himplane = hgtransform('parent',h);
hfoo= ut_wall(himplane,21,21,col,P);
P.facealpha = 1;
ut_arrow3(himplane,[-0.5, -0.5, 0],[ 0.6, -0.5, 0],0.025,[0 0 0],0.1,0.05,[0 0 0],1,P);
ht =text(0.5,-0.5,0,camlabel{2},'interpreter','latex','fontsize',12,'color',[1 0 0]);
set(ht,'parent',himplane);
ut_arrow3(himplane,[-0.5, -0.5, 0],[-0.5,  0.6, 0],0.025,[0 0 0],0.1,0.05,[0 0 0],1,P);
ht =text(-0.5,0.5,0,camlabel{3},'interpreter','latex','fontsize',12,'color',[1 0 0]);
set(ht,'parent',himplane);
M = makehgtform('translate',[0 0 K(1,1)])* makehgtform('xrotate',0*pi/2)*makehgtform('scale',[2*K(1,3);2*K(2,3);2*K(1,3)]);
set(himplane,'matrix',M);
set(himplane,'parent',h);

% draw the optical axis
ha = plot3([0 0],[0 0],[0 K(1,1)],'k','linewidth',0.5);
set(ha,'parent',h);

% draw axis
P.facealpha = 1;
linewidth = 0.1*axlength;
arrowlength = 0.3*axlength;
arrowwidth = 0.2*axlength;
hx = ut_arrow3(h,[0 0 0],[axlength 0 0],linewidth,[1 0.5 0.5],arrowlength,arrowwidth,[1 0.5 0.5],1,P);
hy = ut_arrow3(h,[0 0 0],[0 axlength 0],linewidth,[1 0.5 0.5],arrowlength,arrowwidth,[1 0.5 0.5],1,P);
hz = ut_arrow3(h,[0 0 0],[0 0 axlength],linewidth,[1 0.5 0.5],arrowlength,arrowwidth,[1 0.5 0.5],1,P);
hL(1) = text(axlength, 0, 0, camlabel{4},'interpreter','latex','fontsize',10,'color',[1 0 0]);
hL(2) = text(0, axlength, 0, camlabel{5},'interpreter','latex','fontsize',10,'color',[1 0 0]);
hL(3) = text(0, 0, axlength, camlabel{6},'interpreter','latex','fontsize',10,'color',[1 0 0]);
set(hL,'parent',h)


M = [R T;[0 0 0 1]];
set(h,'matrix',M);
end

