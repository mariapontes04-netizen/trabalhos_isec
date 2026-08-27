#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// --- CONSTANTES ---
#define MAXC 500
#define DEFAULT_ITER 10000

// --- ESTRUTURAS ---
typedef struct {
    int sol[MAXC]; // Indices dos C pontos escolhidos
    int m;         // Tamanho da solução (deve ser sempre igual ao m da instância)
    double fitness;
} Solucao;

typedef struct {
    int popSize;
    int generations;
    double prob_cross;
    double prob_mut;
    int tipo_selecao;
    int tipo_crossover;
    int tipo_mutacao;
    bool usar_memetico;
    bool usar_refinamento_inicial;
} ConfigEA;

// --- FUNÇÕES BÁSICAS ---

void carregar_dados(const char *filename, int *C, int *m, double dist[MAXC][MAXC]) {
    FILE *f = fopen(filename, "r");
    if (!f) { printf("Erro: Nao foi possivel abrir %s\n", filename); exit(1); }
    if (fscanf(f, "%d %d", C, m) != 2) exit(1);

    for(int i=0; i<*C; i++) for(int j=0; j<*C; j++) dist[i][j] = 0.0;

    char ei[10], ej[10];
    double d;
    while (fscanf(f, "%s %s %lf", ei, ej, &d) == 3) {
        int i = atoi(ei + 1) - 1;
        int j = atoi(ej + 1) - 1;
        if(i < *C && j < *C) dist[i][j] = dist[j][i] = d;
    }
    fclose(f);
}

bool existe_na_solucao(int sol[], int m, int ponto) {
    for (int i = 0; i < m; i++) if (sol[i] == ponto) return true;
    return false;
}

double avaliar(int sol[], int m, double dist[MAXC][MAXC], int m_alvo) {
    // Solução inválida: número de locais diferente de m [cite: 25]
    if (m != m_alvo) return 0.0;

    // Penalização de duplicados
    int check_duplicados[MAXC] = {0};
    for(int i=0; i<m; i++) {
        check_duplicados[sol[i]]++;
        if (check_duplicados[sol[i]] > 1) return 0.0;
    }

    double soma = 0.0;
    if (m < 2) return 0.0;

    // Cálculo da Distância Média DM(P) [cite: 22]
    // DM(P) = (1/m) * Sum(i=1..m-1) Sum(j=i+1..m) dist(ei, ej)
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            soma += dist[sol[i]][sol[j]];

    return soma / m;
}

void gerar_aleatoria(Solucao *s, int C, int m, double dist[MAXC][MAXC]) {
    int usados[MAXC] = {0};
    s->m = m;
    int k = 0;
    while (k < m) {
        int p = rand() % C;
        if (!usados[p]) {
            usados[p] = 1;
            s->sol[k++] = p;
        }
    }
    s->fitness = avaliar(s->sol, s->m, dist, m);
}

void reparar_solucao(Solucao *s, int C, double dist[MAXC][MAXC], int m_alvo) {
    int usados[MAXC] = {0};
    int temp[MAXC];
    int count = 0;

    // 1. Filtra válidos
    for (int i = 0; i < s->m; i++) {
        int p = s->sol[i];
        if (p >= 0 && p < C && !usados[p]) {
            usados[p] = 1;
            temp[count++] = p;
        }
    }

    // 2. Preenche faltas até m_alvo
    while (count < m_alvo) {
        int p = rand() % C;
        if (!usados[p]) {
            usados[p] = 1;
            temp[count++] = p;
        }
    }

    s->m = m_alvo;
    memcpy(s->sol, temp, sizeof(int) * s->m);
    s->fitness = avaliar(s->sol, s->m, dist, m_alvo);
}

// --- VIZINHANÇAS (PESQUISA LOCAL) ---

// Vizinhança 1: Troca Externa (Requisito: 2 vizinhanças) [cite: 67]
void vizinhanca_troca_externa(Solucao *s, int C) {
    int pos_remover = rand() % s->m;
    int novo;
    do { novo = rand() % C; } while (existe_na_solucao(s->sol, s->m, novo));
    s->sol[pos_remover] = novo;
}

