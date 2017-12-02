%use different newton's method to solve problem 3

%load the data
load('x_0.mat');
load('x_1.mat');
load('A_m=30_n=100.mat');
load('b.mat');

%the first newton's method
alpha = 0.001;
beta = 0.8;
eta = 1e-10;

x = x_0;
[grad, hess] = grad_obj_p3(x);
fval = obj_p3(x);

count = 0;
disp('可行牛顿迭代')
f_cum1 = fval;
while 1 > 0,
    %solve the delta_x
    [ma,na] = size(A);
    %solve the KKT system by elimination and cholesky
    [delta_x, dual] = solveKKT(hess, A, grad, zeros(ma,1));
    nt_dec = 1/2 * delta_x' * hess * delta_x;
    if nt_dec < eta,
        break;
    end
    [fval,x] = backtrackingLS(@obj_p3,grad,x,delta_x,alpha, beta);
    [grad,hess] = grad_obj_p3(x);
    f_cum1 = [f_cum1,fval];
    count = count + 1
end

disp('the result of the newton method')
fval
count

%the second newton's method
alpha = 0.001;
beta = 0.8;
eta = 1e-10;

[ma,na] = size(A);
x = x_1;
v = zeros(ma,1);
[grad, hess] = grad_obj_p3(x);
fval = obj_p3(x);

count = 0;
disp('不可行牛顿迭代')
res = 1;
f_cum2 = fval;
while res > eta,
    %solve the delta_x
    g = grad + A' * v;
    h = A * x - b;
    l = [g;h];
    res = norm(l,2);
    [delta_x, delta_v] = solveKKT(hess, A, g, h);
    %backtracking line search
    t = 1;
    while 1>0,
        [grad_p,hess_p] = grad_obj_p3(x + t * delta_x);
        g_p = grad_p + A' * (v + t * delta_v);
        h_p = A * (x + t * delta_x) - b;
        l_p = [g_p;h_p];
        if norm(l_p,2) > (1-alpha * t) * res,
            t = t * beta;
        else
            break;
        end
    end
    x = x + t * delta_x;
    v = v + t * delta_v;
    [grad,hess] = grad_obj_p3(x);
    fval = obj_p3(x);
    f_cum2 = [f_cum2,fval];
    count = count + 1
end

fval = obj_p3(x);

disp('the result of the newton method')
fval
count

figure
semilogy(f_cum1 - f_cum1(end), 'g')
hold on
semilogy(f_cum2 - f_cum2(end), 'r')
legend('可行牛顿迭代','不可行牛顿迭代')
xlabel('迭代次数')
title('与最优值对数误差')
