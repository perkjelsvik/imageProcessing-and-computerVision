function [diameters,success]=get_diameters(im,sigma,op)
% [diameters,success]=get_diameters(im,sigma,op)
%
% Estimation of the diameter of a horizontally aligned blood vessel
% INPUT:
% im:           input intensity image
% sigma:        gaussian width of the applied filters in the edge detector
% op:           edge operator. 'm' : marrhildreth, |'c'| : canny
% OUTPUT:
% diameters     array with for each column in the image, the estimated diameter
% success:      flag to indicate successful estimation. 'true' (1): success
%
% Ecample:
%   im = im_bloodvessel(2);                 % simulation of an artery with 2 mm diameters
%   [diam,suc] = get_diameters(im,3,'m');   % sigma=3 performed with Marr-Hildreth operator 

M = size(im,2);
success = 1;

[nrow, ~] = size(im);
imedge = ut_edge(im,op,'s',sigma,'h',[2/nrow 1.5/nrow]);
% [c,r] = find(imedge);
% figure(1); hold off; imshow(im,[]); hold on; plot(r,c,'r.'); drawnow

diameters = zeros(M,1);
for c=1:M
    r = find(imedge(:,c));
    r = r - nrow/2;
    indpos = find(r>0);
    indneg = find(r<0);
    if size(indpos,1)~=1 || size(indneg,1)~=1
        success = 0;
        diameters = [];
        return
    end
    diameters(c) = r(indpos(1)) - r(indneg(1));
end
% figure(2); hold off; plot(diam,'y'); hold on;

end
        
