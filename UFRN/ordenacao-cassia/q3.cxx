#include <iostream>
#include <cstring>
using namespace std;

void troca_naipe(char naipe[], int i, int j){
	char aux = naipe[i];
	naipe[i] = naipe[j];
	naipe[j] = aux;
}

void troca_numeros(int numeros[], int i, int j){
	int aux = numeros[i];
	numeros[i] = numeros[j];
	numeros[j] = aux;
}

int prioridade_naipe(char s){
	if(s == 'c'){
		return 4;
	}else if(s == 'e'){
		return 3;
	}else if(s == 'o'){
		return 2;
	}else if(s == 'p'){
		return 1;
	}
	return 0;
}

void ordena_por_naipe(char naipe[], int numeros[], int qtd_cartas){
	int i, j;
	for(i = 0; i < qtd_cartas; i++){
		for(j = i; j < qtd_cartas; j++){
			if(prioridade_naipe(naipe[i]) < prioridade_naipe(naipe[j])){
				troca_naipe(naipe, i, j);
				troca_numeros(numeros, i, j);
			}
		}
	}
}

void ordena_por_numeros(char naipe[], int numeros[], int qtd_cartas){
	int i;
	for(i = 1; i < qtd_cartas-1; i++){
		if(naipe[i] == naipe[i+1]){
			if(numeros[i] > numeros[i+1]){
				troca_numeros(numeros, i, i+1);
			}
		}
		if(naipe[i] == naipe[i-1]){
			if(numeros[i] < numeros[i-1]){
				troca_numeros(numeros, i, i-1);
			}
		}
	}
}

void ordena_por_naipe_e_numero(char naipe[], int numeros[], int qtd_cartas){
	ordena_por_naipe(naipe, numeros, qtd_cartas);
	ordena_por_numeros(naipe,numeros, qtd_cartas);
}

int main()
{
	int n_cartas, i;
	cout<<"Qtd de cartas: ";
	cin>>n_cartas;
	
	int numeros[n_cartas];
	char naipes[n_cartas];
	
	for(i = 0; i < n_cartas; i++){
		cout<<"Naipe da "<<i+1<<"a carta [c, e, o, p]: ";
		cin>>naipes[i];
		cout<<"Numeros dessa carta: ";
		cin>>numeros[i];
		cout<<"\n";
	}
	
	ordena_por_naipe_e_numero(naipes, numeros, n_cartas);
	
	cout<<"naipes = { ";
	for(i = 0; i < n_cartas; i++){
		cout<<naipes[i]<<" ";
	}
	cout<<"}\n";
	
	cout<<"Numeros das cartas = { ";
	for(i = 0; i < n_cartas; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"}";
	return 0;
	return 0;
}
