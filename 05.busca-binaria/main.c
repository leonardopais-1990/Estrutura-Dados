#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int RA;
	float A1;
	float A2;
} Aluno;

int QTDALUNOS(){
	FILE *arquivo;
	Aluno student;
	int n;
	
	if((arquivo = fopen("A05ordenadoRA.txt","r"))==NULL){
		printf("Nao abre");
		exit(1);
	}
	
	while(! feof(arquivo)){
		fscanf(arquivo,"%d",&student.RA);
		fscanf(arquivo,"%f",&student.A1);
		fscanf(arquivo,"%f",&student.A2);
		n++;
	}
	return n;
}

void preencheVetor (Aluno *vetor,int tam) {
    FILE *arquivo;
    Aluno student;
    int n;

    if((arquivo = fopen("A05ordenadoRA.txt", "r"))== NULL){
    	printf("Nao abre");
    	exit(1);    	
	}

    for(n=0;n<tam;n++) {
        fscanf(arquivo,"%d", &student.RA);
        fscanf(arquivo,"%f", &student.A1);
        fscanf(arquivo,"%f", &student.A2);
        vetor[n] = student;
    }

    fclose(arquivo);
} 

int ctrlf(Aluno *vetor,int start,int end,int key) {
    int mid=(start+end)/2;

    if(vetor[mid].RA==key)
        return mid;
    if (start>=end)
        return -1; 

    if (key<vetor[mid].RA)
        ctrlf(vetor,start,mid-1,key);
    else
        ctrlf(vetor,mid+1,end,key);
}

int main() {	
    int tam,key,n,indfound;
    
    printf("Carregando lista de alunos...");
    tam=QTDALUNOS();
    Aluno student[tam];
	preencheVetor(student,tam);
    
    printf("\nDigite um RA: ");
    scanf("%d",&key);
    
    indfound=ctrlf(student,0,tam-1,key);

	if(indfound==-1){
		printf("Nao achou.\n");
	}else{
		printf("\nAluno: %d",student[indfound].RA);
		printf("\nNota final: %.1f",((student[indfound].A1+(student[indfound].A2*2))/3));		
	}

    return 0;
}