// Vizinhança 2: Troca Dupla (Salto maior, 2-opt) [cite: 67]
void vizinhanca_troca_dupla(Solucao *s, int C) {
    vizinhanca_troca_externa(s, C);
    vizinhanca_troca_externa(s, C);
}

// Algoritmo de Pesquisa Local (Hill Climbing) [cite: 62]
void aplicar_pesquisa_local(Solucao *s, int C, double dist[MAXC][MAXC], int iteracoes) {
    Solucao vizinho;
    int m_alvo = s->m;

    for (int i = 0; i < iteracoes; i++) {
        vizinho = *s;

        // Alterna aleatoriamente entre as duas vizinhanças
        if (rand() % 2 == 0) vizinhanca_troca_externa(&vizinho, C);
        else vizinhanca_troca_dupla(&vizinho, C);

        vizinho.fitness = avaliar(vizinho.sol, vizinho.m, dist, m_alvo);

        // Aceita melhoria estrita (Hill Climbing)
        if (vizinho.fitness > s->fitness) {
            *s = vizinho;
        }
    }
}

// --- OPERADORES EVOLUTIVOS (REQUISITO: 2 de cada) ---

// Seleção 1: Torneio [cite: 72]
int selecao_torneio(Solucao pop[], int tam, int k) {
    int melhor = rand() % tam;
    for (int i = 1; i < k; i++) {
        int desafiante = rand() % tam;
        if (pop[desafiante].fitness > pop[melhor].fitness) melhor = desafiante;
    }
    return melhor;
}

// Seleção 2: Roleta [cite: 72]
int selecao_roleta(Solucao pop[], int tam) {
    double total_fit = 0.0;
    for(int i=0; i<tam; i++) total_fit += pop[i].fitness;

    if (total_fit <= 0.0) return rand() % tam;

    double r = ((double)rand() / RAND_MAX) * total_fit;
    double acc = 0.0;
    for(int i=0; i<tam; i++) {
        acc += pop[i].fitness;
        if(acc >= r) return i;
    }
    return tam-1;
}

// Crossover 1: Um Ponto (Corte) [cite: 71]
void crossover_one_point(Solucao *p1, Solucao *p2, Solucao *f1, Solucao *f2) {
    int corte = rand() % p1->m;
    for (int i = 0; i < p1->m; i++) {
        if (i <= corte) { f1->sol[i] = p1->sol[i]; f2->sol[i] = p2->sol[i]; }
        else            { f1->sol[i] = p2->sol[i]; f2->sol[i] = p1->sol[i]; }
    }
    f1->m = f2->m = p1->m;
}

// Crossover 2: Uniforme [cite: 71]
void crossover_uniform(Solucao *p1, Solucao *p2, Solucao *f1, Solucao *f2) {
    for (int i = 0; i < p1->m; i++) {
        if (rand() % 2 == 0) { f1->sol[i] = p1->sol[i]; f2->sol[i] = p2->sol[i]; }
        else                 { f1->sol[i] = p2->sol[i]; f2->sol[i] = p1->sol[i]; }
    }
    f1->m = f2->m = p1->m;
}

// Mutação 1: Troca Interna [cite: 71]
void mutacao_swap_interno(Solucao *s) {
    int i = rand() % s->m;
    int j = rand() % s->m;
    int temp = s->sol[i];
    s->sol[i] = s->sol[j];
    s->sol[j] = temp;
}

// Mutação 2: Substituição (Troca Externa) [cite: 71]
void mutacao_substituicao(Solucao *s, int C) {
    vizinhanca_troca_externa(s, C);
}

// --- ALGORITMO EVOLUTIVO CORE ---

