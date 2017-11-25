function grad = grad_obj_p3(x)
    global Am;
    s = size(Am);
    t = Am' * x;
    temp = zeros(s(1),1);
    
    tp = 1 ./ (1 - t);
    
    temp = Am * tp;
    temp = temp + 2 * x ./ (1 - x .* x);
    
    grad = temp;
end