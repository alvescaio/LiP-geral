#include <iostream>
#include <string.h>
using namespace std;

void retira_espacos(char frase[]){
	int tam = strlen(frase), i, j;
	for(i = 0; i < tam; i++){
		if(frase[i] == ' ' && frase[i+1] == ' '){
			for(j = i; j < tam; j++){
				frase[j] = frase[j+1];
			}
			i--;
		}
	}
	
	if(frase[0] == ' '){
		for(i = 0; i < tam; i++){
			frase[i] = frase[i+1];
		}
	}
	if(frase[tam-1] == ' '){
		frase[tam-1] = '\0';
	}
}

int qtd_palavras(char frase[]){
	int tam = strlen(frase), i, cont = 0;
	for(i = 0; i < tam; i++){
		if((int) frase[i] == (int) ' '){
			cont++;
		}
	}
	return cont;
}

int main(int argc, char **argv)
{
	char frase[] = "                caio   gustavo           alves ";
	cout<<frase<<"\n";
	retira_espacos(frase);
	cout<<frase;
	cout<<"\n"<<qtd_palavras(frase);
	return 0;
}

