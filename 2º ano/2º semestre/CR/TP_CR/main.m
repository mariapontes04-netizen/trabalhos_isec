%% TRABALHO PRÁTICO: CONHECIMENTO E RACIOCÍNIO (CR)
% Versão Final: Apenas com Deep Learning Toolbox e Processamento de Teste Externo

clear all; close all; clc;

%% 1. TAREFA 3.1: TRATAMENTO DO DATASET (TREINO)
data = readtable('dataset_TP.csv');

% Remover registos sem classe (target)
data(ismissing(data.class_cat), :) = [];

num_vars = {'temperature', 'vibration', 'rotation_speed', 'voltage', ...
            'current', 'pressure', 'noise_level', 'efficiency', ...
            'load_val', 'torque'};
cat_vars = {'maintenance_level', 'operating_mode', 'cooling_type', 'sensor_status'};

% A. Tratar valores em falta (Numéricos) - Média manual
for i = 1:length(num_vars)
    col = num_vars{i};
    col_data = data.(col);
    avg_val = mean(col_data, 'omitnan');
    data.(col)(isnan(col_data)) = avg_val;
end

% B. Tratar valores em falta (Categóricos) - Moda manual
for i = 1:length(cat_vars)
    col = cat_vars{i};
    data.(col) = categorical(data.(col));
    m = mode(data.(col));
    data.(col)(isundefined(data.(col))) = m;
end

% C. Conversão para numérico (Base MATLAB)
data.maintenance_level = double(data.maintenance_level);
data.operating_mode = double(data.operating_mode);
data.cooling_type = double(data.cooling_type);
data.sensor_status = double(data.sensor_status);
data.class_cat = categorical(data.class_cat);
target_names = categories(data.class_cat);
data.class_num = double(data.class_cat);

%% 2. DIVISÃO MANUAL (Sem cvpartition - Para respeitar a restrição de Toolboxes)
percentagem_treino = 0.8;
n_total = height(data);
indices = randperm(n_total);
idx_treino = indices(1:round(percentagem_treino * n_total));
idx_val_teste = indices(round(percentagem_treino * n_total)+1:end);

train_data = data(idx_treino, :);
test_data = data(idx_val_teste, :);

X_train = table2array(train_data(:, [num_vars, cat_vars]));
X_test = table2array(test_data(:, [num_vars, cat_vars]));
Y_train = train_data.class_num;
Y_test = test_data.class_num;

%% 3. NORMALIZAÇÃO MANUAL (Sem zscore - Apenas matemática base)
% Calculamos a média e desvio padrão apenas do treino para não "viciar" o modelo
mu = mean(X_train);
sigma = std(X_train);

% Evitar divisão por zero se um desvio padrão for 0
sigma(sigma == 0) = 1;

X_train_norm = (X_train - mu) ./ sigma;
X_test_norm = (X_test - mu) ./ sigma;

%% 4. TAREFA 3.2: CBR (Implementação manual)
predicted_cbr = zeros(size(Y_test));
for i = 1:size(X_test_norm, 1)
    % Distância Euclidiana manual
    distancias = sqrt(sum((X_train_norm - X_test_norm(i, :)).^2, 2));
    [~, idx] = min(distancias);
    predicted_cbr(i) = Y_train(idx);
end
acc_cbr = sum(predicted_cbr == Y_test) / length(Y_test) * 100;
fprintf('Precisão CBR (Validação): %.2f%%\n', acc_cbr);

%% 5. TAREFA 3.3: REDE NEURONAL (Única Toolbox permitida)
inputs_rn = X_train_norm';
targets_rn = zeros(length(target_names), length(Y_train));
for i = 1:length(Y_train)
    targets_rn(Y_train(i), i) = 1;
end

net = patternnet(10); % 10 neurónios na camada oculta
[net, tr] = train(net, inputs_rn, targets_rn);

outputs_rn = net(X_test_norm');
[~, predicted_rn] = max(outputs_rn);
acc_rn = sum(predicted_rn' == Y_test) / length(Y_test) * 100;
fprintf('Precisão RN (Validação): %.2f%%\n', acc_rn);

%% 6. TAREFA ADICIONAL: PREVISÃO DO FICHEIRO DE TESTE EXTERNO
% Agora aplicamos o que aprendemos ao dataset_TP_test.csv
data_final_test = readtable('dataset_TP_test.csv');

% NOTA: Temos de aplicar a MESMA limpeza e a MESMA normalização (mu e sigma do treino)
for i = 1:length(num_vars)
    col = num_vars{i};
    data_final_test.(col)(isnan(data_final_test.(col))) = mean(data_final_test.(col), 'omitnan');
end
for i = 1:length(cat_vars)
    col = cat_vars{i};
    data_final_test.(col) = categorical(data_final_test.(col));
    data_final_test.(col)(isundefined(data_final_test.(col))) = mode(data_final_test.(col));
    data_final_test.(col) = double(data_final_test.(col));
end

X_final_test = table2array(data_final_test(:, [num_vars, cat_vars]));
X_final_norm = (X_final_test - mu) ./ sigma; % Usar mu/sigma do treino!

% Prever com a Rede Neuronal (Geralmente é a mais precisa)
outputs_finais = net(X_final_norm');
[~, classes_previstas] = max(outputs_finais);

% Converter de volta para nomes (Normal, Electrical, Mechanical)
previsoes_nomes = target_names(classes_previstas);

% Guardar resultados num novo CSV para entregar ao stor
data_final_test.Predicted_Class = previsoes_nomes;
writetable(data_final_test, 'resultados_previsoes.csv');
fprintf('Ficheiro "resultados_previsoes.csv" gerado com sucesso!\n');

% Mostrar Matrizes de Confusão para o Relatório
figure;
subplot(1,2,1); confusionchart(categorical(Y_test, 1:3, target_names), categorical(predicted_cbr, 1:3, target_names), 'Title', 'CBR');
subplot(1,2,2); confusionchart(categorical(Y_test, 1:3, target_names), categorical(predicted_rn, 1:3, target_names), 'Title', 'RN');