function [fval, x, t] = backtrackingLS(f,grad_f,x_int,delta_x,alpha,beta)
    %this function implements the backtracking line search
    %
    %f is the objective function
    %x_int is the initial point for this line search
    %grad_f is the gradient at x_int
    %delta_x is the direction
    %alpah and beta are the parameters for the line search
    %
    %This function does not check that <grad_f,delta_x> < 0
    %Needs to check it before
    %
    
    t = 1;
    fval = f(x_int);
    x = x_int;
    %check if the descent direction is legal
    if grad_f' * delta_x >= 0,
        disp(grad_f' * delta_x)
        error('illegal descent direction')
    end
    %check if the gradient is small enough
    if norm(grad_f,2) <= 1e-10,
        disp('gradient small enough')
        return;
    end
    %backtracking
    while f(x_int + t * delta_x) > f(x_int) + alpha * grad_f' * delta_x * t,
        %disp(f(x_int + t * delta_x) - f(x_int) + alpha * grad_f' * delta_x)
        t = beta * t;
    end
    
    x = x_int + t * delta_x;
    fval = f(x);
    
end