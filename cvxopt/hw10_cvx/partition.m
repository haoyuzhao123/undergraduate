function [x,l,v] = partition(vec)
    %partition the vector
    x = vec(1:200);
    l = vec(201:400);
    v = vec(401:500);
    reshape(x,200,1);
    reshape(l,200,1);
    reshape(v,100,1);
end