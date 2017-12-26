%created by CVX TA, edit by Haoyu Zhao
close all
clear all
load('Problem1.mat')
%transform the matrix into symmetric matrix
Q1 = (Q1' + Q1) / 2;
Q2 = (Q2' + Q2) / 2;
%end for transformation

%transform the ellipsoid into standard (x-mu)^TA^{-1}(x-mu)
A1 = inv(Q1(1:2,1:2));
mu1 = -A1 * Q1(1:2,3);
k = mu1' * Q1(1:2,1:2) * mu1 - Q1(3,3);
A1 = A1 * k;

A2 = inv(Q2(1:2,1:2));
mu2 = -A2 * Q2(1:2,3);
k = mu2' * Q2(1:2,1:2) * mu2 - Q2(3,3);
A2 = A2 * k;
%end transformation

%solve the minimum distance points by cvx
[d,x,y] = EllipDist(A1,mu1,A2,mu2);

%data points
D = [x';y'];


figure;
hold on
 m=ezplot(@(x,y)myfun(x,y,Q1));
 set(m,'Color','red')
 m=ezplot(@(x,y)myfun(x,y,Q2));
  set(m,'Color','blue')
 %plot the minimum distance points
 m=plot(D(:,1),D(:,2));
 axis equal
 %end plot
 title('')
 xlim([-6,4])
  ylim([-6,2.5])
  title('Two ellipsoids for testing')