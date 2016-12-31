#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[])
{

  char palavra[20];
  char chAtual;
  char chNovo;

  printf("Digite uma palavra: ");
  scanf("%s", &palavra);
  setbuf(stdin, NULL);

  printf("Digite o caracter que deseja substituir: ");
  scanf("%c", &chAtual);
  setbuf(stdin, NULL);
  printf("Digite o novo caracter: ");
  scanf("%c", &chNovo);
  setbuf(stdin, NULL);

  int i;
  for(i = 0; i < strlen(palavra); i++){
         if(palavra[i] == chAtual){
                  palavra[i] = chNovo;
         }
  }

  printf("Nova palavra: %s\n", palavra);


  system("PAUSE");
  return 0;
}
