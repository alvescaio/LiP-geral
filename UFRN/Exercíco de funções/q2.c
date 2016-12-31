/*
 * q2.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int div(int x, int y){
	
	if(y == 0){
		return -1;
	}
	
	int divisor, cont = 0;
	
	divisor = x;
	
	while(1){
		if(divisor % y == 0){
			cont++;
			divisor = divisor / y;
		}else{
			break;
		}
	}	

	return cont;
}

int main(int argc, char **argv)
{
	int x = 10, y = 0;
	int result = div(x,y);
	
	if(result == -1){
		printf("Não é possível calcular");
	}else{
		printf("%i pode ser divisível por %i, %i vezes", x, y, result);
	}
		
	return 0;
}

