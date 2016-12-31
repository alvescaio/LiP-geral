/*
 * q4.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int menor(int tam, int *vet){
	if(tam == 1){
		return vet[0];
	}else{
		int x = menor(tam-1, vet);
		
		if(x > vet[tam-1]){
			return x;		
		}else{
			return vet[tam-1];
		}
	}		 
}

int main(int argc, char **argv)
{

	int i, tam = 4;
	int vet[tam];
	
	printf("Vet = ");
	for(i = 0; i < tam; i++){
		vet[i] = rand() % 10;
		printf("%d ", vet[i]);
	}
	
	printf("\nMaior valor: %d", menor(tam, vet));
	
	return 0;
}

