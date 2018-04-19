clear variable
close all

% generate 100 2D samples 30% from one distribution, and 70% from another
% distribution:
figure(1)
generate_data;

%% naive estimation
% estimate the parameters
xin = x;
mu = mean(xin,2);
C  = cov(xin');
figure(2);
colors = {'bo','go','ko','mo','yo','bo','go','ko','mo','yo'};
plot(xin(1,:),xin(2,:),'ro'); hold on;
ut_plotcov(mu,C,'r');
axis equal
for i=1:10                                                  % iterate a number of times
    dis = sum(((x-mu*ones(1,size(x,2))).*(inv(C)*(x-mu*ones(1,size(x,2))))).^2);   
                                                            % calculate distance to model
    ind = find(dis<9);                                      % find indices of inliers
    xin = x(:,ind);                                         % remove outliers
    mu = mean(xin,2);                                       % re-estimate mean
    C  = cov(xin');                                         % re-estimate cov
    plot(xin(1,:),xin(2,:),colors{i});                      % plot
    ut_plotcov(mu,C,colors{i}(1));
    axis equal
    title(['#inliers: ' num2str(length(ind))])
end


%% ransac
figure(1);
[M, inliers, ntrial] = ut_ransac(x, @est_mu_cov, 10, @distest, 9, @consistencycheck, 0.3);
% est_mu_cov:   function that estimates the mean vector and the covariance matrix
% distest:      function that find the distances of samples to the find distribution
% consistencycheck: function that checks whether the solution is consistent
%                   that is, whether the inliers support the assumption
%                   that they are from one distribution

plot(x(1,inliers),x(2,inliers),'r.');
hold on
% ind_false_accepted = intersect(ind2,inliers');
% ind_missed = setdiff(ind1,inliers');
% plot(x(1,ind_missed),x(2,ind_missed),'gx');
% plot(x(1,ind_false_accepted),x(2,ind_false_accepted),'kx');
ind_trueneg = setdiff([ind1' ind2],inliers');
plot(x(1,ind_trueneg),x(2,ind_trueneg),'b.');

mu = M(:,1);
covmat = M(:,2:end);
ut_plotcov(mu,covmat,'g');
axis equal
    title(['#inliers: ' num2str(length(inliers))])

disp(['number of trials: ' num2str(ntrial)])