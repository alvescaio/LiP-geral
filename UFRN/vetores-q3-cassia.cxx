#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	
	cout<<"Digite o tamanho do vetor: ";
	cin>>n;
	
	int vetor[n], i, j, aux;	
	
	for(i = 0; i < n; i++){
		cout<<"Digite o "<<i+1<<"o elemento do vetor: ";
		cin>>vetor[i];
	}
	
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			if(vetor[i] < vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
	
	cout<<"Vetor ordenado: ";
	for(i = 0; i < n; i++){
		cout<<vetor[i];
	}
	
		
	return 0;
}
