#include <stdio.h>
#include <string.h>

char *minusc(char *palavra){
         int i, j;
         char caixaBaixa[27] = "abcdefghijklmnopqrstuvwxyz";
         char caixaAlta[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

         for(i = 0; i < strlen(palavra); i++){
                  for(j = 0; j < 27; j++){
                           if(palavra[i] == caixaAlta[j]){
                                    palavra[i] = caixaBaixa[j];
                           }
                  }
         }

         return palavra;
}

void main(){
         char palavra[20];

         printf("Digite uma palavra: ");
         scanf("%s", &palavra);

         printf("Palavra em caixa alta: %s", minusc(palavra));
}
