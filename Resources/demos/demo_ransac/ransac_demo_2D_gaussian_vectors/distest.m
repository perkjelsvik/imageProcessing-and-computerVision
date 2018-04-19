function dist = distest(par, x)



mu = par(:,1);
C = par(:,2:end);

N = size(x,2);
D = size(x,1);

res = x - mu*ones(1,N);
Cinv = inv(C);
dist = sum(res .* (Cinv * res));

