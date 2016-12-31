/*
 * Q2.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 */


#include <stdio.h>
#include <string.h>

int palindromo(char *palavra, int tam){
	int isPali = 1;
	int i;
	if(tam % 2 == 0){
		for(i = 0; i < (tam/2); i++){
			if(strupr(palavra[i]) != strupr(palavra[(tam-1)-i])){
				isPali = 0;
				break;
			}
		}
	}else{
		for(i = 0; i < (tam-1)/2; i++){
			if(strupr(palavra[i]) != strupr(palavra[(tam-1)-i])){
				isPali = 0;
				break;
			}
		}
	}
	return isPali;
}
	


int main(int argc, char **argv)
{
	
	char palavra[10];
	scanf("%s", &palavra);
	
	if(palindromo(palavra, strlen(palavra))){
		printf("É palíndromo");
	}else{
		printf("Não é palíndromo");
	}
	
	
	return 0;
}

