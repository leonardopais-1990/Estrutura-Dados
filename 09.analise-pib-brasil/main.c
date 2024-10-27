#include <stdio.h>
#include <stdlib.h>
#include "Operations.c"

#define TAM_MAX 50 

int main(){
	dadosPIB fila[TAM_MAX];
	int i,nDados=0,anoPesquisado,indice;

	lerArquivo(fila,&nDados);
	quickSort(fila,0,nDados-1);

	printf("\n10 Anos de Maior Crescimento:\n");
	imprimirDados(fila,49,39);
	
	printf("\n10 Anos de Menor Crescimento:\n");
	imprimirDados(fila,0,10);	
	
	lerArquivo(fila,&nDados);
	printf("\nPesquise o PIB de um ano especifico ou digite 0 para encerrar:\n");
	while(scanf("%d",&anoPesquisado)!=0){
		if(anoPesquisado==0)
			break;
		indice=buscaBinaria(fila,0,50,anoPesquisado);
		imprimirDadoEspecifico(fila,indice);
	}

  return 0;
}
