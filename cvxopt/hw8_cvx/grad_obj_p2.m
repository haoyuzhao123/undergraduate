function grad = grad_obj_p2(x)
    grad = [0;0];
    grad(1) = -2 * (1 - x(1)) - 8 * x(1) * (x(2) - x(1)^2); 
    grad(2) = 4 * (x(2) - x(1)^2);
end