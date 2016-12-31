/*
 * q6.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int soma(int n){
	if(n<10){
		return n;
	}	
	return (n%10) + soma(n/10);
}

int main(int argc, char **argv)
{
	int n = 0;
	
	printf("Soma dos algarismos de %d é %d", n, soma(n));
	
	return 0;
}

