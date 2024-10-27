#include <stdio.h>
#include <stdlib.h> 

#define N 6
#define TRUE 1
#define FALSE 0

typedef struct _no {
	int id;
	struct _no *proximo;
} NoLista;


void imprimeGrafo(int g[N][N]){
	int lin, col;
	printf("MATRIZ DE ADJACENCIA DO GRAFO\n");
	
	for(lin=0; lin<N; lin++){
		for(col=0; col<N; col++){
			printf("%d\t", g[lin][col]);
		}
		printf("\n");	
	}
}

void inicializaLista (NoLista **lista) {
    *lista = NULL;
}

int estaVazia (NoLista *lista) {
    return (lista == NULL);
}

void insereFinal (NoLista **lista, int id) {
    NoLista *atual = *lista;
    NoLista *novo;
    
    novo = (NoLista*) malloc (sizeof(NoLista));
    novo->id = id;

    if (estaVazia(*lista)) {
        *lista = novo;
        novo->proximo = NULL;
        return;
    }

    while (atual->proximo != NULL)
        atual = atual->proximo;

    atual->proximo = novo;
    novo->proximo = NULL;

}

int removeInicio (NoLista **lista) {
    NoLista *atual = *lista;
    int id;

    if (estaVazia(*lista))
        return -1;

    *lista = atual->proximo;
    id = atual->id;
    free(atual);
    return id;

}

void buscaEmLargura(int g[N][N], int x){
	NoLista *fila;
	int visitados[N];
    int v, w;

    inicializaLista(&fila);

    for (int i=0; i<N; i++) 
        visitados[i]=0;

    visitados[x]=1;

    insereFinal(&fila,x);
    printf("\nPercurso da busca em largura: %d", x);

    while (!estaVazia(fila)) {
        v = removeInicio(&fila);

        for (w=0; w<N; w++) {
            if (g[v][w]==1 && visitados[w]==0) {
                visitados[w]=1;
                insereFinal(&fila, w);
                printf(" %d", w);
            }
        }
    }
    printf("\n");
}

int main(){	
	int grafo[N][N] = { {0, 1, 1, 0, 0, 0},
	                    {1, 0, 1, 1, 0, 1},
	                    {1, 1, 0, 1, 1, 0},
	                    {0, 1, 1, 0, 1, 1},
	                    {0, 0, 1, 1, 0, 0},
	                    {0, 1, 0, 1, 0, 0} };
	                  
	imprimeGrafo(grafo);
	buscaEmLargura(grafo, 2);	
	
	return 0;
}
