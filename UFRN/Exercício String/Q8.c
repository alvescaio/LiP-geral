#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    char s[20];
    char ch;
    int pos;

    printf("Digite uma palavra: ");
    scanf("%s", &s);
    setbuf(stdin, NULL);

    do{
         printf("Digite a posicao do caracter que deseja substituir: ");
         scanf("%d", &pos);
         setbuf(stdin, NULL);

         if(pos <= 0 || pos > strlen(s)){
                  printf("Nao existe nenhum caracter nessa posicao! Digite novamente\n");
         }
    }while(pos <= 0 || pos > strlen(s));

    printf("Digite o caracter novo: ");
    scanf("%c", &ch);
    setbuf(stdin, NULL);

    s[pos-1] = ch;

    printf("Palavra atualizada: %s\n", s);

    return 0;
}
