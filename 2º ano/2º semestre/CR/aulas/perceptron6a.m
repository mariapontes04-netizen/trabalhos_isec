function perceptron6b( )
%Implementing a perceptron using the NNTool

% clear
clear all;
close all;

% input initialization
p = [0 0 1 1; 0 1 0 1];

%which logic gate? 
fprintf('Choose the logic gate: \n');
fprintf('1 - AND\n');
fprintf('2 - OR\n');
fprintf('3 - NAND\n');
fprintf('4 - XOR\n');
tmp =  input('                        operador? (default 1) = ');

% initialize targets
if isempty(tmp)
    t = [0 0 0 1];
    op='AND';
else
    switch tmp
        case 1
            t = [0 0 0 1];
            op='AND';
        case 2
            t = % COMPLETE:
            op='OR';
        case 3
            t = % COMPLETE:
            op='NAND';
        case 4
            t = % COMPLETE:
            op='XOR';
       otherwise
            t = [0 0 0 1];
            op='AND';
    end
end

% COMPLETE: use the nntool to create a perceptron called net


% COMPLETE: initialize the number of epochs to 100


% COMPLETAR: use the nntool to train the perceptron


% COMPLETE: use the nntool to simulate the perceptron (store the output in
% y)


% Show output
fprintf('Outupt of the perceptron to %s:', op);
disp(y);
fprintf('Target desired to %s:', op);
disp(t);

% Vizualize the perceptron
view(net)

%Plot 
w = net.iw{1,1};
b = net.b{1};
plotpv(p, t)
plotpc(w, b)

end

