function fval = obj_p3(x)
    global Am;
    fval = sum(-log(1-Am' * x)) + sum(-log(1-x .* x));
    %make sure that the constraints are satisfied
    if ~isreal(fval),
        fval = 10000;
    end
end