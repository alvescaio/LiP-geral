#include <iostream>
#include <cstring>
using namespace std;

void troca(char s[], int i, int j){
	char aux = s[i];
	s[i] = s[j];
	s[j] = aux;
}

bool ehVogal(char s){
	int i;
	char vogais[] = "aeiou";
	for(i = 0; i < 5; i++){
		if(s == vogais[i]){
			return true; 
		}
	}
	return false;
}

void primeiroVogais(char s[]){
	int tam_s = strlen(s);
	int i, j;
	for(i = tam_s-1; i > 0; i--){
		if(!ehVogal(s[i])){
			for(j = i; j > 0; j--){
				if(ehVogal(s[j])){
					troca(s, i, j);
				}
			}
		}
	}
}

int contaVogais(char s[]){
	int i, cont = 0; 
	int tam_s = strlen(s);
	for(i = 0; i < tam_s; i++){
		if(ehVogal(s[i])){
			cont++;
		}
	}
	return cont;	
}

void ordemAlfabetica(char s[], int posInicial, int posFinal){
	int i, j;
	for(i = posInicial; i < posFinal; i++){
		for(j = i; j < posFinal; j++){
			if(s[j] > s[i]){
				troca(s, i, j);
			}
		}
	}
}

void ordena_vogais_e_consoantes(char s[]){
	int qtd_vogais = contaVogais(s);
	int tam = strlen(s);
	ordemAlfabetica(s, 0, (tam-qtd_vogais));
	ordemAlfabetica(s, (tam-qtd_vogais), tam);
}

void ordenaPalavra(char s[]){
	primeiroVogais(s);
	ordena_vogais_e_consoantes(s);
}

void tudo_minusculo(char s[]){
	int tam = strlen(s);
	int i;
	for(i = 0; i < tam; i++){
		s[i] = tolower(s[i]);
	}
}

int main(int argc, char **argv)
{
	char palavra[200];
	cout<<"Digite uma palavra: ";
	cin.getline(palavra, 100);
	tudo_minusculo(palavra);
	ordenaPalavra(palavra);
	cout<<"Palavra ordenada: "<<palavra;
	
	return 0;
}
