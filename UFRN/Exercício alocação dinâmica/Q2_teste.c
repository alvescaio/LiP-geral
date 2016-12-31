#include <stdio.h>
#include <stdlib.h>

struct aluno{
    float media;
    int faltas;
};

typedef struct aluno aluno;


void lerVetor(aluno *p, int n){
    int i;
    printf("\nDigite as informações dos alunos: \n");
    for(i = 0; i < n; i++){
        printf("\nAluno %i: ",i+1);
        printf("\nMedia: ");
        scanf("%f", &p[i].media); 
        printf("Faltas: ");
        scanf("%d", &p[i].faltas); 
	}
}

void imprimeVetor(aluno *p, int n){
    int i;
    printf("\nInformações cadastradas: \n");
    for(i = 0; i < n; i++){
        printf("\nAluno %i: ",i+1);
        printf("\nMedia: %.2f", p[i].media);
        printf("\nFaltas: %d", p[i].faltas);
    }
}

void main()
{

    int n;

    do{
        printf("Quantos alunos deseja cadastrar? ");
        scanf("%d", &n);
    }while(n < 1);

    aluno *p = (aluno *) calloc(n, sizeof(aluno));

    if(p == NULL){
        printf("\nNão há espaço suficiente na memória!");
    }else{
        lerVetor(p, n);
        imprimeVetor(p, n);
    }

    free(p);

}
