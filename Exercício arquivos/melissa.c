#include<stdio.h>
#include<stdlib.h>


int main(){
    FILE *arq;
    char nome[50], i;
    float nota1, nota2;
    
	arq = fopen("t1.txt", "w");
	printf("Entre nome e nota de alunos : \n");
	for(i = 0; i < 2; i++) {
	     printf("Aluno 1, Entre nome: ");
		 scanf("%s", &nome);
		 printf("Aluno 1, Entre com a nota 1: ");
		 scanf("%f", &nota1);
		 printf("Aluno 1. Entre com a nota 2: ");
		 scanf("%f", &nota2);
	     fputs(nome, arq);
	     fputs("\n", arq);
		 fprintf(arq, "%f\n", nota1);
		 fprintf(arq, "%f\n", nota2);
    }
    
    fclose(arq);
    
    arq = fopen("t1.txt", "r");
    
        fscanf(arq, "%s", &nome);
        printf("Nome: %s", nome);
        
        fscanf(arq, "%f", &nota1);
        printf("Nota 1: %f", nota1);
        
        fscanf(arq, "%f", &nota2);
        printf("Nota 2: ", nota2);
    
	fclose(arq);
	return 0;
}
