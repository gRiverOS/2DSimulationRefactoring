function A = plotg(data)

A = data(:,[1,2,3,4,5,6]);

N = length(data);
topid = max(A(:,1));

for i=1:topid,
    I = find(A(:,1) == i);
	B = A(I,:);
	%scatter(B(:,2),B(:,3),5,'r');
	
	
	x = B(:,2);
	y= B(:,3);
	u = gradient(x);
	v = gradient(y);
	scale = 0;
	lh = quiver(x,y,u,v,scale)
	set(lh,'linewidth',1.5);

	
	hold on;
end


rectangle('Position',[0,0,1,1])
circle(0.5,0.5,0.4);

axis([0 1 0 1]);