function z = myfun(x,y,Q)
z =Q(1,1).*x.^2+Q(2,1).*x.*y+Q(3,1).*x+Q(1,2).*x.*y+Q(2,2).*y.^2+Q(3,2).*y+Q(1,3).*x+Q(2,3).*y+Q(3,3);
end