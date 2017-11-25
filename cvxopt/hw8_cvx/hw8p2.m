%use diffent method to solve the problem 2
x = [0;0];
eps = 1e-8;
el_eps = 0.0000000001;

%use the L1 norm
grad = grad_obj_p2(x);
fval = obj_p2(x);

count = 0;
x_cum = x;
f_l1 = fval;
while norm(grad,2) > eps,
    delta_x = [0;0];
    n = norm(grad,'inf');
    if abs(abs(grad(1)) - n) < eps,
        delta_x(1) = sign(-grad(1));
    else
        delta_x(2) = sign(-grad(2));
    end
    [fval,x] = exactLS(@obj_p2,grad,x,delta_x,el_eps);
    x_cum = [x_cum, x];
    f_l1 = [f_l1, fval];
    grad = grad_obj_p2(x);
    count = count + 1;
end

x_l1 = x_cum;

disp('the result of L1')
fval
x
count

%use the L2 norm
x = [0;0];
grad = grad_obj_p2(x);
fval = obj_p2(x);

count = 0;
x_cum = x;
f_l2 = fval;
while norm(grad,2) > eps,
    n = norm(grad,2);
    delta_x = - grad / n;
    [fval,x] = exactLS(@obj_p2,grad,x,delta_x,el_eps);
    x_cum = [x_cum, x];
    f_l2 = [f_l2, fval];
    grad = grad_obj_p2(x);
    count = count + 1;
end

x_l2 = x_cum;

disp('the result of L2')
fval
x
count

%use the L inf norm
x = [0;0];
grad = grad_obj_p2(x);
fval = obj_p2(x);

count = 0;
x_cum = x;
f_linf = fval;
while norm(grad,2) > eps,
    delta_x = sign(-grad);
    [fval,x] = exactLS(@obj_p2,grad,x,delta_x,el_eps);
    x_cum = [x_cum, x];
    f_linf = [f_linf, fval];
    grad = grad_obj_p2(x);
    count = count + 1;
end

x_linf = x_cum;

disp('the result of L inf')
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
plot(x_l1(1,:), x_l1(2,:), 'm')
hold on
plot(x_l2(1,:), x_l2(2,:), 'g')
hold on
plot(x_linf(1,:), x_linf(2,:), 'r')
title('位置－迭代次数')
legend('函数等高线','l1范数','l2范数','l无穷范数')

%plot the value of the function with the nubmer of iterations
figure
semilogy(f_l1, 'm')
hold on
semilogy(f_l2, 'g')
hold on
semilogy(f_linf, 'r')
title('函数值－迭代次数')
legend('l1范数','l2范数','l无穷范数')