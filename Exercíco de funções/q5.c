/*
 * q5.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int maior(int x, int y){
	
	if(x > y || x == y){
		return x;
	}
	
	return y;
}	

int menor(int x, int y){
	
	if(x < y || x == y){
		return x;
	}
	
	return y;
}

int main(int argc, char **argv)
{
	int vet[10] = {4,3,5,6,7,8,13,4,5,10};
	int i;
	int maiorn = vet[0];
	int menorn = vet[0];
	
	for(i = 0;i < 10; i++){
		if(maior(vet[i], maiorn) == vet[i]){
			maiorn = vet[i];
		}
		if(menor(vet[i], menorn) == vet[i]){
			menorn = vet[i];
		}
	}
	
	printf("Maior elemento do vetor: %i", maiorn);
	printf("\nMenor elemento do vetor: %i\n", menorn);
	
	return 0;
}

