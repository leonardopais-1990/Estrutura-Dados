#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacion.h"

/* Inicializa a pilha */
void inicializaPilha(No** pilha) {
    *pilha = NULL;
}

/* Verifica se a pilha está vazia */
int listaVazia(No* pilha) {
    return (pilha == NULL);
}

/* Imprime a pilha */
void imprimePilha(No* pilha) {
    No* temp = pilha;
    while (temp != NULL) {
        printf("Carro %d - Placa: %s\n", temp->nroCarro, temp->placa);
        temp = temp->proximo;
    }
}

/* Insere um elemento na pilha */
void push(No** pilha, int nroCarro, char* placa) {
    No* novo = (No*)malloc(sizeof(No));
    novo->nroCarro = nroCarro;
    strncpy(novo->placa, placa, 8);
    novo->proximo = *pilha;
    *pilha = novo;
}

/* Remove o elemento do topo da pilha */
void pop(No** pilha) {
    if (!listaVazia(*pilha)) {
        No* temp = *pilha;
        *pilha = (*pilha)->proximo;
        free(temp);
    }
}

/* Manobra a pilha para remover um carro específico */
void manobra(No** pilha, int nroCarro) {
    No* temp = *pilha;
    No* anterior = NULL;
    No* pilhaAux = NULL;

    while (temp != NULL && temp->nroCarro != nroCarro) {
        push(&pilhaAux, temp->nroCarro, temp->placa);
        pop(pilha);
        temp = *pilha;
    }

    if (temp != NULL) {
        pop(pilha); // Remove o carro desejado
    }

    while (!listaVazia(pilhaAux)) {
        push(pilha, pilhaAux->nroCarro, pilhaAux->placa);
        pop(&pilhaAux);
    }
}

