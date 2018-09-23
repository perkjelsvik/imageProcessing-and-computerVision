function ok=consistencycheck(parm,x,~)

D = size(x,1);
mu = parm(:,1);
C = parm(:,2:end);


% test on normal distribution for the different components of x:
ok = 0;
for i=1:D
    xs = (x(i,:)-mu(i))/sqrt(C(i,i));
    if kstest(xs,[],0.05), return; end;
end
        
ok = 1;
