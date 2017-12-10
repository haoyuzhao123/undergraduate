function [v,w] = solveKKT(H,A,g,h)
    v = zeros(size(g));
    w = zeros(size(h));
    %examine the matrices
    [mh,nh] = size(H);
    [ma,na] = size(A);
    [mg,ng] = size(g);
    [mhp,nhp] = size(h);
    if mh ~= nh,
        error('H is not square');
    end
    if nh ~= na,
        error('H and A do not match');
    end
    if mh ~= mg,
        error('H,g do not match');
    end
    if ma ~= mhp,
        error('A,h do not match');
    end
    %solve the v,w
    %H^{-1}A^T
    temp1 = lineqsol(H, A');
    %H^{-1}g
    temp2 = lineqsol(H, g); 
    %shur complement
    S = -A * temp1;
    %w
    w = lineqsol(-S, h - A * temp2);
    %v
    v = lineqsol(H, -A' * w - g);
    
end