function [fval, x] = exactLS(f, grad_f, x_int, delta_x, eps)
    %this function implements the exact line search
    %
    %f is the objective function
    %grad_f is the gradient at this point
    %x_int is the initial point
    %delta_x is the direction
    %eps is the tolerance
    %
    %check if the descent direction is legal
    if grad_f' * delta_x >= 0,
        disp('illegal descent direction')
        return;
    end
    
    gamma = 1.5;
    delta = 1;
    %obtain the interval [l,r]
    l = 0;
    temp = delta;
    while f(x_int + temp * delta_x) > f(x_int + gamma * temp * delta_x),
        temp = temp * gamma;
    end
    r = temp * gamma;
    %the minimum of the function
    c = (sqrt(5) - 1) / 2;
    t = l + c * (r - l);
    s = l + (1 - c) * (r - l);
    while r - l > eps,
        if f(x_int + s * delta_x) > f(x_int + t * delta_x),
            l = s;
            s = t;
            t = l + c * (r - l);
        else
            r = t;
            t = s;
            s = l + (1-c) * (r-l);
        end
    end
    fval = f(x_int + l * delta_x);
    x = x_int + s * delta_x;
end