function [Iout]=ut_edge(varargin)
%ut_edge	Marr-Hilderth and Canny edge detectors
%
%   Iout = UT_EDGE(Iin) finds the possible edges in image Iin using an
%   implementation of the Canny edge detector. The derivatives are
%   calculated from a 2-D Gaussian function implemented with UT_GAUSS.
%   The localization is done by finding the zero-crossings of the second
%   directional derivatives (instead of directional maximum suppression
%   such as implemented by EDGE from the image processing toolbox). The
%   sigma (standard deviation) of the Gaussian  filtering is set to 2.
%   Iout is a 2-dimensional array with the same size as Iin. The no-edge
%   pixels are indicated in Iout as zeroes. Edge pixels carries the edge
%   strength as grey level. The edge strength is scaled between 0 and 1.
%
%   Iout = UT_EDGE(Iin,...,OPTION,OPTIONVAL,...) finds the possible edges
%   with some options switched on, and with parameter(s) set to OPTIONVAL.
%   The  following options are available:
%
%   'marrhildreth' or 'm':  Perform Marr-Hildreth operation, i.e. Laplacian
%                           of Gaussian, rather than Canny operation.
%   'canny' or 'c':         Perform Canny operation (default).
%   'sigma' or 's':         The width (standard deviation) of the Gaussian
%                           filtering is set to OPTIONVAL (default: 2)
%   'threshold' or 't':     Return a binary (logical) edge map instead of edge
%                           strengths. The edges are detected by
%                           thresholding it at OPTIONVAL. If OPTIONVAL is
%                           omitted, the default of the threshold is 0.1.
%   'hysteresis' or 'h':    Return a binary (logical) edge map instead of edge
%                           strengths. The edge are detected by hysteresis
%                           thresholding. Two thresholds are applied. The
%                           edges detected with the higher thresholds form
%                           the seed that is propagated in the edge
%                           segments obtained by thresholding with the
%                           lower threshold. OPTIONVAL is a two-element
%                           vector. The first element specifies the
%                           fraction of pixels that will be assigned to
%                           candidate edges (detected with the lower
%                           threshold). The second element is the fraction
%                           of pixels that will be assigned to seed edges
%                           (detected with the higher threshold). If
%                           OPTIONVAL is omitted, the default of [0.1 0.03]
%                           is assumed. If OPTIONVAL is a scalar, then the
%                           default assignment to the second element is
%                           0.3*OPTIONVAL.
%
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   Laboratory for Measurements and Instrumentation
%   University of Twente, the Netherlands
%   Version 1.3, date: 21-02-2018
%
%   See also UT_GAUSS, EDGE.

[Iin,sigma,operator,threshold_method,thres_parm]=ParseInputs(varargin{:});

grad=(ut_gauss(Iin,sigma,1,0).^2+ut_gauss(Iin,sigma,0,1).^2).^0.5;
grad=grad/max(grad(:));

if strcmp(operator,'marrhildreth')
    lap=ut_gauss(Iin,sigma,2,0)+ut_gauss(Iin,sigma,0,2);
    zerocross=ut_levelx(lap,0.0);
    Iout=grad.*zerocross;
end

if strcmp(operator,'canny')
    SDGD=ut_gauss(Iin,sigma,1,0).^2.*ut_gauss(Iin,sigma,2,0)+ ...
        2*ut_gauss(Iin,sigma,1,0).*ut_gauss(Iin,sigma,0,1).*ut_gauss(Iin,sigma,1,1)+...
        ut_gauss(Iin,sigma,0,1).^2.*ut_gauss(Iin,sigma,0,2);
    zerocross=ut_levelx(SDGD,0.0);
    Iout=grad.*zerocross;
end

if strcmp(threshold_method,'threshold')
    Iout = logical(Iout>thres_parm(1));
end

if strcmp(threshold_method,'hysteresis')
    Iout_sorted = sort(Iout(:));
    thres_parm(1) = Iout_sorted(max(floor((1-thres_parm(1))*numel(Iout)),1));
    thres_parm(2) = Iout_sorted(max(floor((1-thres_parm(2))*numel(Iout)),1));
    Iout_mask = Iout>thres_parm(1);
    Iout_marker = Iout>thres_parm(2);
    Iout=imreconstruct(Iout_marker,Iout_mask);
end



%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [Iin,Sigma,operator,threshold_method,thres_parm] =  ParseInputs(varargin)

narginchk(1,30);


Iin = double(varargin{1});
if ndims(Iin)~=2
    error('Iin must be a 2-dimensional array');
end

%defaults
Sigma=2;
operator = 'canny';
threshold_method = 'none';
thres_parm = [0.1, 0.03];

options = {'canny','c','marrhildreth','m','threshold','t','hysteresis','h','sigma','s'};

if nargin>1
    for k=2:length(varargin)
        if ischar(varargin{k})
            string = lower(varargin{k});
            j = strmatch(string,options,'exact');
            if isempty(j)
                error(['Invalid input string: ''' varargin{k} '''.']);
            end
            switch string
                case {'canny','c','marrhildreth','m'}
                    if strcmp(string,'m'), string = 'marrhildreth'; end;
                    if strcmp(string,'c'), string = 'canny'; end;
                    operator = string;
                case {'sigma','s'}
                    if nargin>k & isnumeric(varargin{k+1})
                        Sigma = varargin{k+1};
                        k=k+1;
                    end
                case {'threshold','t'}
                    threshold_method = 'threshold';
                    thres_parm = [0.1 0.03];
                    if nargin>k & isnumeric(varargin{k+1})
                        thres_parm(1) = varargin{k+1};
                        k=k+1;
                    end
                case {'hysteresis','h'}
                    threshold_method = 'hysteresis';
                    thres_parm = [0.1 0.03];
                    if nargin>k & isnumeric(varargin{k+1})
                        thres_parm = varargin{k+1};
                        if length(thres_parm)==1
                            thres_parm(2) =  0.3*thres_parm(1);
                        end
                        k=k+1;
                    end
            end
        end
    end
end

if Sigma<0
    error('Sigma must be positive');
end

if strcmp(threshold_method , 'hysteresis')
    if thres_parm(1)<0 | thres_parm(1)>1 | thres_parm(2)<0 | thres_parm(2)>1
        error('hysteresis: threshold parameters out of range');
    end
    if thres_parm(2)>thres_parm(1)
        error('hysteresis: the second threshold must be less than the first');
    end
end

