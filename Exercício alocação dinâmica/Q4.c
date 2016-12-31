/*
 * Q4.c
 * 
 * Copyright 2016 Caio Alves <caioalves@caiopc>
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

struct Data{
	int dia;
	int mes;
	int ano;
};

typedef struct Data Data;

struct Pessoa{
	Data dataNascimento;
	char CPF[15];
};

typedef struct Pessoa Pessoa;



int cadastroPessoa(Pessoa *p, int n){
	Pessoa *ptVerificador = (Pessoa *) realloc(p, n*sizeof(Pessoa)); // Aloca mais um espaço para armazenar outro cadastro
	if(ptVerificador == NULL){
		return 0;
	}else{
		p = ptVerificador;
	}
	
	system("clear"); //Para linux
	//system("cls"); //Para windows
	
	printf("\nNovo cadastro de pessoa: ");
	printf("\nDigite o CPF: ");
	scanf("%s", p[n-1].CPF);
	printf("\nData de nascimento:");
	printf("\nDia: ");
	scanf("%d", &p[n-1].dataNascimento.dia);
	printf("Mes: ");
	scanf("%d", &p[n-1].dataNascimento.mes);
	printf("Ano: ");
	scanf("%d", &p[n-1].dataNascimento.ano);
	return 1;
}

void imprimeDados(Pessoa *p, int n){
	int i;
	system("clear"); //Para linux
	//system("cls"); //Para windows
	printf("\nInformações cadastradas: \n");
	for(i = 0; i < n; i++){
		printf("\nPessoa %d", i+1);
		printf("\nData de Nascimento: %d/%d/%d", p[i].dataNascimento.dia, p[i].dataNascimento.mes, p[i].dataNascimento.ano);
		printf("\nCPF: %s", p[i].CPF);
		printf("\n");	
	}
}


int main(int argc, char **argv)
{
	
	int n = 0, resp = 0;
	Pessoa *ptPessoa;
	ptPessoa = (Pessoa *) malloc(sizeof(Pessoa));	
	
	do{
	
		printf("\n-- MENU --\n");
		printf("Escolha uma opção: ");
		printf("\n[1] - Cadastrar uma nova Pessoa");
		printf("\n[2] - Exibir informações cadastradas");
		printf("\n[0] - Sair");
		printf("\n> ");
		scanf("%d", &resp);
		
		if(resp == 1){
			if(cadastroPessoa(ptPessoa, n+1)){
				n++;
			}else{
				printf("\nNão há espaço suficiente para novos cadastros!");
			}
		}else if(resp == 2){
			imprimeDados(ptPessoa, n);
		}
		
	}while(resp != 0);
	
	free(ptPessoa);
	
	return 0;
}

