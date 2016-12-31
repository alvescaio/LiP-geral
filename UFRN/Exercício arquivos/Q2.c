/*
 * Q2.c
 * 
 */


#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char nomeArquivo[20] = "arquivoQ2.txt";
	
	FILE *p = fopen(nomeArquivo, "w");
	
	if(p == NULL){
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	int A[5], B[5], i;

	for(i = 0; i < 5; i++){
		
		printf("Digite o %io numero inteiro: \n> ", (i+1));
		scanf("%i", &A[i]);
		
		fprintf(p, "%i\n", A[i]);
		
	}
	
	fclose(p);
	
	p = fopen(nomeArquivo, "r");
	
	for(i = 0; i < 5; i++){
		fscanf(p, "%d", &B[i]);
		
		if(A[i] != B[i]){
			printf("%do valor - Erro na gravação!\n", i);
		}else{
			printf("%do valor - Gravado com sucesso!\n", i);
		}
		
	}
	
	fclose(p);
	
	
	return 0;
}

