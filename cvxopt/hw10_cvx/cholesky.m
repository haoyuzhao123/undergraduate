function [B] = cholesky(A)
    %the cholesky decomposition of a positive definite matrix
    [n,m] = size(A);
    if n ~= m,
        error('A is not symmetric')
    end
    if norm(A-A','inf') > 0.0001,
        error('A is not symmetric')
    end
    B = A;
    for j=1:n,
        for k=1:(j-1),
            B(j,j) = B(j,j) - B(j,k) * B(j,k);
        end
        
        %check, make sure that B(j,j) \ge 0
        if B(j,j) < 0,
            B(j,j)
            j
            error('B(j,j) < 0')
        end
        B(j,j) = sqrt(B(j,j));
        
        for i=(j+1):n,
            for k=1:(j-1),
                B(i,j) = B(i,j) - B(i,k) * B(j,k);
            end
            B(i,j) = B(i,j) / B(j,j);
        end
    end
    
    for j=1:n,
        for i=1:(j-1),
            B(i,j) = 0;
        end
    end
    
end