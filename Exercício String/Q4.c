/*
 * Q4.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>

 * 
 */


#include <stdio.h>
#include <string.h>
int minus(char *palavra, int tam){
int i, j;
int cont=0;
	char vet[27]= "abcdefghijklmnopkrstuvwxyz";
	for(i=0; i<tam; i++){
		for(j=0;j<26; j++){
			if(palavra[i]==vet[j]){
				cont++;
				}
			}
		
		}
	return cont;
	
	}

int main(int argc, char **argv){
	
	char palavra[10]; 
	scanf("%s", &palavra);
	printf("A palavra possui %d letras minusculas", minus (palavra, strlen(palavra)));

	
	return 0;
}

