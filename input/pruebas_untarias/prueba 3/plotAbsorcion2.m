function A = plotAbsorcion2(data, A, limit)

delta = 10/1000;

I = find(data(:,1) <= limit);
B = data(I,:);

N = length(B);
for i=1:N,
    x = fix(B(i,2)/delta)+1;
    y = fix(B(i,3)/delta)+1;
    A(x,y) = A(x,y) + data(i,8);
end



