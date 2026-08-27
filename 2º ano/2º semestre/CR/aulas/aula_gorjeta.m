function [fis] = gorjeta()

%PASSO 1 criar sistema fis
fis = mamfis;

%PASSO 2 VARIÁVEIS
fis = addInput(fis,[0,10],'Name',"servico");
       %COMPLETAR

%PASSO 3 FUNÇÕES DE PERTENÇA
fis = addMF(fis,"servico", "gaussmf",[1.5 0],'Name', "fraco");
	%COMPLETAR para as três variáveis

	%PASSO 4 REGRAS
regra1 = "servico==fraco | comida==ma => gorjeta=fraca";
regra2 = %COMPLETAR
regra3 = %COMPLETAR
regras=[regra1 regra2 regra3];
fis = addRule(fis,regras);

%PASSO 5: avaliar para vários valores de servico e comida com evalfis
for servico=0:10
  	  for comida=0:10
           entrada=[servico comida];
           out = evalfis(fis, entrada);
            fprintf('serviço = %d\nComida = %d\nGorjeta = %f\n\n',servico, comida, out);
      end
 end
end

