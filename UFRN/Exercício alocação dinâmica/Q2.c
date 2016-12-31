/*
 * Q2.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 */


#include <stdio.h>
#include <stdlib.h>

struct Aluno{
	float media;
	int faltas;
};

typedef struct Aluno Aluno;


void lerVetor(Aluno *p, int n){
	int i;
	printf("\nDigite as informações dos alunos: \n");
	for(i = 0; i < n; i++){
		printf("\nAluno %i: ",i+1);
		printf("\nMedia: ");
		scanf("%f", &p[i].media); // Caso seja requerido, fazer um do/while para restringir que 0 <= media <= 10
		printf("Faltas: ");
		scanf("%d", &p[i].faltas); // Caso seja requerido, fazer um do/while para restringir que faltas >= 0
	}
}

void imprimeVetor(Aluno *p, int n){
	int i;
	printf("\nInformações cadastradas: \n");
	for(i = 0; i < n; i++){
		printf("\nAluno %i: ",i+1);
		printf("\nMedia: %.2f", p[i].media);
		printf("\nFaltas: %d", p[i].faltas);
	}
}

int main(int argc, char **argv)
{
	
	int n;
	
	do{
		printf("Quantos alunos deseja cadastrar? ");
		scanf("%d", &n);
	}while(n < 1);
	
	Aluno *p = (Aluno *) calloc(n, sizeof(Aluno));
	
	if(p == NULL){
		printf("\nNão há espaço suficiente na memória!");
	}else{
		lerVetor(p, n);
		imprimeVetor(p, n);
	}
	
	free(p);
	
	return 0;
}

