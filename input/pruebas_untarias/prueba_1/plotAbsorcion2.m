function A = plotAbsorcion2(filename, limit)

delta = 5/1000;

data = load(filename);
I = find(data(:,1) <= limit);
B = data(I,:);

N = length(B)
MAX_X =fix(max(B(:,2)) / delta);
MAX_Y =fix(max(B(:,3)) / delta);

A = zeros(MAX_X, MAX_Y);
for i=1:N,
    x = fix(B(i,2)/delta)+1;
    y = fix(B(i,3)/delta)+1;
    % I(i)
    % x
    % y
    % A(x,y) = A(x,y) + data(I(i),8);
    % A(x,y) = A(x,y) + data(B(i),8);
    A(x,y) = A(x,y) + B(i,8);
end