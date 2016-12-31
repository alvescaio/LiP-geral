#include <iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Digite a qtd de bois: ";
	cin>>n;
	
	int numeroBoi[n];
	float peso[n];
	
	int i;
	for(i = 0; i < n; i++){
		cout<<"\n\nNumero do "<<i+1<<"o Boi: ";
		cin>>numeroBoi[i];
		
		cout<<"Peso do "<<i+1<<"o Boi: ";
		cin>>peso[i];
	}
	
	float maiorPeso = 0, menorPeso = peso[0], somaPesos = 0, mediaPeso = 0;
	int boiMaisPesado = numeroBoi[0], boiMaisLeve = numeroBoi[0];
	
	for(i = 0; i < n; i++){
		if(maiorPeso < peso[i]){
			maiorPeso = peso[i];
			boiMaisPesado = numeroBoi[i];
		}
		
		if(menorPeso > peso[i]){
			menorPeso = peso[i];
			boiMaisLeve = numeroBoi[i];
		}
		
		somaPesos += peso[i];
	}
	
	mediaPeso = somaPesos/n;
	
	cout<<"\nMedia dos pesos dos bois: "<<mediaPeso;
	cout<<"\nNumero do boi mais pesado: "<<boiMaisPesado;
	cout<<"\nNumero do boi mais leve: "<<boiMaisLeve;
	
	return 0;
}

