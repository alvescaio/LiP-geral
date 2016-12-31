/*
 * Exemplo2Alloc.c
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	
	int *p = (int *) realloc(NULL, 10*sizeof(int));	
	
	free(p);
	
	int i;
	for(i = 0; i < 300; i++){
		if(i < 3){
			p[i] = 2;
		}
		printf("%i ", p[i]);
	}
	
	return 0;
}

