#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacion.h"
#include "operacoes.c"

/* -------------------------------------------------------------------- */
int main() {
    No *vagas;
    int i, op, nroVeiculo = 0, nro;
    char placa[8];

    inicializaPilha(&vagas);

    while(1) {
        printf("\nDIEGO'S PARKING HALL\n");
        printf("1 - Entrada de um novo carro\n");
        printf("2 - Saida do ultimo carro\n");
        printf("3 - Saida de um carro especifico\n");
        printf("4 - Exibe carros estacionados\n");
        printf("5 - Encerra\n");
        scanf("%d", &op);
        if(op == 5)
            break;

        switch(op) {
            case 1:
                if (nroVeiculo < 18) {
                    nroVeiculo++;
                    printf("Digite a placa do carro: ");
                    scanf("%s", placa);
                    push(&vagas, nroVeiculo, placa);
                } else {
                    printf("Estacionamento cheio!\n");
                }
                break;
            case 2:
                if (!listaVazia(vagas)) {
                    pop(&vagas);
                    nroVeiculo--;
                } else {
                    printf("Estacionamento vazio!\n");
                }
                break;
            case 3:
                printf("Numero do carro a ser removido: ");
                scanf("%d", &nro);
                if (nro <= nroVeiculo) {
                    manobra(&vagas, nro);
                    nroVeiculo--;
                } else {
                    printf("Carro não encontrado!\n");
                }
                break;
            case 4:
                if (!listaVazia(vagas)) {
                    imprimePilha(vagas);
                } else {
                    printf("Estacionamento vazio!\n");
                }
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
} /* fim da função main */

