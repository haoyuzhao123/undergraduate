function [grad, hessian] = grad_obj_p2(x)
    global Am;
    s = size(Am);
    t = Am' * x;
    temp = zeros(s(1),1);
    tp = 1 ./ (1 - t);
    
    temp = Am * tp + 2 * x ./ (1 - x .* x);
    grad = temp;
    
    hessian = zeros(s(2),s(2));
    hessian = hessian + Am * diag(tp .* tp) * Am';
    temp = 2 * (1 + x .* x) ./ ((1 - x .* x) .* (1 - x .* x));
    hessian = hessian + diag(temp);
end