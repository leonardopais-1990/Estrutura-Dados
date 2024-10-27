#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define QDEUF 27

typedef struct _No{
    char uf[3];
    float ano2016;
    float ano2017;
    float ano2018;
    float ano2019;
    float ano2020;
    struct _No *pai;
    struct _No *esq;
    struct _No *dir;
} No;

void inicializar(No **raiz) {
    *raiz = NULL;
}

int estaVazia(No *raiz) {
    if (raiz == NULL) 
        return 1;
    return 0;
}

void ExibirTodasemOrdem(No *raiz) {
    if (!estaVazia(raiz)) {
        ExibirTodasemOrdem(raiz->esq);

        printf("%s\n", raiz->uf);
        printf("2016 - %.2f%%\n", raiz->ano2016);
        printf("2017 - %.2f%%\n", raiz->ano2017);
        printf("2018 - %.2f%%\n", raiz->ano2018);
        printf("2019 - %.2f%%\n", raiz->ano2019);
        printf("2020 - %.2f%%\n\n", raiz->ano2020);

        ExibirTodasemOrdem(raiz->dir);
    }
}

No* pesquisar(No *raiz, char estado[]) {
    No *aux = raiz;
    for (int ch=0; ch<3; ch++) estado[ch] = toupper(estado[ch]);

    while (aux != NULL) {
        if (strcmp(aux->uf, estado) == 0)
            return aux;
        else if (strcmp(estado, aux->uf) < 0)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return NULL;
}
;

void inserirUF(No **raiz, No temp) {
    No *novo = (No*) malloc(sizeof(No));
    No *aux;
    No *papai;

    strcpy(novo->uf, temp.uf);
    novo->ano2016 = temp.ano2016;
    novo->ano2017 = temp.ano2017;
    novo->ano2018 = temp.ano2018;
    novo->ano2019 = temp.ano2019;
    novo->ano2020 = temp.ano2020;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;

    if (estaVazia(*raiz)) {
        *raiz = novo;
        return;
    }
    
    aux = *raiz;
    while (aux != NULL) {
        papai = aux;
        if (strcmp(temp.uf, aux->uf) < 0)
            aux = aux->esq;
        else if (strcmp(temp.uf, aux->uf) > 0)
            aux = aux->dir;
        else {
            printf("Nao eh possivel incluir o novo no\n");
            return;
        }
    }

    if (strcmp(temp.uf, papai->uf) < 0)
        papai->esq = novo;
    else
        papai->dir = novo;
    novo->pai = papai;

    return;
}

No* acharMaior(No *raiz) {
    No *atual = raiz;

    if (!estaVazia(raiz)) {
        while (atual->dir != NULL) atual = atual->dir;
    }

    return atual;
}

void remover(No **raiz, char chaveRemover[]) {
    No* atual;
    No* maior;
    char estado[3];

    if (estaVazia(*raiz)) return;

    atual = pesquisar(*raiz, chaveRemover);
    if (atual == NULL) {
        printf("Nó %s não encontrado\n", chaveRemover);
        return;
    }    

    if (atual->esq == NULL && atual->dir == NULL) {
        if (atual->pai == NULL) {
            inicializar(raiz);
            free(atual);
            return;
        }

        if (strcmp(atual->uf, atual->pai->uf) < 0)
            atual->pai->esq = NULL;
        else
            atual->pai->dir = NULL;
        free(atual);
        return;
    }

    if (atual->dir == NULL || atual->esq == NULL) {
        if (atual->pai == NULL) { 
            if (atual->esq != NULL) 
                *raiz = atual->esq;
            else
                *raiz = atual->dir;
        } 
        else {
            if (atual == atual->pai->esq){ 
                if (atual->esq != NULL) {
                    atual->pai->esq = atual->esq;
                    atual->esq->pai = atual->pai;
                }
                else {
                    atual->pai->esq = atual->dir;
                    atual->dir->pai = atual->pai;
                }
            }
            else if (atual == atual->pai->dir){
                if (atual->esq != NULL) {
                    atual->pai->dir = atual->esq;
                    atual->esq->pai = atual->pai;
                }
                else {
                    atual->pai->dir = atual->dir;
                    atual->dir->pai = atual->pai;
                }
            }
        }
        free(atual);
        return;
    }

    if (atual->esq != NULL && atual->dir != NULL) {
        maior = acharMaior(atual->esq);
        strcpy(estado, maior->uf);
        remover(raiz, estado);
        strcpy(atual->uf, estado);
    }

    return;
} 

void limparBST(No **raiz) {
    No *atual = *raiz;
    if (*raiz != NULL) {
        limparBST(&atual->dir);
        limparBST(&atual->esq);
        
        printf("Limpeza do No %s\n", atual->uf);       
        free(atual);
    }

    return;
}

int quantidadeNos(No *raiz) {
    int qtd = 0;
    if (raiz != NULL) {
        qtd += quantidadeNos(raiz->esq);
        qtd += quantidadeNos(raiz->dir);

        return qtd + 1;
    }
    return 0;
}

float somaNosAno(No *raiz, int ano) {
    float soma;

    if (raiz == NULL) {
        return 0;
    }

    switch (ano)
    {
    case 2016:
        soma = raiz->ano2016;
        break;
    case 2017:
        soma = raiz->ano2017;
        break;
    case 2018:
        soma = raiz->ano2018;
        break;
    case 2019:
        soma = raiz->ano2019;
        break;
    case 2020:
        soma = raiz->ano2020;
        break;
    }

    return soma + somaNosAno(raiz->esq, ano) + somaNosAno(raiz->dir, ano);
}

float calcularMedia(No *raiz, int ano) {
    if (raiz == NULL) {
        printf("Nao eh possivel calcular media de uma arvore vazia.\n");
        return 0;
    }
    
    int qtd = quantidadeNos(raiz);
    float soma = somaNosAno(raiz, ano);
    
    return soma / qtd;
}

int main(){
    No *arvore;
    No *aux;
    No temp;

    FILE *arq;

	int op, ano;
	float media;
	char uf[3];
	
    inicializar(&arvore);

	while(TRUE){
		printf("Menu\n");
		printf("1 - Carregar dados das UFs\n");
		printf("2 - Exibir dados de todas as UFs\n");
		printf("3 - Exibir dados de uma UF\n");
		printf("4 - Excluir uma UF\n");
		printf("5 - Esvaziar a BST\n");
		printf("6 - Calcular a media brasileira em um ano especifico\n");
		printf("0 - Sair\n");
	
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);

		switch(op){
		case 1:
			arq = fopen("A04ODS392.txt", "r");	
			if (arq == NULL) {
		       printf("Problemas na abertura do arquivo A04ODS392.txt\n");
		 	   exit(0);	   
			}
				
			while(fscanf(arq, "%s %f %f %f %f %f", temp.uf, &temp.ano2016, &temp.ano2017, &temp.ano2018, &temp.ano2019, &temp.ano2020) == 6)
			    inserirUF(&arvore, temp);
						
			fclose(arq);
            printf("Arquivo importado com sucesso!\n");
			break;
				
		case 2: 
            if (!estaVazia(arvore))
                ExibirTodasemOrdem(arvore);
            else
                printf("Não é possível exibir dados de uma árvore vazia.\n");
			break;
		
		case 3:
            printf("Insira a sigla do Estado que deseja encontrar: ");
            scanf("%s", uf);

            aux = pesquisar(arvore, uf);
            if (aux != NULL) {
                printf("%s\n", aux->uf);
                printf("2016 - %.2f%%\n", aux->ano2016);
                printf("2017 - %.2f%%\n", aux->ano2017);
                printf("2018 - %.2f%%\n", aux->ano2018);
                printf("2019 - %.2f%%\n", aux->ano2019);
                printf("2020 - %.2f%%\n\n", aux->ano2020);
            }
            else {
                printf("Estado não encontrado na base de dados.\n");
            }

			break;
		
		case 4: 
            printf("Insira a UF do Estado que deseja remover: ");
            scanf("%s", uf);

            remover(&arvore, uf);
            printf("Estado %s removido com sucesso!\n", uf);            

			break;
			
		case 5: 
            limparBST(&arvore);
            inicializar(&arvore);
            printf("Arvore esvaziada com sucesso!\n");
			break;

		case 6:
            printf("Selecione um ano para calcular a media: ");
            scanf("%d", &ano);

            if (ano<2016 || ano>2020) {
                printf("Ano invalido.\n");
                break;
            }

            media = calcularMedia(arvore, ano);
            printf("A media do ano de %d eh: %.2f%%\n", ano, media);
			break;
						
		case 0: 
			exit (1);
			
		default:
			printf("Opcao invalida\n"); 
		
		}
	}
	
    return 0;

} 
