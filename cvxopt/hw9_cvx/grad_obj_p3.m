function [grad, hessian] = grad_obj_p3(x)
    [n,m] = size(x);
    grad = log(x) + ones(n,m);
    
    hessian = diag(1 ./ x);
end