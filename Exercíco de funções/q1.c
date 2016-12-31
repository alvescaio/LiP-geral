/*
 * q1.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>

int divisivel(int x, int y){
	
	if(y == 0){
		
		return 0;
		
	}else if(x % y == 0){
		
		return 1;
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	int x = 2, y = 0;
	
	if(divisivel(x,y)){
		printf("%i é divisível por %i", x, y);
	}else{
		printf("%i não é divisível por %i", x, y);
	}
	
	return 0;
}

