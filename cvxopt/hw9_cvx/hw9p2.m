%use diffent method to solve the problem 2

%load the matrices as global variables
global Am;

%the first matrix
temp = load('m=50_n=50.mat');
Am = temp.A;

alpha = 0.3;
beta = 0.8;

s = size(Am);
eps = 1e-8;

%use the newton's method
x = zeros(s(1),1);
[grad, hess] = grad_obj_p2(x);
fval = obj_p2(x);

count = 0;
disp('the first matrix')
t_1 = zeros(1,0);
f_1 = fval;
while norm(grad,2) > eps,
    [delta_x,L] = lineqsol(hess, -grad);
    [fval,x,t] = backtrackingLS(@obj_p2,grad,x,delta_x,alpha, beta);
    [grad,hess] = grad_obj_p2(x);
    t_1 = [t_1,t];
    f_1 = [f_1,fval];
    count = count + 1
end

disp('the result of the newton method')
fval
count

%the second matrix
temp = load('m=100_n=100.mat');
Am = temp.A;

s = size(Am);

%use the newtom's method
x = zeros(s(1),1);
%use the L1 norm
[grad, hess] = grad_obj_p2(x);
fval = obj_p2(x);

count = 0;
disp('the second matrix')
t_2 = zeros(1,0);
f_2 = fval;
while norm(grad,2) > eps,
    delta_x = lineqsol(hess, -grad);
    [fval,x] = backtrackingLS(@obj_p2,grad,x,delta_x,alpha, beta);
    [grad,hess] = grad_obj_p2(x);
    t_2 = [t_2,t];
    f_2 = [f_2,fval];
    count = count + 1;
end

disp('the result of newton method')
fval
count

%log of the error
figure
semilogy(f_1 - f_1(end), 'm')
hold on
semilogy(f_2 - f_2(end), 'g')
legend('50*50','100*100')
xlabel('迭代次数')
title('与最优值的对数误差')

%steps
figure
plot(t_1, 'm')
hold on
plot(t_2, 'g')
legend('50*50','100*100')
xlabel('迭代次数')
title('步长')