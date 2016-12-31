/*
 * q5.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int soma(int tam, int *vet){
	if(tam == 1){
		return vet[0];
	}
	
	return vet[tam-1] + soma((tam-1), vet);
}

int main(int argc, char **argv)
{
	int i, tam = 4;
	int vet[tam];
	
	printf("Vet = ");
	for(i = 0; i < tam; i++){
		vet[i] = random()%10;
		printf("%d ", vet[i]);
	}
	
	printf("\nSoma dos elementos: %d", soma(tam, vet));
	
	
	return 0;
}

