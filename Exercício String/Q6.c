#include <stdio.h>
#include <string.h>

char *intercalar(char *A, char *B){
         int i;
         int cont = 0;
         int tam = strlen(A) + strlen(B);
         char *C = (char *) calloc(tam+1, sizeof(char));
         for(i = 0; i < tam; i++){
                  if(i % 2 == 0){
                           C[i] = A[cont];
                  }else{
                           C[i] = B[cont];
                           cont++;
                  }
         }

         C[tam] = '\0';

         return C;
}

int main(int argc, char *argv[])
{


    char A[20];
    char B[20];

    do{
         printf("Digite a 1a palavra: ");
         scanf("%s", &A);
         printf("Digite a 2a palavra: ");
         scanf("%s", &B);

         if(strlen(A) != strlen(B)){
                  printf("As palavras devem possuir o mesmo tamanho!\n");
         }

    }while(strlen(A) != strlen(B));

    printf("Palavra intercalada: %s\n", intercalar(A, B));

  system("PAUSE");
  return 0;
}
