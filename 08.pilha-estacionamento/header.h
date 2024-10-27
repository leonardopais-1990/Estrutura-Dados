#ifndef PILHA_H
#define PILHA_H

/* Estrutura do nó da pilha */
typedef struct _no {
    int nroCarro;
    char placa[8];
    struct _no *proximo;
} No;

/* Declarações das funções de pilha */
void inicializaPilha(No** pilha);
int listaVazia(No* pilha);

void imprimePilha(No* pilha);

void push(No** pilha, int nroCarro, char* placa);
void pop(No** pilha);

void manobra(No** pilha, int nroCarro);

#endif

