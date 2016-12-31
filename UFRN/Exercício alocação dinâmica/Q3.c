/*
 * Q3.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int *alocarInt(int n){
	int *p = calloc(n, sizeof(int));
	return p;
}

void imprimeVetor(int *p, int n){
	int i;
	printf("\nVetor = ");
	for(i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
}

void liberaMemoria(int *p){
	free(p);
}

int main(int argc, char **argv)
{
	int n, i; 
	int *vetor;
	
	do{
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &n);
	}while(n <= 0);
	
	vetor = alocarInt(n);
	
	if(vetor == NULL){
		printf("\nNão há espaço suficiente na memória!");
		system("PAUSE");
	}else{
		for(i = 0; i < n; i++){
			printf("Vet[%d] = ", i);
			scanf("%d", &vetor[i]);
		}
		imprimeVetor(vetor, n);
	}
	
	liberaMemoria(vetor);
	
	return 0;
}

