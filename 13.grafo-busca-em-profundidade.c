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

void buscaP(int g[N][N],int vTrabalho,int visitados[N]){
    int w;
 
    visitados[vTrabalho]=TRUE;
    printf("%d ",vTrabalho);

    for(w=0;w<N;w++){
        if(g[vTrabalho][w]==1 && visitados[w]==0){
            buscaP(g,w,visitados);
        }
    }
}

void buscaEmProfundidade(int g[N][N],int vInicio){
    int visitados[N];
  
    for(int i=0;i<N;i++){
        visitados[i]=FALSE;
    }
    printf("\nPercurso da busca em profundidade: ");

    buscaP(g,vInicio,visitados);
    printf("\n");
}


int main(){
	
	int grafo[N][N] = { {0, 1, 1, 0, 0, 0},
	                    {1, 0, 1, 1, 0, 1},
	                    {1, 1, 0, 1, 1, 0},
	                    {0, 1, 1, 0, 1, 1},
	                    {0, 0, 1, 1, 0, 0},
	                    {0, 1, 0, 1, 0, 0} };

  buscaEmProfundidade(grafo,5);
	
	return 0;
}
