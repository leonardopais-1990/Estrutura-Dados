#ifndef LISTA_H
#define LISTA_H

typedef struct dadosPIB{
	int ano;
	float crescimento;
} dadosPIB;

void lerArquivo(dadosPIB*,int *nDados);
void imprimirDados(dadosPIB*,int,int);
void imprimirDadoEspecifico(dadosPIB*,int);
void trocar(dadosPIB*,int,int);
int particionar(dadosPIB*,int,int);
void quickSort(dadosPIB*,int,int);
int buscaBinaria(dadosPIB*,int,int,int);

#endif
