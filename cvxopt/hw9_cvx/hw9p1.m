%use newton's method to solve the problem 1
x = [0;0];
eps = 1e-8;
el_eps = 0.0000000001;


[grad, hess] = grad_obj_p1(x);
fval = obj_p1(x);

%the parameters for the backtracking line search
alpha = 0.01;
beta = 0.3;

count = 0;

x_cum = x;
f_cum = fval;

while norm(grad,2) > eps,
    delta_x = lineqsol(hess, -grad);
    [fval,x] = backtrackingLS(@obj_p1,grad,x,delta_x,alpha, beta);
    [grad,hess] = grad_obj_p1(x);
    x_cum = [x_cum,x];
    f_cum = [f_cum,fval];
    count = count + 1;
end

disp('the result of newton method')
fval
x
count

%plot the process of the optimization
x = -0.5:0.05:1.5;
y = -0.5:0.05:1.5;
[X,Y] = meshgrid(x,y);
Z = (1-X).^2 +2 * (Y-X.^2).^2;

%plot the iteration steps
figure
contour(X,Y,Z)
hold on
plot(x_cum(1,:), x_cum(2,:), 'm')
title('位置－迭代次数')
legend('函数等高线','牛顿迭代')

%plot the value of the function with the nubmer of iterations
figure
plot(f_cum, 'm')
title('函数值－迭代次数')
legend('牛顿迭代')