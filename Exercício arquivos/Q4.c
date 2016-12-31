/*
 * Q4.c
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	
	FILE *p;
	char nomeArquivo[20] = "arquivoQ4.txt";
	
	char nome[50];
	float nota1, nota2;
	float media;
	
	if((p = fopen(nomeArquivo, "r")) == NULL){
		printf("Não foi possivel abrir o arquivo!");
		exit(1);
	}
		
	int cont = 0;
	while((fgets(nome, 50, p)) != NULL){
		if(cont % 2 == 0){
			fscanf(p, "%f", &nota1);
			fscanf(p, "%f", &nota2);
			
			media = (nota1 + nota2)/2;
			
			if(media >= 7){
				printf("\nAluno: %s\n", nome);
				printf("Nota 1: %.2f\n", nota1);
				printf("Nota 2: %.2f\n", nota2);
				printf("Media: %.2f\n", media);
			}
		}
		cont++;
	}
		
	return 0;
}

