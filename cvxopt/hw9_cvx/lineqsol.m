function [X,L] = lineqsol(A,B),
    %solve the linear equation AX = B when A is positive definite
    if norm(A - A','inf') > 0.0001,
        error('A is not symmetric')
    end
    
    [n,m] = size(A);
    [nb,mb] = size(B);
    if n ~= nb || m ~= nb,
        error('size A and size b not match')
    end
    
    X = zeros(size(B));
    %use cholesky decomposition and backsubstitution to solve the linear
    %equation
    L = cholesky(A);
    U = L';
    for col=1:mb,
        y = B(:,col);
    
        for i=1:n,
            for j=1:(i-1),
                y(i,1) = y(i,1) - y(j,1) * L(i,j);
            end
            y(i,1) = y(i,1) / L(i,i);
        end
    
        x = y;
        for i=n:-1:1,
            for j=n:-1:(i+1),
                x(i,1) = x(i,1) - x(j,1) * U(i,j);
            end
            x(i,1) = x(i,1) / U(i,i);
        end
        X(:,col) = x;
    end
    
end