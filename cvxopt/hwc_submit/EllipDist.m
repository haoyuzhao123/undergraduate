function [d,e1,e2] = EllipDist(A1,mu1,A2,mu2)
    %compute the signed distance between 2 non-overlap ellipsoid
    %the inputs are the matrix and center for each of the matrix
    Ap1 = sqrtm(A1);
    Ap2 = sqrtm(A2);
    m = size(A1,1);
    
    cvx_begin
        variable x(m);
        variable y(m);
        minimize(norm(Ap1 * x - Ap2 * y + mu1 - mu2,2));
        subject to
            norm(x,2) <= 1;
            norm(y,2) <= 1;
    cvx_end
    
    e1 = Ap1 * x + mu1;
    e2 = Ap2 * y + mu2;
    d = norm(e1-e2,2);
end