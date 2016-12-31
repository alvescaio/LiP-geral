/*
 * q3.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int fib(int n){
	if(n <= 0){
		return 0;
	}
	
	if(n == 1 || n == 2){
		return 1;
	}
	
	return fib(n-1) + fib(n-2);
}

int main(int argc, char **argv)
{
	int n = 6;
	
	printf("O %d termo é %d", n, fib(n));
	
	return 0;
}

