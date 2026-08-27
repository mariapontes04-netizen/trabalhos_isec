%% SCRIPT PARA GERAR TABELA DE EXPERIÊNCIAS (RELATÓRIO)
clear all; clc;

% 1. Carregar e tratar dados (Rápido)
data = readtable('dataset_TP.csv');
data(ismissing(data.class_cat), :) = [];
% ... (Aqui deves ter a mesma limpeza que fizemos no código principal) ...

% Variáveis para o loop
topologias = {2, 5, 10, [10 5], 20}; % Diferentes números de neurónios
funcoes_treino = {'trainscg', 'trainrp'};
resultados = {}; % Para guardar os dados

fprintf('A iniciar as experiências... Isto pode demorar um pouco.\n');

for f = 1:length(funcoes_treino)
    for t = 1:length(topologias)
        
        topo = topologias{t};
        func = funcoes_treino{f};
        
        % Criar e treinar rede
        net = patternnet(topo, func);
        net.trainParam.showWindow = false; % Não abrir janelas para ser mais rápido
        
        % Treino (usando os dados normalizados X_train_norm e targets_rn do código anterior)
        % [net, tr] = train(net, inputs_rn, targets_rn);
        
        % Simulação de resultados para o exemplo (Aqui usarias a acc_rn real)
        acc_treino = 95 + rand()*4; 
        acc_teste = 94 + rand()*5;
        
        % Guardar na lista
        resultados = [resultados; {func, num2str(topo), acc_treino, acc_teste}];
        fprintf('Feito: %s com topo %s\n', func, num2str(topo));
    end
end

% 2. Criar a Tabela e Exportar para Excel
T = cell2table(resultados, 'VariableNames', {'Funcao_Treino', 'Topologia', 'Accuracy_Treino', 'Accuracy_Teste'});
writetable(T, 'Experiencias_RN.xlsx');

fprintf('\nSUCESSO: O ficheiro "Experiencias_RN.xlsx" foi criado na tua pasta!\n');