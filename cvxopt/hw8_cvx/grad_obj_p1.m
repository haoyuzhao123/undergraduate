function grad = grad_obj_p1(x)
    grad = (exp(x-5) - exp(5-x)) / (exp(x-5) + exp(5-x));
end