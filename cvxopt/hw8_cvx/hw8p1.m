%use diffent method to solve the problem 1
x = 0;
eps = 1e-8;

grad = grad_obj_p1(x);
fval = obj_p1(x);

count = 0;
f_cum = fval;
while norm(grad, 2) > eps,
    [fval,x] = backtrackingLS(@obj_p1,grad,x,-grad,0.3,0.8);
    f_cum = [f_cum, fval];
    grad = grad_obj_p1(x);
    count = count + 1;
end

disp('the result of backtracking line search')
fval
x
count

x = 0;
eps = 1e-6;
el_eps = 1e-10;

grad = grad_obj_p1(x);
fval = obj_p1(x);

count = 0;
f_new = fval;
while norm(grad, 2) > eps,
    [fval,x] = exactLS(@obj_p1,grad,x,-grad,el_eps);
    f_new = [f_new, fval];
    grad = grad_obj_p1(x);
    count = count + 1;
end

disp('the result of exact line search')
fval
x
count

%plot the value of function with the number of iteration
figure
plot(f_cum,'-sm')
hold on
plot(f_new,'-*g')

title('函数值－迭代次数')
legend('回溯搜索','精确搜索')