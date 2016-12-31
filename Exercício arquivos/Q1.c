/*
 * Q1.c
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpaBuffer(void){
	 char c;
	 while((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char **argv)
{
	
	char nome[20];
	char nomeArquivo[20] = "arquivoQ1.txt";
	int i;
	
	FILE *p = fopen(nomeArquivo, "w");
	
    if (p == NULL){
        printf("Erro! Impossível abrir o arquivo!\n");
        exit(1);
    }
	
	for(i = 0; i < 2; i++){
		
		printf("Nome e sobrenome do aluno %d:\n> ", (i+1));
		gets(nome);		
		
		fprintf(p, "%s\n", nome);
	} 
	
	printf("\nDados armazenados com sucesso!\n");
	
	fclose(p);
	
	return 0;
}

