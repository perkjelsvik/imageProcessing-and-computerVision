% generate data for testing ransac.m

N=100;      % number of samples
w=0.7;      % probability that a sample is within a consistent model M1
D=2;        % dimension of the samples

mu1 = [5;5];    % expectation of model M1
mu2 = [-5;0];    % expectation of model M2
C1 = [1     0.0;
    0.0    1]; % covmat of model M1
C2 = [20    -0.25;
    -0.25   20]; % covmat of model M2

ind1 = randsample(N,round(w*N));    % indices for model M1
ind2 = setdiff(1:N,ind1);           % indices for model M2
N1 = length(ind1);
N2 = length(ind2);

x = zeros(D,N);
x(:,ind1) = mu1*ones(1,N1) + C1^0.5 * randn(D,N1);
x(:,ind2) = mu2*ones(1,N2) + C2^0.5 * randn(D,N2);

plot(x(1,ind1),x(2,ind1),'ro');
hold on;
plot(x(1,ind2),x(2,ind2),'bo');

