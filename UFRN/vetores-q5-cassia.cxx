#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Digite o tamanho da sequencia: ";
	cin>>n;
	
	double sequencia[n];
	
	int i;
	for(i = 0; i < n; i++){
		cout<<i+1<<"o valor da sequencia: ";
		cin>>sequencia[i];
	}
	
	double numRepetidos[n];
	int qtdRepeticoes[n];
	int tamDoVetorDeRepeticoes = 1, j;
	bool ehRepetido = false;
	
	qtdRepeticoes[0] = 1;
	numRepetidos[0] = sequencia[0];
	
	for(i = 1; i < n; i++){
		for(j = 0; j < tamDoVetorDeRepeticoes; j++){
			if(sequencia[i] == numRepetidos[j]){
				qtdRepeticoes[j]++;
				ehRepetido = true;
			}
		}
		
		if(!ehRepetido){
			numRepetidos[tamDoVetorDeRepeticoes] = sequencia[i];
			tamDoVetorDeRepeticoes++;
		}
		ehRepetido = false;
		
	}
	
	cout<<"Sequencia: [ ";
	for(i = 0; i < n; i++){
		cout<<sequencia[i]<<" ";
	}
	cout<<" ]\n";
	
	for(i = 0; i < tamDoVetorDeRepeticoes; i++){
		cout<<sequencia[i]<<" ocorre "<<qtdRepeticoes[i]<<" vezes.\n";
	}
	
	return 0;
}

