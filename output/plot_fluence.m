function A = plot_fluence(filename, limit)

% delta = 0.4/200;
delta = 0.4/40;

if limit < 0
    B = load(filename);
else
    data = load(filename);
    I = find(data(:,1) <= limit);
    B = data(I,:);
end

N = length(B)
% MAX_X = fix(max(B(:,2)) / delta)
% MAX_Y = fix(max(B(:,3)) / delta)
% MAX_Z = fix(max(B(:,4)) / delta)
% MAX_R = fix(max(MAX_X, MAX_Y) * sqrt(2))

% A = zeros(201, 250);
A = zeros(41, 51);
for i=1:N,
    z = fix(B(i,4) / delta) + 1;
    x = fix(B(i,2) / delta) + 1;
    y = fix(B(i,3) / delta) + 1;
    
    r = fix(sqrt(B(i,2) * B(i,2) + B(i,3) * B(i,3)) / delta) + 1;

    if B(i,4) <= 0.4 && B(i,4) >= 0
    % if B(i,4) >= 0
        if sqrt(B(i,2) * B(i,2) + B(i,3) * B(i,3)) <= 0.3
            % if B(i,4) >= 0.2
            %     A(z,r) = A(z,r) + B(i, 10) / 2; 
            % elseif B(i,4) >= 0.1
            %     % A(z,r) = A(z,r) + B(i, 10) * 2; 
            %     A(z,r) = A(z,r) + B(i, 10);
            % else
                % [z r]
                A(z,r) = A(z,r) + B(i, 10);
            end
        end
    end
end
