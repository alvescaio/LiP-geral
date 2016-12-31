#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char data[30];
    char cpf[30];
    
}DADOS;

DADOS pessoa;
DADOS *pp = &pessoa;
 
void preencher(DADOS *pp){
    printf("Data de nascimento: "); 
	scanf("%s", pp[0].data);
    printf("Informe seu CPF: ");
	scanf("%s", pp[0].cpf);
}
void imprimir(DADOS *pp){
	printf("\nData de nascimento: %s", (*pp).data);
	printf("\nCPF: %s", (*pp).cpf);
}

int main(){

    preencher(pp);
    imprimir(pp);
 
    return 0;
}
