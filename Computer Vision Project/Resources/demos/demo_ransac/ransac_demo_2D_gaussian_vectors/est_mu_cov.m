function [par, not_ok] = est_mu_cov(x)


estmu = mean(x')';
estcov = cov(x');

D = size(x,1);
par = zeros(D,D+1);
par(:,1) = estmu;
par(:,2:end) = estcov;
not_ok = (length(x)<5);