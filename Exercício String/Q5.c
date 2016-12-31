#include <stdio.h>
#include <string.h>

char *inverteCaixa(char *palavra){
   int i, j;
   char alfabMin[27] = "abcdefghijklmnopqrstuvwxyz";
   char alfabMai[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   for(i = 0; i < strlen(palavra); i++){
         for(j = 0; j < 27; j++){
                  if(palavra[i] == alfabMin[j]){
                           palavra[i] = alfabMai[j];
                  }else if(palavra[i] == alfabMai[j]){
                           palavra[i] = alfabMin[j];
                  }
         }
   }

   return palavra;
}


void main(){

   char palavra[20];
   printf("Digite uma palavra: ");
   scanf("%s", &palavra);

   printf("Palavra invertida: %s", inverteCaixa(palavra));

}
