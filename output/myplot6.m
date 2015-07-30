function myplot6()

load data_0.txt

l = length(data_0);
figure;
axis([0 5 0 5])
hold;
x = [0, 5, 5, 0, 0];
y = [0, 0, 5, 5, 0];
plot(x, y);
x = [2.5, 3.5, 3.5, 2.5, 2.5];
y = [2.5, 2.5, 3.5, 3.5, 2.5];
plot(x, y);


t = linspace(0,2*pi,100)';

ar = 2.25;
ax = 2.5; ay = 2.5;
circsax = ar.*cos(t)+ax;  circsay = ar.*sin(t)+ay; 
plot(circsax, circsay); 

br = 0.6;
bx = 2.5; by = 1.25;
circsbx = br.*cos(t)+bx;  circsby = br.*sin(t)+by; 
plot(circsbx, circsby);

axis([0 5 0 5])

for e=1:300,
	I = find(data_0(:,1) == e);
	plot(data_0(I,2),data_0(I,3),'-o', 'MarkerSize', 4);
end; 

end;
