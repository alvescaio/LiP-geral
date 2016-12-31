#include <iostream>
#include <cstring>
using namespace std;

bool ehDigito(char s){
	if(s == '0' || s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' || s == '8' || s == '9'){
		return true;
	}
	return false;
}

int conta_digito(char s[]){
	int tam_s = strlen(s);
	int i, cont = 0;
	for(i = 0; i < tam_s; i++){
		if(ehDigito(s[i])){
			cont++;
		}
	}
	return cont;
}

void troca(char s[], int i, int j){
	char aux = s[i];
	s[i] = s[j];
	s[j] = aux;
}

void ordena_digitos_primeiro(char s[]){
	int tam_s = strlen(s);
	int i, j;
	for(i = 0; i < tam_s; i++){
		if(!ehDigito(s[i])){
			for(j = i; j < tam_s; j++){
				if(ehDigito(s[j])){
					troca(s, i, j);
				}
			}
		}
	}
}

void ordem_decrescente(char s[]){
	int tam_s = strlen(s);
	int qtd_digitos = conta_digito(s);
	int i, j;
	//Ordena os digitos
	for(i = 0; i < qtd_digitos; i++){
		for(j = i; j < qtd_digitos; j++){
			if(s[i] < s[j]){
				troca(s,i, j);
			}
		}	
	}
	//Ordena as letras
	for(i = qtd_digitos; i < tam_s; i++){
		for(j = i; j < tam_s; j++){
			if(s[i] < s[j]){
				troca(s,i, j);
			}
		}	
	}
}

void ordena_palavra(char s[]){
	ordena_digitos_primeiro(s);
	ordem_decrescente(s);
}

void tudo_minusculo(char s[]){
	int tam = strlen(s);
	int i;
	for(i = 0; i < tam; i++){
		s[i] = tolower(s[i]);
	}
}

int main()
{
	char palavra[200];
	cout<<"Digite uma palavra: ";
	cin.getline(palavra, 100);
	tudo_minusculo(palavra);
	ordena_palavra(palavra);
	cout<<"Palavra ordenada: "<<palavra;
	return 0;
}

