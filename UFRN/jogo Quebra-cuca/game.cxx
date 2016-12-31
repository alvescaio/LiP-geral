#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void imprime_game(int matriz[4][4], int tam, int qtd_movimentos){
	int i, j;
	cout<<"\n\n";
	cout<<" Movimentos: "<<qtd_movimentos<<" \n";
	//cout<<"    + + + + + + + + + + + +\n"
	cout<<" +-     ---     ---     ---     -+"<<endl;
	for(i = 0; i < tam; i++){
		cout<<" |   ";
		for(j = 0; j < tam; j++){
			if(matriz[i][j] == 0){
				cout<<"    |   ";
			}else if(matriz[i][j] <= 9){
				cout<<matriz[i][j]<<"   |   ";
			}else{
				cout<<matriz[i][j]<<"  |   ";
			}
		}
		cout<<"\n +-     ---     ---     ---     -+"<<endl;
	}
	//cout<<"    + + + + + + + + + + + +\n";
	cout<<" >";
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

int main(int argc, char **argv)
{
	int game[4][4] = {5,12,14,3,13,4,2,1,6,15,7,8,11,10,9,0};
	char direcao;
	int i = 0;
	
	while(1){
		imprime_game(game, 4, i);
		cin>>direcao;	
		if(direcao_valida(direcao)){
			realiza_jogada(game, 4, direcao);
			i++;
		}
		system("clear"); //para linux
		//system("cls"); //para windows
	}
	
	return 0;
}

