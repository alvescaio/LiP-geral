#include <iostream>
using namespace std;

int tam_string(char string[]){
	int tam_string, i;
	for(tam_string = 1, i = 0; string[i] != '\0'; i++, tam_string++);
	return tam_string;
}

void concatenar(char source[], char destination[]){
	int tam_destination, tam_source, i, j;
	tam_destination = tam_string(destination);
	tam_source = tam_string(source);
	
	int novo_tam_source = tam_destination-1 + tam_source;
	
	for(i = tam_destination-1, j = 0; i < novo_tam_source-1; j++, i++){
		destination[i] = source[j];
	}
}

int main()
{
	char source[100] = "Cassia Carla de Carvalho";
	char destination[100] = "Nome: ";
	
	concatenar(source, destination);
	cout<<destination;
	
	
	return 0;
}

