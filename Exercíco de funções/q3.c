/*
 * q3.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int eqvalue(n){
	int vet[10] = {1, 3, 6, 4, 7, 3, 5, 7, 1, 0};
	int i, cont = 0;
	int posicao = -1;
	
	for(i = 0; i < 10; i++){
		if(vet[i] == n){
			cont++;
			posicao = i;
		}
	}	
	if(posicao == -1){
		printf("%i não apareceu no vetor", n);
	}else{
		printf("Posição que %i aparece por último: %i", n, posicao);
	}
	
	return cont;
}

int main(int argc, char **argv)
{
	int n = 3;
	
	printf("\n%i aparece no vetor %i vezes",n, eqvalue(n));
	
	return 0;
}

