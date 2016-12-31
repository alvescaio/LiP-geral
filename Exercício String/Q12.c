#include <stdio.h>
#include <string.h>

void limpaLetra(char *palavra, char carac){
	int i, k;
	
	for(i = 0; i < strlen(palavra); i++){
			if(palavra[i] == carac){
				for(k=i; k < strlen(palavra); k++){
                    palavra[k]= palavra[k+1];
                }
			}
			
	}
	
	printf("\nPalavra atualizada: %s\n", palavra);
}

void limpaBuffer(void){
	 char c;
	 while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
	char palavra[20]; 	
	char letra;
	
	printf("Digite uma palavra: ");
	scanf("%s", &palavra);
	limpaBuffer();
	
	printf("Digite uma letra: ");
	scanf("%c", &letra);
	
	limpaLetra(palavra, letra);
	
	return 0;
}

