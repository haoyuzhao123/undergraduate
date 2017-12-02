function [grad, hessian] = grad_obj_p1(x)
    grad = [0;0];
    grad(1) = -2 * (1 - x(1)) - 8 * x(1) * (x(2) - x(1)^2); 
    grad(2) = 4 * (x(2) - x(1)^2);
    hessian = zeros(2,2);
    hessian(1,1) = 2 - 8 * x(2) + 24 * x(1) * x(1);
    hessian(1,2) = -8 * x(1);
    hessian(2,1) = -8 * x(1);
    hessian(2,2) = 4;
end