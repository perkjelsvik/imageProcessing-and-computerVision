function [Iout]=ut_levelx(varargin)
%ut_levelx  finding level crossings
%
%   IOUT=UT_LEVELX(IN,LEVEL) outputs a map of the input image IN that
%   indicates the positions where the gray levels cross the level LEVEL.
%   The contour, thus obtained, is 8 connected. The input image must be an
%   intensity image. The function is used in UT_EDGE for zero crossing
%   detection.
%
%   Default: LEVEL=0.
%
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   Laboratory for Measurements and Instrumentation
%   University of Twente, the Netherlands
%   Version 1.0, date: 27-10-2004
%
%   See also UT_EDGE, IMCONTOUR.

[Iin,level] =  ParseInputs(varargin{:});

[m,n,~]=size(Iin);

% pad image with border and replicate pixels:
b = zeros(m+2,n+2);
b(1+(1:m),1+(1:n)) = Iin;
b(1+(1:m),1) = b(1+(1:m),2);
b(1+(1:m),end) = b(1+(1:m),end-1);
b(1,1+(1:n)) = b(2,1+(1:n));
b(end,1+(1:n)) = b(end-1,1+(1:n));
b(1,1) = b(2,2);
b(1,end) = b(2,end-1);
b(end,1) = b(end-1,2);
b(end,end) = b(end-1,end-1);
n = n+2;
m = m+2;
Iout = zeros(size(b));

% level crossings in row direction
b = b-level;
a = circshift(b,[-1 0]);
c = circshift(b,[+1 0]);
ind = find(a.*b<0);
ac = a(ind);
bc = b(ind);
ind = ind + double(abs(bc)>=abs(ac));
ind = mod(ind-1,n*m)+1;
Iout(ind) = 1;
ind = (a.*b>=0) & (b==0) & (a.*c<0);
Iout(ind) = 1;

% level crossings in column direction
a = circshift(b,[0 -1]);
c = circshift(b,[0 +1]);
ind = find(a.*b<0);
ac = a(ind);
bc = b(ind);
ind = ind + double(abs(bc)>=abs(ac))*m;
ind = mod(ind-1,n*m)+1;
Iout(ind) = 1;
ind = (a.*b>=0) & (b==0) & (a.*c<0);
Iout(ind) = 1;

% crop border:
Iout = Iout(2:end-1,2:end-1);



%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [Iin,level] =  ParseInputs(varargin)

narginchk(1,2);
%MSG = NARGCHK(LOW,HIGH,N) returns an appropriate error message if
%    N is not between low and high. If it is, return empty matrix.

Iin = double(varargin{1});

%defaults
level=0;

if nargin==2
      level=varargin{2};
end
   