Solucao executar_evolutivo(int C, int m_alvo, double dist[MAXC][MAXC], ConfigEA cfg) {
    Solucao *pop = malloc(sizeof(Solucao) * cfg.popSize);
    Solucao *nova_pop = malloc(sizeof(Solucao) * cfg.popSize);
    Solucao melhor_global;
    melhor_global.fitness = -1.0;

    // Parâmetros fixos usados internamente:
    int TORNEIO_K = 3;

    // 1. Inicialização
    for (int i = 0; i < cfg.popSize; i++) {
        gerar_aleatoria(&pop[i], C, m_alvo, dist);

        // HÍBRIDO 2: Refinamento na população inicial [cite: 73]
        if (cfg.usar_refinamento_inicial) {
            aplicar_pesquisa_local(&pop[i], C, dist, 200); // 200 Iteraçóes de refinamento
        }

        if (pop[i].fitness > melhor_global.fitness)
            melhor_global = pop[i];
    }

    // 2. Loop Geracional
    for (int g = 0; g < cfg.generations; g++) {
        nova_pop[0] = melhor_global; // Elitismo

        for (int i = 1; i < cfg.popSize; i += 2) {
            // A. Seleção
            int p1_idx, p2_idx;
            if (cfg.tipo_selecao == 0) { // Torneio
                p1_idx = selecao_torneio(pop, cfg.popSize, TORNEIO_K);
                p2_idx = selecao_torneio(pop, cfg.popSize, TORNEIO_K);
            } else { // Roleta
                p1_idx = selecao_roleta(pop, cfg.popSize);
                p2_idx = selecao_roleta(pop, cfg.popSize);
            }

            Solucao f1, f2;

            // B. Crossover
            if ((double)rand() / RAND_MAX < cfg.prob_cross) {
                if (cfg.tipo_crossover == 0) crossover_one_point(&pop[p1_idx], &pop[p2_idx], &f1, &f2);
                else                         crossover_uniform(&pop[p1_idx], &pop[p2_idx], &f1, &f2);
            } else {
                f1 = pop[p1_idx];
                f2 = pop[p2_idx];
            }

            // C. Mutação
            if ((double)rand() / RAND_MAX < cfg.prob_mut) {
                if (cfg.tipo_mutacao == 0) mutacao_swap_interno(&f1);
                else                       mutacao_substituicao(&f1, C);
            }
            if (i + 1 < cfg.popSize && (double)rand() / RAND_MAX < cfg.prob_mut) {
                if (cfg.tipo_mutacao == 0) mutacao_swap_interno(&f2);
                else                       mutacao_substituicao(&f2, C);
            }

            // D. Reparação e Avaliação
            reparar_solucao(&f1, C, dist, m_alvo);
            nova_pop[i] = f1;

            if (i + 1 < cfg.popSize) {
                reparar_solucao(&f2, C, dist, m_alvo);
                nova_pop[i + 1] = f2;
            }
        }

        // Atualização da População
        for (int i = 0; i < cfg.popSize; i++) {
            pop[i] = nova_pop[i];
            if (pop[i].fitness > melhor_global.fitness) melhor_global = pop[i];
        }

        // HÍBRIDO 1: Memético (Refina o melhor da geração) [cite: 73]
        if (cfg.usar_memetico) {
            aplicar_pesquisa_local(&melhor_global, C, dist, 500);
            pop[0] = melhor_global;
        }
    }

    free(pop);
    free(nova_pop);
    return melhor_global;
}

// --- FUNÇÃO DE ESTATÍSTICA (BATCH RUN) ---
void correr_estatistica(int C, int m, double dist[MAXC][MAXC], int opcao_algo, ConfigEA cfg) {
    int NUM_RUNS = 10;
    double PL_ESTUDO_ITER = 20000; // Iteraçóes para o estudo do PL (valor mais alto)

    double melhor_val = -1.0;
    double soma_vals = 0.0;
    double valores[10];

    printf("\n--- MODO ESTATISTICO (%d Runs) ---\n", NUM_RUNS);
    printf("Aguarde...\n");

    for(int r=0; r<NUM_RUNS; r++) {
        Solucao final;

        if (opcao_algo == 1) { // Pesquisa Local (Hill Climbing)
            gerar_aleatoria(&final, C, m, dist);
            aplicar_pesquisa_local(&final, C, dist, PL_ESTUDO_ITER);
        } else { // Evolutivos e Híbridos
            final = executar_evolutivo(C, m, dist, cfg);
        }

        valores[r] = final.fitness;
        soma_vals += final.fitness;
        if(final.fitness > melhor_val) melhor_val = final.fitness;

        printf("Run %d: %.6f\n", r+1, final.fitness);
    }

    double media = soma_vals / NUM_RUNS;

    // Desvio Padrão
    double soma_var = 0.0;
    for(int r=0; r<NUM_RUNS; r++) soma_var += pow(valores[r] - media, 2);
    double std_dev = sqrt(soma_var / NUM_RUNS);

    printf("\n--- RESULTADOS FINAIS (para %d runs) ---\n", NUM_RUNS);
    printf("Melhor Global (max): %.6f\n", melhor_val);
    printf("Media:               %.6f\n", media);
    printf("Desvio Padrao:       %.6f\n", std_dev);
    printf("-------------------------\n");
}

