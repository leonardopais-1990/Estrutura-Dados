#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

#define NUM_CAIXAS_MAX 25
#define NUM_CAIXAS_MIN 3
#define INTERVALO_OBSERVACAO 15 // em minutos

/* Estrutura para armazenar informações do caixa */
typedef struct {
    int id;
    int totalAtendimentos;
    int tempoTotalAtendimento; // em segundos
} Caixa;

/* Estrutura para armazenar informações sobre a fila */
typedef struct {
    No* fila;
    int tempoEsperaTotal; // em segundos
    int numClientes;
} Fila;

/* Inicializa um caixa */
void inicializaCaixa(Caixa* caixa, int id) {
    caixa->id = id;
    caixa->totalAtendimentos = 0;
    caixa->tempoTotalAtendimento = 0;
}

/* Inicializa uma fila */
void inicializaFilaEstrutura(Fila* fila) {
    inicializaFila(&(fila->fila));
    fila->tempoEsperaTotal = 0;
    fila->numClientes = 0;
}

/* Insere um cliente na fila e atualiza os tempos de espera */
void insereCliente(Fila* fila, int nroAtendimento, int tempoEspera) {
    insereElemento(&(fila->fila), nroAtendimento);
    fila->tempoEsperaTotal += tempoEspera;
    fila->numClientes++;
}

/* Remove um cliente da fila e atualiza os tempos de espera */
void removeCliente(Fila* fila) {
    if (!listaVazia(fila->fila)) {
        removeElemento(&(fila->fila));
        fila->numClientes--;
        // Assumindo que a redução do tempo de espera é proporcional ao número de clientes restantes
        if (fila->numClientes > 0) {
            fila->tempoEsperaTotal -= fila->tempoEsperaTotal / fila->numClientes;
        } else {
            fila->tempoEsperaTotal = 0;
        }
    }
}

/* Calcula o tempo médio de atendimento do dia */
float tempoMedioAtendimento(Caixa caixas[], int numCaixas) {
    int totalAtendimentos = 0;
    int tempoTotalAtendimento = 0;
    for (int i = 0; i < numCaixas; i++) {
        totalAtendimentos += caixas[i].totalAtendimentos;
        tempoTotalAtendimento += caixas[i].tempoTotalAtendimento;
    }
    return (float)tempoTotalAtendimento / totalAtendimentos;
}

/* Calcula o tempo de espera atual da fila */
float tempoEsperaAtual(Fila* fila) {
    return (float)fila->tempoEsperaTotal / fila->numClientes;
}

/* Gerencia a abertura e fechamento de caixas */
void gerenciarCaixas(Fila* fila, Caixa caixas[], int* numCaixas) {
    if (fila->numClientes / *numCaixas > 5 && *numCaixas < NUM_CAIXAS_MAX) {
        (*numCaixas)++;
    } else if (fila->numClientes / *numCaixas < 3 && *numCaixas > NUM_CAIXAS_MIN) {
        (*numCaixas)--;
    }
}

/* Função principal para simular o sistema */
int main() {
    Caixa caixas[NUM_CAIXAS_MAX];
    Fila fila;
    int numCaixas = NUM_CAIXAS_MIN;

    inicializaFilaEstrutura(&fila);
    for (int i = 0; i < NUM_CAIXAS_MAX; i++) {
        inicializaCaixa(&caixas[i], i + 1);
    }

    // Simulação de chegada de clientes e atendimento
    // Isso deve ser adaptado para uma simulação real com dados reais

    time_t inicio, fim;
    time(&inicio);
    int tempoTotalSimulacao = 3600; // 1 hora de simulação
    int tempoDecorrido = 0;

    while (tempoDecorrido < tempoTotalSimulacao) {
        // Simula a chegada de clientes a cada minuto
        for (int i = 0; i < 10; i++) {
            insereCliente(&fila, rand() % 1000, rand() % 300); // tempo de espera aleatório até 5 minutos
        }

        // Simula o atendimento
        for (int i = 0; i < numCaixas; i++) {
            if (!listaVazia(fila.fila)) {
                removeCliente(&fila);
                caixas[i].totalAtendimentos++;
                caixas[i].tempoTotalAtendimento += rand() % 300; // tempo de atendimento aleatório até 5 minutos
            }
        }

        time(&fim);
        tempoDecorrido = difftime(fim, inicio);

        // A cada 15 minutos, verifica a necessidade de abrir ou fechar caixas
        if (tempoDecorrido % (INTERVALO_OBSERVACAO * 60) == 0) {
            gerenciarCaixas(&fila, caixas, &numCaixas);
        }
    }

    printf("Tempo médio de atendimento do dia: %.2f segundos\n", tempoMedioAtendimento(caixas, numCaixas));
    printf("Tempo de espera atual: %.2f segundos\n", tempoEsperaAtual(&fila));

    return 0;
}

