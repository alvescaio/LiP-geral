/*
 * Q1.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>


void lerVetor(int *p, int tam){
	int i;
	printf("\nDigite os valores para o vetor: \n");
	for(i = 0; i < tam; i++){
		printf("%do elemento: ", i+1);
		scanf("%d", &p[i]);
	}
}

void imprimeVetor(int *p, int tam){
	int i;
	printf("\nElementos do vetor: ");
	for(i = 0; i < tam; i++){
		printf("%d ", p[i]);
	}
}

void operacaoFinal(int *p, int tam){
	int i;
	int soma = 0;
	
	for(i = 0; i < tam; i++){
		if(p[i] % 2 != 0){
			soma = soma + p[i];
		}
	}
	
	printf("\nA soma dos elementos ímpares é %d ", soma);
}

int main(int argc, char **argv)
{
	
	int tam;
	int *p;
	
	do{
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &tam);
	}while(tam < 1); // O tamanho do vetor deve ser maior que zero para sair do do/while

	p = (int *) calloc(tam, sizeof(int)); // Aloca o espaço de memória necessário para o vetor de tamanho "tam"
	
	if(p == NULL){
		printf("\nNão há espaço suficiente na memória! ");
	}else{
		lerVetor(p, tam);
		imprimeVetor(p, tam);
		operacaoFinal(p, tam);				
	}
	
	free(p);
	
	return 0;
}

