/*
 * q5.c
 * 
 * Copyright 2016 Caio Alves <caio_alves@outlook.com>
 * 
 * Problema: calcular o valos de n^3 e imprimir da seguinte forma: 
 * Exemplo para n = 4: 13 + 15 + 17 + 19 = 64
 * 
 */


#include <stdio.h>

int n = 5;

int main(int argc, char **argv)
{
	
	int i, result = 1;
	int primeiroImpar, numeroDoMeio;
	
	for(i = 0; i < 3; i++){
		result = result * n;
	}
	
	numeroDoMeio = result / n;
	
	if(numeroDoMeio % 2 == 0){
		primeiroImpar = numeroDoMeio - (n-1);
	}else{
		primeiroImpar = numeroDoMeio - (n-1);
	}
	
	
	result = primeiroImpar;
	int somaImpares = result;
	
	printf(" %i ", result);
	
	for(i = 1; i < n; i++){
		result = result + 2;
		printf("+ %i ", result);
		somaImpares = somaImpares + result;
	}
	printf(" = %i", somaImpares);
	
	return 0;
}

