/*
 * q2.c
 * 
 * Copyright 2016 Caio Alves <caio_alves@outlook.com>
 * 
 * Problema: dado um inteiro positivo n, verificar e mostrar se n é primo
 * 
 */


#include <stdio.h>

	int primo(int n){
		int i;
		for(i = 2; i < n; i++){
			if(n % i == 0){
				return 0;
			}
		}
		return 1;
	}

int main(int argc, char **argv)
{
	
	int n; 
	
	printf("Digite um número: ");
	scanf("%i", &n);
	
	do{
		
		if(n <= 0){
			printf("O número deve ser positivo: ");
			scanf("%i", &n);
		}
		
	}while(n <= 0);
	
	if(primo(n)){
		printf("%i é um número primo", n);
	}else{
		printf("%i não é um número primo", n);
	}
	
	return 0;
}

