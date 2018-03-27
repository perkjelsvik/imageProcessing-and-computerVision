function h = ut_plotcov(mu,C,opt)
% UT_PLOTCOV plots an ellipse that is associated with a 2D mean vector MU and
% a 2x2 covariance matrix C.
%
%   UT_PLOTCOV(MU,C) plots an ellipse in the current axis in the current
%   figure. The position of the ellipse is defined by the 2x1 vector MU,
%   which can be regarded as the expectation vector of a normal
%   distribution. The size and shape of the ellipse is defined by the 2x2
%   covariance matrix C. The ellipse is defined by the equation
%   x*inv(C)*x'=1.
%
%   UT_PLOTCOV(MU,C,OPT) can be used to change the colour of the ellipse. A
%   valid option is, for instance, 'g', 'b', and so on, as in PLOT. The
%   default colour is 'r'.
%   
%   h = UT_PLOTCOV(..) returns a handle to the ellipse.
%
%   See also PLOT

if nargin==2, opt='r-'; end
[E,L] = eig(C);
nPoints = 100;
w=0:2*pi/nPoints:2*pi;
nPoints=length(w);
rCircle=1*[cos(w);sin(w)];  %circle
A=E*L^0.5;
rPlot=A*rCircle+mu*ones(1,nPoints);
h = plot(rPlot(1,:),rPlot(2,:),opt,'LineWidth',2'); 
end
