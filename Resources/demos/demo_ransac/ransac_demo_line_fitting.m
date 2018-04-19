function ransac_demo_line_fitting
%% demo ransac: line fitting
clear all
close all
% global x

%% generate the data 
x = (1:20)';
p = 1;
S = 0.05;

% the linear model
y = p + S * randn(size(x));

% the outliers
y(end-9:end) = y(end-9:end) - 1;
y = y(randperm(20));

% and plot
figure;
plot(x,y,'r.','markersize',10); hold on; 

%% naive robust estimation
[pest, ind] = iterative_mean(y);
hold on;
plot(x,pest+0*x,'linewidth',2);
plot(x(ind),y(ind),'bo');

%% ransac
[pest, inliers, ntrial] = ...
        ut_ransac(y', @estimator, 3, @absdiff, 3*S, @consistency, 0.1);
plot(x(inliers),pest+0*x(inliers),'k');
plot(x(inliers),y(inliers),'k+');

% find the second cluster
[y,i] = setdiff(y,y(inliers));
x = x(i);
[pest, inliers, ntrial] = ...
        ut_ransac(y', @estimator, 3, @absdiff, 3*S, @consistency, 0.5);
plot(x,pest+0*x,'g');
plot(x(inliers),y(inliers),'g+');
    
    






function [pest, x] = iterative_mean(y)
tol = 0.6;
x = 1:length(y);

pest = mean(y);                                 % first estimate of mean
while true
    if sum(abs(pest-y)>=tol)==0, break; end     % if all samples are within a tolerance: exit
    ind = find(abs(pest-y)<tol);                % find the samples that are within a tolerance
    y = y(ind);                                 % select those samples
    x = x(ind);                                 % and corresponding x values
    pest = mean(y);                             % re-estimate mean
end
return


function [pest, not_ok] = estimator(y)
pest = mean(y);
not_ok = false;
        
function dist = absdiff(pest,y)
dist = abs(pest-y);
return

function ok = consistency(pest,y,~)
ok = (length(y)>=6);
return

