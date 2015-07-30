function myplot()

load data.txt

l = length(data);
figure;
axis([0 1 0 1])
hold;
x = [0, 1, 1, 0, 0];
y = [0, 0, 1, 1, 0];
plot(x, y)
x = [0.5, 0.7, 0.7, 0.5, 0.5];
y = [0.5, 0.5, 0.7, 0.7, 0.5];
plot(x, y);
x = [0.5, 0.55, 0.55, 0.5, 0.5];
y = [0.25, 0.25, 0.30, 0.30, 0.25];
plot(x, y);


t = linspace(0,2*pi,100)';

ar = 0.45;
ax = 0.5; ay = 0.5;
circsax = ar.*cos(t)+ax;  circsay = ar.*sin(t)+ay; 
plot(circsax, circsay); 

br = 0.12;
bx = 0.5; by = 0.25;
circsbx = br.*cos(t)+bx;  circsby = br.*sin(t)+by; 
plot(circsbx, circsby);

axis([0 1 0 1])

plot(data(:,1),data(:,2)); 

end;
