/*
 * q4.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * Problema: calcular o valor de E usando a série E = 1/1! - 1/2! + 1/3!
 * 
 */


#include <stdio.h>

#define n 10

int main(int argc, char **argv)
{
	float E = 1, temp;
	int i, j;
	
	for(i = 2; i <= n; i++){
		
		temp = 1;
		for(j = i; j > 1; j--){
			
			temp = temp * j;
			
		}
		
		if(i % 2 == 0){
			E = E - (1/temp);
		}else{
			E = E + (1/temp);
		}
	}
	
	printf("E = %f", E);
	
	
	return 0;
}

