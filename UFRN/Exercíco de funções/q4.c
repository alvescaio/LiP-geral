/*
 * q4.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int i, vet[10];

void store(){	
	//printf("Digite 10 valores separados por espaço, para serem armazenados no vetor: ");
	//scanf("%i %i %i %i %i %i %i %i %i %i", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4], &vet[5], &vet[6], &vet[7], &vet[8], &vet[9]);
	
	for(i = 0; i < 10; i++){
		printf("Vet[%i] = ", i);
		scanf("%i", &vet[i]);
	}
}

void show(){
	printf("Vet = ");
	for(i = 0; i < 10; i++){
		printf("%i ", vet[i]);
	}
}

int main(int argc, char **argv)
{
	store();
	//system(cls); // Para windows
	system("clear"); // Para linux
	show();
	
	return 0;
}

