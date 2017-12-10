function [grad,hess] = grad_barrier(x)
    %the gradient and the hessian of the barrier function 
    grad = -1 ./ x;
    hess = diag(grad .^ 2);
end