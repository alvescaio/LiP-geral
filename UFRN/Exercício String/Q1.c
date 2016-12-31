/*
 * Q1.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 */


#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char palavra[50];
	
	printf("Digite uma palavra: ");
	scanf("%[a-zA-Z]s", &palavra);
	setbuf(stdin, NULL);
	
	printf("A palavra invertida é: ");
	int i;
	
	for(i = strlen(palavra); i >= 0; i--){
		printf("%c", palavra[i]);
	}	
	return 0;
}

