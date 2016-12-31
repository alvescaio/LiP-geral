/*
 * q6.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 */


#include <stdio.h>

void interseccao(int tamanhoA, int tamanhoB, int *A, int *B){
	
	int dimensaoC = tamanhoA;
	int C[dimensaoC];
	int i, j, k = 0;
	
	for(i = 0; i < tamanhoA; i++){
		for(j = 0; j < tamanhoB; j++){
			if(A[i] == B[j]){
				C[k] = A[i];
				k++;
			}
		}
	}
	
	printf("A = ");
	for(i = 0; i < tamanhoA; i++){
		printf("%i ", A[i]);
	}
	
	printf("\n");
	
	printf("B = ");
	for(i = 0; i < tamanhoB; i++){
		printf("%i ", B[i]);
	}
	
	printf("\n");
	
	printf("C = ");
	for(i = 0; i < k; i++){
		printf("%i ", C[i]);
	}
	
	printf("\n");
}

int main(int argc, char **argv)
{
	
	int dimensaoA = 1, dimensaoB = 1;
	
	printf("Dimensão de A: ");
	scanf("%i", &dimensaoA);
	printf("Dimensão de B: ");
	scanf("%i", &dimensaoB);
	
	int A[dimensaoA];
	int B[dimensaoB];
	int i, j;
	
	//system("cls"); //Para windows
	system("clear"); //Para linux
	
	for(i = 0; i < dimensaoA; i++){
		printf("A[%i] = ", i);
		scanf("%i", &A[i]);
		for(j = 0; j < i; j++){
			if(A[i] == A[j]){
				printf("Não repita valores, digite novamente!\n");
				i--;
			}
		}
	}
	
	//system("cls"); //Para windows
	system("clear"); //Para linux
		
	for(i = 0; i < dimensaoB; i++){
		printf("B[%i] = ", i);
		scanf("%i", &B[i]);
		for(j = 0; j < i; j++){
			if(B[i] == B[j]){
				printf("Não repita valores, digite novamente!\n");
				i--;
			}
		}
	}
	
	interseccao(dimensaoA, dimensaoB, A, B);
	
	return 0;
}

