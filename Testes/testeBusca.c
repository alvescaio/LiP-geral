#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void busca(){


    FILE *p;
    p = fopen("teste.txt", "r");

    char pesquisaTipo[50] = "sffsf";
    char pesquisaMarca[50] = "Marca: palio";


    char tipo[50], marca[50];

    char c, b;
    char palavra[50];
    int cont = 0;
    int contLinha = 0;

    printf("Pesquisa por: %s\n\n", pesquisaMarca);

    c = getc(p);

    while(c != EOF){
        if(c != '\n'){
            palavra[cont] = c;
            cont++;

        }else if(c == '\n'){
            palavra[cont] = '\0';


            if(contLinha == 0){
                strcat(tipo, palavra);
            }else if(contLinha == 1){
                strcat(marca, palavra);
            }

            cont = 0;
            contLinha++;
        }


        if(contLinha == 7){
            contLinha = 0;
        }

        if(((strcmp(palavra, pesquisaTipo) == 0) && contLinha == 1) || ((strcmp(palavra, pesquisaMarca) == 0) && contLinha == 2)){

            if(contLinha == 1){
                printf("\n%s\n", tipo);
            }else if(contLinha == 2){
                printf("\n%s\n", tipo);
                printf("\n%s\n", marca);
            }



            while(contLinha < 7){
                b = getc(p);
                printf("%c", b);

                if(b != '\n'){
                    cont++;

                }else if(b == '\n'){
                    cont = 0;
                    contLinha++;
                }

            }
        }

        c = getc(p);
    }

    fclose(p);

}

int main(){

    busca();


    system("pause");

}
