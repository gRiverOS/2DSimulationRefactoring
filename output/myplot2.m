function myplot2()

load data_0.txt

l = length(data_0);
figure;
axis([0 10 0 10])
hold;
x = [0, 10, 10, 0, 0];
y = [0, 0, 10, 10, 0];
plot(x, y)
x = [5, 7, 7, 5, 5];
y = [5, 5, 7, 7, 5];
plot(x, y);
x = [5, 5.5, 5.5, 5, 5];
y = [2.5, 2.5, 3, 3, 2.5];
plot(x, y);


t = linspace(0,2*pi,100)';

ar = 4.5;
ax = 5; ay = 5;
circsax = ar.*cos(t)+ax;  circsay = ar.*sin(t)+ay; 
plot(circsax, circsay); 

br = 1.2;
bx = 5; by = 2.5;
circsbx = br.*cos(t)+bx;  circsby = br.*sin(t)+by; 
plot(circsbx, circsby);

axis([0 10 0 10])

for e=1:300,
	I = find(data_0(:,1) == e);
	plot(data_0(I,2),data_0(I,3),'-o', 'MarkerSize', 4);
end; 

end;
