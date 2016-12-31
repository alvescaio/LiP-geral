/*
 * Q3.c
 * 
 */


#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *p;
	char nomeArquivo[20] = "arquivoQ3.txt";
	
	p = fopen(nomeArquivo, "r");
	
	if(p == NULL){
		printf("Arquivo inexistente!");
		exit(1);
	}
	
	int cont = 0;
	char c;
	
	while((c = fgetc(p)) != EOF){
		if(c != '\n' && c != '\0' && c != ' ' && c != '\f' && c != '\t' && c != '\v' && c != '\r'){
			cont++;
		}
	}
	
	fclose(p);
	
	printf("Qtd de caracteres: %d", cont);
	
	return 0;
}

