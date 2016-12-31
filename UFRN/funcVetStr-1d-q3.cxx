#include <iostream>
using namespace std;

bool eh_igual(int vet_num[], int inicio, int meio, int fim){
	int i, j;
	for(i = inicio, j = meio; i < meio && j < fim; i++, j++){
		if(vet_num[i] != vet_num[j]){
			return false;
		}
	}
	return true;
}

void encontra_repeticoes(int vet_num[], int tam, int &i, int &m){
	int j, k;
	for(j = 0; j < tam; j++){
		for(k = j+2; k < tam; k++){
			if(vet_num[j] == vet_num[k] && (k-j) <= (tam-k)){
				if(eh_igual(vet_num, j, k, (2*k)-j)){
					i = j;
					m = k-j;
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	int tam;
	cout<<"Digite o tamanho da sequencia de numeros: ";
	cin>>tam;
	int vet_num[tam];
	
	int i=0, m=0, j;
	for(j = 0; j < tam; j++){
		cout<<j+1<<"o termo: ";
		cin>>vet_num[j];
	}
	encontra_repeticoes(vet_num, tam, i, m);
	cout<<"i = "<<i+1;
	cout<<"\nm = "<<m;
	return 0;
}

