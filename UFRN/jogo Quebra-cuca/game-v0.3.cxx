/* Projeto: QUEBRA-CUCA
 * Ultima modificacao: 11/03/2016.
 * Autores: Caio Alves; Cassia Carla.
 * 
 * Requisitos funcionais:
 * 
 * [===  ] - (RF01) logica do game
 * [==== ] - (RF02) Controle de telas (Menu)
 * [=====] - (RF03) Instrucoes 
 * [     ] - (RF04) Ranking
 * [     ] - (RF05) Tela de fim de jogo
 * 
 * (RF01) - Logica do game:
 * 		.1 - [x] Implementar jogadas
 * 		.2 - [ ] Contar jogadas
 * 			.2.1 - Nao conta corretamente, quando o jogador seleciona uma jogada impossivel
 * 		.3 - [ ] Verificar se o jogador venceu  
 * 		
 * (RF02) - Controle de telas (Menu)
 * 		.1 - [x] Redirecionamento para telas do jogo
 * 			.1.1 - novo jogo
 * 			.1.2 - ranking
 * 			.1.3 - instrucoes
 * 			.1.4 - sair do jogo
 * 
 * (RF03) - Instrucoes
 * 		.1 - [x] Mostrar as instrucoes do jogo
 * 
 * (RF04) - Ranking
 * 		.1 - [ ] Mostrar as 5 menores quantidades de jogadas vencedoras
 * 			.1.1 - Usar arquivo ou banco de dados para armazenar a qtd de jogadas vencedoras
 * 
 * (RF05) - Tela de fim de jogo
 * 		.1 - [ ] Exibir uma mensagem de parabens para jogador vencedor
 * 			.1.1 - mostrar pontuacao
 * 			.1.2 - mostrar se o jogador quebrou algum record de menores jogadas vencedoras
 * 
 * Requisitos nao-funcionais:
 * 
 * [=    ] - (RNF01) Comentar codigo
 * 
 * (RNF01) - Comentar codigo
 * 		.1 - [ ] Comentar para que serve cada funcao
 * 		.2 - [ ] Explicar trechos 'chaves' de codigo 
 * 
 * 
 * Historico de modificacoes:
 * 11/03/2016 - (Caio Alves, Cassia Carla): primeira versao para ser enviada ao professor
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void menu();
void resultado(int pontuacao);
void cabecalho();
void imprime_game(int matriz[4][4], int tam, int qtd_movimentos);
void indice_do_num(int matriz[4][4], int tam, int num, int &i_num, int &j_num);
void realiza_jogada(int matriz[4][4], int tam, char c);
bool direcao_valida(char c);
void novo_jogo();
void instrucoes();

void menu(){
	cabecalho();
	cout<<"\n\t1 - Novo Jogo\n\t2 - Ranking \n\t3 - Instrucoes\n\t0 - Sair\n\t>";
}

void resultado(int pontuacao){
	cout<<"Parabens, voce conseguiu ganhar com "<<pontuacao<< "jogadas";
}

void cabecalho(){
	cout<<"\n\t---------------------------------\n\t========== Quebra-Cuca ==========\t\n\t---------------------------------";
}

void instrucoes(){
	cabecalho();
	cout<<"\n\n\tDA CONCEPCAO E OBJETIVO DO JOGO\n";
	cout<<"\n\tO Quebra-Cuca eh um jogo de raciocinio logico, que desafia \n\to jogador a alinhar os numeros de uma matriz em ordem crescente.";
	cout<<"\n\n\tDAS INSTRUCOES E CONTROLES\n";
	cout<<"\n\tPara cumprir o objetivo do game, o jogador podera realizar \n\ttrocas de espacos que estejam acima, abaixo, ou ao lado \n\tdo espaco vazio.";
	cout<<"\n\n\tO controle do jogo eh realizado pelas seguistes teclas: \n";
	cout<<"\n\t[w] - troca a posicao do numero acima do espaco vazio pelo mesmo";
	cout<<"\n\t[s] - troca a posicao do numero abaixo do espaco vazio pelo mesmo";
	cout<<"\n\t[d] - troca a posicao do numero a direita do espaco vazio pelo mesmo";
	cout<<"\n\t[a] - troca a posicao do numero a esquerda do espaco vazio pelo mesmo\n";
}

void imprime_game(int matriz[4][4], int tam, int qtd_movimentos){
	int i, j;
	cabecalho();
	cout<<"\n\n";
	cout<<"\tMovimentos: "<<qtd_movimentos<<"\t    [0] para sair\n";
	//cout<<"    + + + + + + + + + + + +\n"
	cout<<"\t+-     ---     ---     ---     -+"<<endl;
	for(i = 0; i < tam; i++){
		cout<<"\t|   ";
		for(j = 0; j < tam; j++){
			if(matriz[i][j] == 0){
				cout<<"\t|   ";
			}else if(matriz[i][j] <= 9){
				cout<<matriz[i][j]<<"   |   ";
			}else{
				cout<<matriz[i][j]<<"  |   ";
			}
		}
		cout<<"\n\t+-     ---     ---     ---     -+"<<endl;
	}
	//cout<<"    + + + + + + + + + + + +\n";
	cout<<"\t>";
}

void indice_do_num(int matriz[4][4], int tam, int num, int &i_num, int &j_num){
	int i, j;
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			if(matriz[i][j] == 0){
				i_num = i;
				j_num = j;
			}
		}
	}
}

void realiza_jogada(int matriz[4][4], int tam, char c){
	int i_0, j_0, aux;
	if(c == 'w'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(i_0 > 0){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0-1][j_0];
			matriz[i_0-1][j_0] = aux;
		}
	}else if(c == 'a'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(j_0 > 0){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0][j_0-1];
			matriz[i_0][j_0-1] = aux;
		}
	}else if(c == 'd'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(j_0 < tam-1){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0][j_0+1];
			matriz[i_0][j_0+1] = aux;
		}
	}else if(c == 's'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(i_0 < tam-1){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0+1][j_0];
			matriz[i_0+1][j_0] = aux;
		}
	}
}

bool direcao_valida(char c){
	if(c == 'w' || c == 'a' || c == 'd' || c == 's'){
		return true;
	}
	return false;
}

//comeca novo jogo
void novo_jogo(){
	int game[4][4] = {5,12,14,3,13,4,2,1,6,15,7,8,11,10,9,0};
	char direcao;
	int i = 0;
	
	while(1){
		imprime_game(game, 4, i);
		cin>>direcao;	
		if(direcao_valida(direcao)){
			realiza_jogada(game, 4, direcao);
			i++;//controla a qtd de jogadas
		}if(direcao == '0'){
			break;
		}
		//system("clear"); //para linux
		system("cls"); //para windows
	}	
}

int main(int argc, char **argv)
{	
	char op_menu;
	while(1){
		//system("clear"); //para linux
		system("cls"); //para windows
		menu();
		cin>>op_menu;
		//system("clear"); //para linux
		system("cls"); //para windows
		if(op_menu == '1'){
			novo_jogo();
		}else if(op_menu == '3'){
			instrucoes();
			cout<<"\n\t";
			system("PAUSE");
		}else if(op_menu == '0'){
			exit(1);
		}
	}
	
	return 0;
}

