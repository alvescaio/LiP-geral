/* Projeto: QUEBRA-CUCA
 * Ultima modificacao: 17/11/2016.
 * Autores: Caio Alves; Cassia Carla.
 * 
 * Requisitos funcionais:
 * 
 * [=====] - (RF01) logica do game
 * [=====] - (RF02) Controle de telas (Menu)
 * [=====] - (RF03) Instrucoes 
 * [=====] - (RF04) Ranking
 * [=====] - (RF05) Tela de fim de jogo
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
 * 		.1 - [x] Mostrar as 10 menores quantidades de jogadas vencedoras
 * 			.1.1 - Usar arquivo ou banco de dados para armazenar a qtd de jogadas vencedoras
 * 
 * (RF05) - Tela de fim de jogo
 * 		.1 - [x] Exibir uma mensagem de parabens para jogador vencedor
 * 			.1.1 - mostrar pontuacao [Corrigido]
 * 			.1.2 - mostrar se o jogador quebrou algum record de menores jogadas vencedoras
 * 
 * Requisitos nao-funcionais:
 * 
 * [=====] - (RNF01) Comentar codigo
 * 
 * (RNF01) - Comentar codigo
 * 		.1 - [x] Comentar para que serve cada funcao
 * 		.2 - [x] Explicar trechos 'chaves' de codigo 
 * 
 * 
 * Historico de modificacoes:
 * 03/11/2016 - (Caio Alves, Cassia Carla): primeira versao para ser enviada ao professor
 * 10/11/2016 - (Caio Alves, Cassia Carla): segunda versao para ser enviada ao professor
 * 17/11/2016 - (Caio Alves, Cassia Carla): versao final para ser enviada ao professor
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

struct Jogador{
	char nome[50];
	int n_jogadas;
};
typedef struct Jogador Jogador;

void menu();
void cabecalho();
void imprime_game(int matriz[4][4], int tam, int qtd_movimentos);
void indice_do_num(int matriz[4][4], int tam, int num, int &i_num, int &j_num);
bool realiza_jogada(int matriz[4][4], int tam, char c);
bool direcao_valida(char c);
void novo_jogo();
void ranking();
void instrucoes();
void preenche_aleatoriamente(char vetor[]);
bool esta_alinhado(char matriz[4][4], int tam);
void fim_de_jogo(int qtd_movimentos);
void atualiza_ranking(Jogador lista_jogadores[], int qtd_itens, char url_arquivo[]);
void preenche_lista_jogadores(Jogador lista_jogadores[], int qtd_itens);
void imprime_lista_jogadores(Jogador lista_jogadores[], int qtd_itens);
void preenche_lista_jogadores_de_arquivo(Jogador lista_jogadores[], int qtd_itens, char url_arquivo[]);
void troca(Jogador lista_jogadores[], int i, int j);
void ordena_vetor(Jogador lista_jogadores[], int qtd_itens);
bool eh_record(int qtd_movimentos);

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

//preenche um vetor aleatoriamente com caracteres que representam jogadas
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

//funcoes referentes ao ranking: atualiza_ranking, preenche_lista_jogadores, imprime_lista_jogadores, preenche_lista_jogadores_arquivo,
//troca, ordena_vetor, eh_record e ranking.

//preenche com valores padroes uma lista de jogadores do tipo Jogador (struct)
void preenche_lista_jogadores(Jogador lista_jogadores[], int qtd_itens){
	int i;
	for(i = 0; i < qtd_itens; i++){
		strcpy(lista_jogadores[i].nome, "[---------]");
		lista_jogadores[i].n_jogadas = 0;
	}
}

//imprime um vetor do tipo Jogador (struct)
void imprime_lista_jogadores(Jogador lista_jogadores[], int qtd_itens){
	int i;
	for(i = 0; i < qtd_itens; i++){
		if(lista_jogadores[i].n_jogadas != 0){
			cout<<"\t"<<lista_jogadores[i].nome<<"\t - "<<lista_jogadores[i].n_jogadas<<" \tjogadas\n";
		}
	}
}

//preenche um vetor do tipo Jogador (struct) com informacoes contidas no arquivo ranking.qc
void preenche_lista_jogadores_de_arquivo(Jogador lista_jogadores[], int qtd_itens, char url_arquivo[]){
	int i = 0;
	FILE *arq; //ponteiro criado para inicializar o arquivo que contem a lista do ranking de jogadores
	arq = fopen(url_arquivo, "r"); //funcao para abrir o arquivo no modo leitura
	if(arq == NULL){ //verifica se o arquivo foi aberto sem erros
		atualiza_ranking(lista_jogadores, qtd_itens, url_arquivo);
	}else{
		while(fscanf(arq, "%s %i\n", lista_jogadores[i].nome, &lista_jogadores[i].n_jogadas) != EOF){
			i++;
		}
		fclose(arq);
	}
}

//atualiza o arquivo ranking.qc com a lista de jogadores passada por parametro
void atualiza_ranking(Jogador lista_jogadores[], int qtd_itens, char url_arquivo[]){
	int i;
	FILE *arq; //ponteiro criado para inicializar o arquivo que contem a lista do ranking de jogadores
	arq = fopen(url_arquivo, "w"); //funcao para abrir o arquivo no modo escrita
	if(arq == NULL){ //verifica se o arquivo foi aberto sem erros
		cout<<"Erro no arquivo de ranking!!";
		system("PAUSE");
	}else{
		for(i = 0; i < qtd_itens; i++){
			fprintf(arq, "%s %i\n", lista_jogadores[i].nome, lista_jogadores[i].n_jogadas); //funcao para escrever no arquivo
		}
		fclose(arq);//funcao para fechar o arquivo
	}
}

//realiza uma troca entre variaveis do tipo Jogador (struct)
void troca(Jogador lista_jogadores[], int i, int j){
	Jogador aux = lista_jogadores[i];
	lista_jogadores[i] = lista_jogadores[j];
	lista_jogadores[j] = aux;
}

//ordena um vetor em ordem decrescente de n_jogadas
void ordena_vetor(Jogador lista_jogadores[], int qtd_itens){
	int i, j;
	for(i = 0; i < qtd_itens; i++){
		for(j = i; j < qtd_itens; j++){
			if(lista_jogadores[i].n_jogadas == 0 && lista_jogadores[j].n_jogadas != 0){
				troca(lista_jogadores, i, j);
			}else if(lista_jogadores[j].n_jogadas == 0){
				continue;
			}else if(lista_jogadores[i].n_jogadas > lista_jogadores[j].n_jogadas){
				troca(lista_jogadores, i, j);
			}
		}
	}
}

//verifica se a quantidade de movimentos passada por parametro eh menor do que os movimentos dos jogadores contido no arquivo ranking.qc
bool eh_record(int qtd_movimentos){
	char url_arquivo[20] = "ranking.qc"; //local do arquivo que armazenara o ranking dos jogadores
	Jogador lista_jogadores[10]; //vetor criado para armazenar uma lista de jogadores que fazem parte do ranking
	preenche_lista_jogadores(lista_jogadores, 10);
	preenche_lista_jogadores_de_arquivo(lista_jogadores, 10, url_arquivo);
	if(lista_jogadores[9].n_jogadas == 0 || qtd_movimentos < lista_jogadores[9].n_jogadas){
		return true;
	}
	return false;
}

//controla a tela do ranking
void ranking(){
	char url_arquivo[20] = "ranking.qc"; //local do arquivo que armazenara o ranking dos jogadores
	Jogador lista_jogadores[10]; //vetor criado para armazenar uma lista de jogadores que fazem parte do ranking
	preenche_lista_jogadores(lista_jogadores, 10);
	preenche_lista_jogadores_de_arquivo(lista_jogadores, 10, url_arquivo);
	
	ordena_vetor(lista_jogadores, 10);
	
	atualiza_ranking(lista_jogadores, 10, url_arquivo);
	cabecalho();
	cout<<"\n\n";
	cout<<"\tRANKING\n\n";
	imprime_lista_jogadores(lista_jogadores, 10);
}

//exibe tela de parabens para o jogador quando ele vence
void fim_de_jogo(int qtd_movimentos){
	system("cls");
	cabecalho();
	if(eh_record(qtd_movimentos)){
		cout<<"\n\tParabens! Novo record!\n";
		char url_arquivo[20] = "ranking.qc"; //local do arquivo que armazenara o ranking dos jogadores
		Jogador gamer; //variavel criada para capturar as informacoes do jogador, como nome e qtd de jogadas, depois que esse venceu o jogo
		cout<<"\tDigite seu nome: ";
		cin>>gamer.nome;
		gamer.n_jogadas = qtd_movimentos;
		
		Jogador lista_jogadores[10]; //vetor criado para armazenar uma lista de jogadores que fazem parte do ranking
		preenche_lista_jogadores(lista_jogadores, 10);
		preenche_lista_jogadores_de_arquivo(lista_jogadores, 10, url_arquivo);
		
		lista_jogadores[9] = gamer;	//o jogador vencedor eh adicionado a ultima posicao da lista que contem o ranking dos jogadores
		
		ordena_vetor(lista_jogadores, 10);
		
		atualiza_ranking(lista_jogadores, 10, url_arquivo);
		cout<<"\n\t";
	}else{
		cout<<"\n\n\tParabens, voce conseguiu vencer\n\tcom "<<qtd_movimentos<<" movimentos!!\n\n\t";
	}
	
	system("PAUSE");	
}

//comeca novo jogo
void novo_jogo(){
	int game[4][4] = {13, 14, 11, 12, 6, 1, 15, 10, 9, 3, 4, 7, 8, 2, 5, 0}; //variavel utilizada para armazenar os valores de cada posicao do jogo, em forma de matriz
	char jogadas_aleatorias[500]; //vetor para armazenar diversas jogadas aleatorias
	preenche_aleatoriamente(jogadas_aleatorias);
	char direcao; //variavel que determina a direcao em que sera realizada a troca de posicoes no jogo
	int i = 0;//contador do laco for
	
	//laco de repeticao para realizar jogadas aleatorias no game
	for(i = 0; i < 500; i++){
		realiza_jogada(game, 4, jogadas_aleatorias[i]);
	}
	
	int qtd_movimentos = 0; //variavel para armazenar a quantidade de movimentos realizados
	while(1){
		imprime_game(game, 4, qtd_movimentos);
		direcao = getch(); //funcao da biblioteca conio.h que utiliza o valor teclado em tempo real, sem necessidade de apertar enter	
		if(direcao_valida(direcao)){
			if(realiza_jogada(game, 4, direcao)){
				qtd_movimentos++;
			}
		}
		
		if(direcao == '0'){
			break;
		}
		
		if(esta_alinhado(game, 4)){
			fim_de_jogo(qtd_movimentos);
			break;
		}
		system("cls"); //para windows
	}	
}

//funcao principal: contem o controle do menu principal
int main(int argc, char **argv){	
	char op_menu; //variavel para capturar a opcao do menu principal
	while(1){
		system("cls"); //para windows
		menu();
		op_menu = getch();
		system("cls"); //para windows
		if(op_menu == '1'){
			novo_jogo();
		}else if(op_menu == '2'){
			ranking();
			cout<<"\n\t";
			system("PAUSE");
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
