#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void lerArquivo(dadosPIB *dados,int *nDados){
	int i=0;
	FILE *arquivo = fopen("economia.txt","r");
	if(arquivo == NULL){
		printf("Erro ao abrir arquivo.\n");
		exit(1);
	}
	while(i<50){
		fscanf(arquivo,"%d %f",&dados[i].ano,&dados[i].crescimento);
			i++;	
	}
	fclose(arquivo);
	*nDados=i;
}

int filaVazia(dadosPIB *fila){
	if(fila == NULL)
		return 1;
	return 0;
}

void imprimirDados(dadosPIB *fila,int inicio,int final){
	int i;
	if(inicio<final){
		for(i=inicio;i<final;i++)
		    printf("Ano: %d Taxa de Crescimento: %.2f%%\n", fila[i].ano, fila[i].crescimento);
	}else{
		for(i=inicio;i>final;i--)
		    printf("Ano: %d Taxa de Crescimento: %.2f%%\n", fila[i].ano, fila[i].crescimento);
	}
}

void imprimirDadoEspecifico(dadosPIB *fila,int indice){
	if(indice==-1){
		printf("Ano nao encontrado.\n");
		return;
	}
	printf("Ano: %d Taxa de Crescimento: %.2f%%\n", fila[indice].ano, fila[indice].crescimento);
}

void trocar(dadosPIB *fila,int i,int j) {
  dadosPIB aux=fila[i];
  fila[i]=fila[j];
  fila[j]=aux;
}

int particionar(dadosPIB *fila,int inicio,int fim){
  int pivo;
  int i,j;
  pivo=fila[fim].crescimento;
  i=inicio-1;
  for(j=inicio;j<fim;j++) {
    if(fila[j].crescimento<=pivo){
      i++;
      trocar(fila,i,j);
    }
  }
  trocar(fila,i+1,fim);
  return i+1;
}

void quickSort(dadosPIB *fila,int inicio,int fim){
	int pivo;
	if(inicio<fim) {
    	pivo=particionar(fila,inicio,fim);
    	quickSort(fila,inicio,pivo-1);
    	quickSort(fila,pivo+1,fim);
  }
}

int buscaBinaria(dadosPIB *fila,int inicio,int final,int anoPesquisado){
	int meio=(inicio+final)/2;
	if(fila[meio].ano==anoPesquisado)
		return meio;
	if(inicio>=final)
		return -1;
	if(anoPesquisado<fila[meio].ano)
		buscaBinaria(fila,inicio,meio-1,anoPesquisado);
	else
		buscaBinaria(fila,meio+1,final,anoPesquisado);
}
