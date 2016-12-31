/*
 * q3.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * Problema: realizar a soma de todos os números entre um intervalo indicado pelo usuário
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	int inicial, final;
	
	printf("Digite o valor inicial: ");
	scanf("%i", &inicial);
	printf("Digite o valor final: ");
	scanf("%i", &final);
	
	do{
		if(inicial > final){
			printf("O valor inicial deve ser menor que o valor final!");
			printf("\nDigite novamente o valor inicial: ");
			scanf("%i", &inicial);
			printf("Digite novamete o valor final: ");
			scanf("%i", &final);
		}
	}while(inicial > final);
	
	int i, soma = 0;
	for(i = inicial; i <= final; i++){
		soma = soma + i;
	}
	
	printf("A soma de todos os números no intervalo entre %i até %i é %i", inicial, final, soma);
	
	
	return 0;
}