int main() {
    srand(time(NULL));
    int C, m;
    double dist[MAXC][MAXC];
    char nome_fich[100];

    // Parâmetros fixos para o estudo experimental (movidos de #define)
    int POP_SIZE = 50;
    int GENERATIONS = 500;
    double PROB_CROSS = 0.8;
    double PROB_MUT = 0.1;

    printf("Nome do ficheiro (ex: tourism_5.txt): ");
    if (scanf("%s", nome_fich) != 1) return 1;
    carregar_dados(nome_fich, &C, &m, dist);
    printf("Instancia: %s (C=%d, m=%d)\n", nome_fich, C, m);

    int op = -1;
    while (op != 0) {
        printf("\n=== MENU ===\n");
        printf("1. Pesquisa Local (Hill Climbing - %d Iteracoes)\n", DEFAULT_ITER);
        printf("2. Algoritmo Evolutivo (Padrao - %d Geracoes)\n", GENERATIONS);
        printf("3. Hibrido 1 (Memetico - %d Geracoes)\n", GENERATIONS);
        printf("4. Hibrido 2 (Pop. Inicial Refinada - %d Geracoes)\n", GENERATIONS);
        printf("5. MODO ESTATISTICO (Correr 10 x e tirar Medias)\n");
        printf("0. Sair\nOpcao: ");
        if (scanf("%d", &op) != 1) break;

        if (op == 0) break;

        // Configuração Padrão para o Evolutivo
        ConfigEA cfg = {
                .popSize = POP_SIZE,
                .generations = GENERATIONS,
                .prob_cross = PROB_CROSS,
                .prob_mut = PROB_MUT,
                .tipo_selecao = 0,     // Torneio (Opção 1)
                .tipo_crossover = 0,   // 1-Ponto (Opção 1)
                .tipo_mutacao = 1,     // Substituição (Opção 2 - mais útil)
                .usar_memetico = false,
                .usar_refinamento_inicial = false
        };

        // Ajustes baseados na escolha
        if (op == 3) cfg.usar_memetico = true;
        if (op == 4) cfg.usar_refinamento_inicial = true;

        if (op == 5) {
            int sub_op;
            printf("\nQual algoritmo testar 10 x? (1-4): ");
            if (scanf("%d", &sub_op) != 1) continue;

            if (sub_op == 3) cfg.usar_memetico = true;
            if (sub_op == 4) cfg.usar_refinamento_inicial = true;

            correr_estatistica(C, m, dist, sub_op, cfg);
            continue;
        }

        // Execução Única
        Solucao final;
        printf("\n>> A executar...\n");

        if (op == 1) { // Pesquisa Local (Hill Climbing)
            gerar_aleatoria(&final, C, m, dist);
            // Uso do DEFAULT_ITER = 10 para a demonstração rápida
            aplicar_pesquisa_local(&final, C, dist, DEFAULT_ITER);
        } else { // Evolutivos e Híbridos
            final = executar_evolutivo(C, m, dist, cfg);
        }

        printf("RESULTADO -> Fitness: %.6f\n", final.fitness);
        printf("Locais Escolhidos: ");
        for(int i=0; i<m; i++) printf("e%d ", final.sol[i] + 1);
        printf("\n");
    }

    return 0;
}