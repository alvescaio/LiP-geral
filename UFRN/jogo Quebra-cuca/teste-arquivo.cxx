#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

struct Jogador{
	char nome[50] = "";
	int n_jogadas;
};
typedef struct Jogador Jogador;

void atualiza_ranking(){
}

void preenche_lista_jogadores(Jogador lista_jogadores[], int qtd_itens){
	int i;
	for(i = 0; i < qtd_itens; i++){
		strcat(lista_jogadores[i].nome, "[---------]");
		lista_jogadores[i].n_jogadas = 0;
	}
}

void imprime_lista_jogadores(Jogador lista_jogadores[], int qtd_itens){
	int i;
	for(i = 0; i < qtd_itens; i++){
		cout<<lista_jogadores[i].nome<<" - "<<lista_jogadores[i].n_jogadas<<"\n";
	}
}

void preenche_lista_jogadores_de_arquivo(Jogador lista_jogadores[], int qtd_itens, char url_arquivo[]){
	int i = 0;
	FILE *arq;
	arq = fopen(url_arquivo, "r");
	if(arq == NULL){
		cout<<"Erro no arquivo de ranking!!";
		system("PAUSE");
	}else{
		while(fscanf(arq, "%s#%i\n", lista_jogadores[i].nome, &lista_jogadores[i].n_jogadas) != EOF){
			i++;
		}
		fclose(arq);
	}
}

void atualiza_ranking(Jogador lista_jogadores[], int qtd_itens, char url_arquivo[]){
	int i;
	FILE *arq;
	arq = fopen(url_arquivo, "w");
	if(arq == NULL){
		cout<<"Erro no arquivo de ranking!!";
		system("PAUSE");
	}else{
		for(i = 0; i < qtd_itens; i++){
			fprintf(arq, "%s %i\n", lista_jogadores[i].nome, lista_jogadores[i].n_jogadas);
		}
		fclose(arq);
	}
}

int main(int argc, char **argv)
{
	char url_arquivo[20] = "ranking.qc";
	Jogador gamer;
	cout<<"Digite seu nome: ";
	cin>>gamer.nome;
	gamer.n_jogadas = 200;
	
	Jogador lista_jogadores[10];
	preenche_lista_jogadores(lista_jogadores, 10);
	preenche_lista_jogadores_de_arquivo(lista_jogadores, 10, url_arquivo);
	atualiza_ranking(lista_jogadores, 10, url_arquivo);
	imprime_lista_jogadores(lista_jogadores, 10);
	
	return 0;
}

