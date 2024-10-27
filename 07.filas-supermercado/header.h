#ifndef FILA_H
#define FILA_H


/* estrutura do noh da fila */
typedef struct _no {
    int nroAtendimento;
    struct _no *proximo;
} No;


/* declaracoes das funcoes de fila */
void inicializaFila (No**);
int listaVazia (No*);

void imprimeFila (No*);

void insereElemento (No**, int);
void removeElemento (No**);
No* pesquisaElemento (No*, int);

void esvaziarFila (No**);


#endif
