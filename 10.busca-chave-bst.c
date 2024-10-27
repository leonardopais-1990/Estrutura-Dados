#include <stdio.h> 
#include <stdlib.h>

typedef struct _no
{
    int id;
    struct _no *esq; 
    struct _no *dir;
    struct _no *pai;
} No;

void inicializar (No **raiz) {
    *raiz = NULL;
}

int estaVazia(No *raiz){
    if(raiz == NULL)
        return 1;

    return 0;
}

No* pesquisar(No *raiz, int valorPesquisado){

    No *aux;
    int count = 0;

    aux = raiz;
    while(!estaVazia(raiz)){   

        if(aux->id==valorPesquisado){
            printf("Valor encontrado: %d, na tentativa %d ", valorPesquisado,count);
            return aux;
    }   else if(aux->id>valorPesquisado){
            aux = aux->esq;
        }else {
            aux = aux->dir;
        }
        count++;
    }
    printf("Valor não encontrado");    
}

void inserir(No **raiz, int chave) {
    No *novo;
    No *aux;
    No *papai;

    novo = (No*) malloc(sizeof(No));
    novo->id = chave; //ponteiro de memória
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    
    if(estaVazia(*raiz)){
        *raiz = novo;
        return;
    }

     aux = *raiz;
     while(aux != NULL){
        papai = aux;
        if(chave < aux->id)
            aux = aux->esq;
        else if(chave > aux->id)
            aux = aux->dir;
        else  {
            printf("Nao eh possivel incluir o novo noh \n");
            return;
        }  
     }

       if(chave < papai->id)
            papai->esq = novo;
       else
        papai->dir = novo;

        novo->pai = papai;

}

int main() {

    No *arvore;
    No *aux;
	  int ret;
	
    inserir(&arvore, 50);
    inserir(&arvore, 40);
    inserir(&arvore, 30);
    inserir(&arvore, 60);
    inserir(&arvore, 45);
    inserir(&arvore, 30);
    inserir(&arvore, 14);
    inserir(&arvore, 65);
    inserir(&arvore, 78);
    inserir(&arvore, 55);
    inserir(&arvore, 52);

    printf("\nBusca pelo Noh 52 ");
    if ((aux = pesquisar(arvore, 52)) != NULL)
        printf(" -> %d encontrado!\n", aux->id);
    else
        printf(" -> Noh NAO encontrado!\n");

    printf("Busca pelo Noh 53 ");
    if ((aux = pesquisar(arvore, 53)) != NULL)
        printf(" -> %d encontrado!\n", aux->id);
    else
        printf(" -> Noh NAO encontrado!\n");

    return 0;
}
