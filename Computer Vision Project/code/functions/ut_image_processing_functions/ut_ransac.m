function [parm, inliers, ntrial] = ut_ransac(varargin)
% function [parm, inliers, ntrial] = ...
%       ut_ransac(x, estimator, n, errormetric, errortolerance, consistency, w)
%
%   input arguments:
%   x:              DxP array containing P data vectors of dimension D.
%   estimator:      Handle to a function that estimates the parameters from
%                   a subset consisting of n (or more) data vectors
%                   selected from x. The function embodies a parametric
%                   model that should be able to describe the inlying data
%                   vectors.
%   n:              The number of data vectors needed to estimate the
%                   parameters.
%   errormetric:    Handle to a function that calculates an error measure
%                   describing how well a data vector fits the paramtric
%                   model. Based on this measure it is decided whether a
%                   data vector is an inlier w.r.t. the model.
%   errortolerance: The threshold that is applied to the error measure. If
%                   the error measure of a data vector is above this
%                   threshold, the datum is considered as outlying.
%   consistency:    Handle to a function that checks the consistency of the
%                   consensus set. If this check passes succesfully, then
%                   ut_ransac will terminate, returning the parameters of
%                   this data set. If the set is not consistent, a new
%                   sample set is drawn.
%                   Usefull checks might be:
%                   - The number of data vectors in the consensus set must
%                     exceed a threshold (this is used in the original paper
%                     of ransac)
%                   - The residuals of the data set must obey a given
%                     distribution, e.g. a Gaussian distribution.
%                   - The error measures (calculated by errormetric) should
%                     obey a given distribution, e.g. a chisquare
%                     distribution.
%                   - The size of the consensus set should be larger than a
%                     fraction of the size of the dataset.
%   w:              The assumed probability of an inlier. This parameter is
%                   used to determine the maximum number of random
%                   selections. This number is determined according to:
%                       Nmax = round(3*w^-n);
%
%   Output variables:
%   parm:           The parameters found by ut_ransac. If no concensus set
%                   has been found, then parm is empty.
%   inliers:        The set of indices of x that belong to the found
%                   consensus set.
%   ntrial:         The number of trials before getting a consistent set.
%
% The functions estimator, errormetric, consistency should be defined as:
%
%   function parm = estimator(x)   or:
%   function [parm, failed] = estimator(x)
%       (parm is an array containing the parameters to estimate;
%       (failed is a boolean indicating singular behaviour of the estimator)
%   function dist = errormetric(parm,x)
%       (dist is a 1xP array if x is a DxP array)
%   function ok = consisteny(parm,x,P)
%
%   Copyright: F. van der Heijden, F.vanderHeijden@utwente.nl
%   S&S group
%   University of Twente, the Netherlands
%   Version 3.0, date: 14-03-2008
%
% Ref:
%    M.A. Fishler and  R.C. Boles. "Random sample concensus: A paradigm
%    for model fitting with applications to image analysis and automated
%    cartography". Comm. Assoc. Comp, Mach., Vol 24, No 6, pp 381-395, 1981

[x, P, estimator, n, errormetric, errortolerance, consistency, w] ...
    = ParseInputs(varargin{:});

maxtrials = round(3*w^-n);

ntrial = 1;
max_nr_inliers = 0;

while ntrial <= maxtrials

    ind = randsample(P,n);                  % select random n indices
    try
        [parm, failed] = feval(estimator, x(:,ind));  % estimate the parameters;
                                            % use this if the estimator checks for deteriotated cases
    catch
        failed = 0;                         % flag to indicate whether the estimator was succesful (i.e. no deteriotated case)
        parm = feval(estimator, x(:,ind));  % estimate the parameters; use this if there is no deteriotation check
    end
    if ~failed
        dist = feval(errormetric, parm, x); % determine the fit
        inliers = find(dist<errortolerance);% find the consensus set
        max_nr_inliers = max(max_nr_inliers,length(inliers));
%         disp([length(x) length(inliers) max_nr_inliers])
        if feval(consistency, parm, x(:,inliers), size(x,2))
            parm =  feval(estimator, x(:,inliers));  % estimate the parameters
            %         dist = feval(errormetric, parm, x); % determine the fit
            %         inliers = find(dist<errortolerance);% find the consensus set
            %         parm = feval(estimator, x(:,inliers));  % estimate the parameters
            %         dist = feval(errormetric, parm, x); % determine the fit
            return
        end
    end
    ntrial = ntrial+1;
end
parm = [];
inliers = [];




%----------------------------------------------------------------------
% Subfunction ParseInputs
%----------------------------------------------------------------------

function [x, P, estimator, n, errormetric, errortolerance, consistency, w] =  ...
    ParseInputs(varargin)

narginchk(1,7);
%MSG = NARGCHK(LOW,HIGH,N) returns an appropriate error message if
%    N is not between low and high. If it is, return empty matrix.

x = varargin{1};
P = size(x,2);
n = varargin{3};
if n>P
    error('n cannot be larger than P');
end
estimator = varargin{2};
errormetric = varargin{4};
errortolerance = varargin{5};
consistency = varargin{6};
w = varargin{7};

