/*
 * q1.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int suc(int n){
	if(n == 0){
		return 1;
	}
	
	return n + suc(0);
}

int main(int argc, char **argv)
{
	int n = -1;
	
	printf("O sucessor de %d é %d", n, suc(n));
	
	
	return 0;
}

