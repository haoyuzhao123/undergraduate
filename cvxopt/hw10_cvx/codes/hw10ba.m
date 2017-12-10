%load the global variables
load('A.mat')
load('b.mat')
load('lambda.mat')
load('mu.mat')
load('P.mat')
load('q.mat')
load('x_0.mat')

%load the size of the equality constriants
[n,m] = size(A);

%the newton's method parameters
alpha = 0.001;
beta = 0.3;
eta = 1e-10;

%interior point method parameter
t_int = 1;
mu_ba = 20;
epsilon = 1e-10;

%begin the barrier interior point method
t = t_int;
x_ba = x_0;
count_cum = 0;

gap_cum = zeros(1,0);
while m / t > epsilon / mu_ba,
    x_nt = x_ba;
    v = zeros(n,1);
    
    %begin the newton's method
    [grad,hess] = grad_barrier(x_nt);
    grad = grad + t * (P * x_nt + q);
    hess = hess + t * P;
    count = 0;
    while 1 > 0,
        %solve the KKT system by elimination and cholesky
        g = grad + A' * v;
        h = A * x_nt - b;
        l = [g;h];
        res = norm(l,2);
        fprintf('res = %f\n', res);
        if res < t * eta,
            break;
        end
        %disp(sprintf('the current res is: %f', res))
        [delta_x, delta_v] = solveKKT(hess, A, g, h);
        
        %backtracking line search in newton's method
        step = 1;
        
        while 1>0,
            x_ntp = x_nt + step * delta_x;
            [grad_p,hess_p] = grad_barrier(x_ntp);
            grad_p = grad_p + t * (P * x_ntp + q);
            hess_p = hess_p + t * P;
            g_p = grad_p + A' * (v + step * delta_v);
            h_p = A * (x_nt + step * delta_x) - b;
            l_p = [g_p;h_p];
            if sum(x_ntp < 0) > 0,
                step = step * beta;
            elseif norm(l_p,2) > (1-alpha * step) * res,
                step = step * beta;
            else
                break;
            end
        end
        x_nt = x_nt + step * delta_x;
        v = v + step * delta_v;
        [grad,hess] = grad_barrier(x_nt);
        grad = grad + t * (P * x_nt + q);
        hess = hess + t * P;
        fval = (1/2 * x_nt' * P * x_nt + q' * x_nt);
        fprintf('step = %f, fval = %f \n', step,fval)
        count = count + 1;
        gap_cum = [gap_cum, m / t];
    end
    count_cum = count_cum + count;
    t = t * mu_ba;
    x_ba = x_nt;
end

t = t / mu_ba;

lambda_ba = 1 ./ (t * x_ba);
mu_ba = v / t;
p_ba = fval;

fprintf('fval = %f, count_cum = %d \n', fval, count_cum)

%plot the result
figure
semilogy(gap_cum, 'r');
legend('pri-dual gap')
xlabel('迭代次数')
title('对偶间隙与迭代次数')

%save the results
save('x_ba.mat','x_ba')
save('lambda_ba.mat','lambda_ba')
save('mu_ba.mat','mu_ba')
save('p_ba','p_ba')