function myplo4()

load data_0.txt

l = length(data_0);
figure;
axis([0 1 0 1])
hold;
x = [0, 1, 1, 0, 0];
y = [0, 0, 1, 1, 0];
plot(x, y)

t = linspace(0,2*pi,100)';

ar = 0.4;
ax = 0.5; ay = 0.5;
circsax = ar.*cos(t)+ax;  circsay = ar.*sin(t)+ay; 
plot(circsax, circsay); 


axis([0 1 0 1])

for e=1:300,
	I = find(data_0(:,1) == e);
	plot(data_0(I,2),data_0(I,3),'-o', 'MarkerSize', 4);
end; 

end;
