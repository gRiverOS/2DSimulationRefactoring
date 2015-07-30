function A = plotg(data)

A = data(:,[1,2,3,4,5,6]);

N = length(data);
topid = max(A(:,1));

for i=1:topid,
    I = find(A(:,1) == i);
	B = A(I,:);
	scatter(B(:,2),B(:,3),5,'r');
	hold on;
end


rectangle('Position',[5,2.5,2,2]);
rectangle('Position',[0,0,10,10]);

circle(5,5,4.5);

axis([0 10.02 0 10.02]);