function A = plotaref2(data)

A = data(:,[1,2,3,4,5,6]);

N = length(data);
topid = max(A(:,1));

for i=1:topid,
  I = find(A(:,1) == i);
	B = A(I,:);
	%scatter(B(:,2),B(:,3),5,'r');
	
	color = rand(1,3);
	
	 x = B(:,2);
    y = B(:,3);
    plot(x,y,'.','Color',[1 0 0]);
	plot(x,y,'o-','Color',[1 0 0]);
	hold on;
end

rectangle('Position',[0.3,0.25,0.3,0.3])

circle(0.5,0.5,0.4);

axis([0 1 0 1]);