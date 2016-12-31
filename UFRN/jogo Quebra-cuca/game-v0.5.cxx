/* Projeto: QUEBRA-CUCA
 * Ultima modificacao: 10/11/2016.
 * Autores: Caio Alves; Cassia Carla.
 * 
 * Requisitos funcionais:
 * 
 * [=====] - (RF01) logica do game
 * [=====] - (RF02) Controle de telas (Menu)
 * [=====] - (RF03) Instrucoes 
 * [     ] - (RF04) Ranking
 * [===  ] - (RF05) Tela de fim de jogo
 * 
 * (RF01) - Logica do game:
 * 		.1 - [x] Implementar jogadas
 * 		.2 - [x] Contar jogadas
 * 			.2.1 - Nao conta corretamente, quando o jogador seleciona uma jogada impossivel [Corrigido]
 * 		.3 - [x] Verificar se o jogador venceu  
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
 * 			.1.1 - mostrar pontuacao [Corrigido]
 * 			.1.2 - mostrar se o jogador quebrou algum record de menores jogadas vencedoras
 * 
 * Requisitos nao-funcionais:
 * 
 * [===  ] - (RNF01) Comentar codigo
 * 
 * (RNF01) - Comentar codigo
 * 		.1 - [x] Comentar para que serve cada funcao
 * 		.2 - [ ] Explicar trechos 'chaves' de codigo 
 * 
 * 
 * Historico de modificacoes:
 * 03/11/2016 - (Caio Alves, Cassia Carla): primeira versao para ser enviada ao professor
 * 10/11/2016 - (Caio Alves, Cassia Carla): segunda versao para ser enviada ao professor
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void menu();
void cabecalho();
void imprime_game(int matriz[4][4], int tam, int qtd_movimentos);
void indice_do_num(int matriz[4][4], int tam, int num, int &i_num, int &j_num);
bool realiza_jogada(int matriz[4][4], int tam, char c);
bool direcao_valida(char c);
void novo_jogo();
void instrucoes();
void preenche_aleatoriamente(char vetor[]);
bool esta_alinhado(char matriz[4][4], int tam);
void fim_de_jogo(int qtd_movimentos);

//imprime o menu inicial do jogo
void menu(){
	cabecalho();
	cout<<"\n\t1 - Novo Jogo\n\t2 - Ranking \n\t3 - Instrucoes\n\t0 - Sair\n\t>";
}

//imprime um cabecalho do jogo
void cabecalho(){
	cout<<"\n\t---------------------------------\n\t========== Quebra-Cuca ==========\t\n\t---------------------------------";
}

//exibe as instrucoes do jogo
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

//imprime a matriz de numeros no devido layout do jogo
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

//verifica se existe um numero na matriz e retorna seus indices, da linha e coluna, por referencia 
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

//verifica se a matriz esta corretamente alinhada
bool esta_alinhado(int matriz[4][4], int tam){
	int i, j;
	
	if(matriz[tam-1][tam-1] != 0){
		return false;
	}
	
	for(i = 1; i < tam; i++){
		for(j = 1; j < tam; j++){
			if(i < 3 || j < 3){
				if(matriz[i][j] < matriz[i-1][j] || matriz[i][j] < matriz[i][j-1]){
					return false;
					break;
				}
			}			
		}
	}
	
	return true;
}

//modifica matriz que contem a sequencia de numeros, realizando o movimento pretendido
bool realiza_jogada(int matriz[4][4], int tam, char c){
	int i_0; //indice da linha da matriz onde esta o numero 0
	int j_0; //indice da coluna da matriz onde esta o numero 0
	int aux; //variavel auxiliar
	if(c == 'w'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(i_0 > 0){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0-1][j_0];
			matriz[i_0-1][j_0] = aux;
			return true;
		}
	}else if(c == 'a'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(j_0 > 0){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0][j_0-1];
			matriz[i_0][j_0-1] = aux;
			return true;
		}
	}else if(c == 'd'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(j_0 < tam-1){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0][j_0+1];
			matriz[i_0][j_0+1] = aux;
			return true;
		}
	}else if(c == 's'){
		indice_do_num(matriz, tam, 0, i_0, j_0);
		if(i_0 < tam-1){
			aux = matriz[i_0][j_0];
			matriz[i_0][j_0] = matriz[i_0+1][j_0];
			matriz[i_0+1][j_0] = aux;
			return true;
		}
	}
	return false;
}

//verifica se a direcao de movimento pretendida eh valida
bool direcao_valida(char c){
	if(c == 'w' || c == 'a' || c == 'd' || c == 's'){
		return true;
	}
	return false;
}

//preenche um vetor aleatoriamente com jogadas
void preenche_aleatoriamente(char vetor[]){
    int i;
    for(i=0; i<500; i++){
		if(i%2 == 0){
			vetor[i] = 'a' + (char)(rand()%2);
		}else if(i%3 == 0){
			vetor[i] = 'w' + (char)(rand()%2);
		}else if(i%5 == 0){
			vetor[i] = 's' + (char)(rand()%2);
		}else{
			vetor[i] = 'd' + (char)(rand()%2);
		}
	}
}

//exibe tela de parabens para o jogador quando ele vence
void fim_de_jogo(int qtd_movimentos){
	system("cls");
	cabecalho();
	cout<<"\n\n\tParabens, voce conseguiu vencer\n\tcom "<<qtd_movimentos<<" movimentos!!\n\n\t";
	system("PAUSE");
	
}

//comeca novo jogo
void novo_jogo(){
	int game[4][4] = {13, 14, 11, 12, 6, 1, 15, 10, 9, 3, 4, 7, 8, 2, 5, 0};
	char jogadas_aleatorias[500];
	preenche_aleatoriamente(jogadas_aleatorias);
	char direcao;
	int i = 0;
	
	//laco de repeticao para realizar jogadas aleatorias no game
	for(i = 0; i < 500; i++){
		realiza_jogada(game, 4, jogadas_aleatorias[i]);
	}
	
	int qtd_movimentos = 0;
	while(1){
		imprime_game(game, 4, qtd_movimentos);
		cin>>direcao;	
		if(direcao_valida(direcao)){
			if(realiza_jogada(game, 4, direcao)){
				qtd_movimentos++;//controla a qtd de jogadas
			}
		}
		
		if(direcao == '0'){
			break;
		}
		
		if(esta_alinhado(game, 4)){
			fim_de_jogo(qtd_movimentos);
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

