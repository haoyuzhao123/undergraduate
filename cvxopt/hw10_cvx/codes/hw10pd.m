%load the global variables
load('A.mat')
load('b.mat')
load('lambda.mat')
load('mu.mat')
load('P.mat')
load('q.mat')
load('x_0.mat')

%the parameters for the interior point method
epsilon = 1e-10;
beta = 0.8;
[n,m] = size(A);

x = x_0;
l = lambda;
v = mu;
mu_int = 2;
count = 0;

%for the plots
eta_cum = zeros(1,0);
norm_cum = zeros(1,0);

while 1 > 0,
    eta = l' * x;
    eta_cum = [eta_cum,eta];
    t = mu_int * m / eta;
    r_dual = q + P * x - l + A' * v;
    r_cent = diag(l) * x - (1 / t) * ones(m,1);
    r_pri = A * x - b;
    norm_cum = [norm_cum, norm([r_dual;r_pri],2)];
    fprintf('the r_dual is: %f, the r_pri is: %f, the eta is: %f \n',...
        norm(r_dual,2), norm(r_pri,2), eta)
    if norm(r_dual,2) < epsilon && norm(r_pri,2) < epsilon && eta < epsilon,
        break;
    end 
    r = [r_dual;r_cent;r_pri];
    dir_mat = [P, -eye(200), A';
        diag(l), diag(x), zeros(200,100);
        A, zeros(100,200),zeros(100,100)];
    dy = -inv(dir_mat) * r;
    [dx, dl, dv] = partition(dy);
    
    %backtracking line search
    step = 1;
    while sum(x + step * dx < 0) > 0 ||  sum(l + step * dl < 0) > 0,
        step = step * beta;
    end
    
    step = step * 0.99;
    x = x + step * dx;
    l = l + step * dl;
    v = v + step * dv;
    
    count = count + 1;
end

fval = 1 / 2 * x' * P * x + q' * x;
fprintf('the fval is: %f, and the count num is: %d\n', fval, count)

x_pd = x;
lambda_pd = l;
mu_pd = v;
p_pd = fval;

%plot
figure
semilogy(eta_cum, 'g')
hold on
semilogy(norm_cum, 'r')
legend('eta','norm')
xlabel('迭代次数')
title('eta-norm-迭代次数的关系')

%save the results
save('x_pd.mat','x_pd')
save('lambda_pd.mat','lambda_pd')
save('mu_pd.mat','mu_pd')
save('p_pd.mat','p_pd')