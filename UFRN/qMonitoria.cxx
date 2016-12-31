#include <iostream>
using namespace std;

void preenche_vetor(int vet[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		cout<<"Digite o "<<i+1<<"o numero do vetor: ";
		cin>>vet[i];
	}
}

void imprime(int vet[], int tam){
	int i;
	cout<<"[";
	for(i = 0; i < tam; i++){
		cout<<" "<<vet[i];
	}
	cout<<" ]";
}

int intersecao(int vet_a[], int tam_a, int vet_b[], int tam_b, int vet_int_ab[]){
	int i, j, k, tam_int_ab = 0;
	bool ja_existe = false;
	for(i = 0; i < tam_a; i++){
		for(j = 0; j < tam_b; j++){
			if(vet_a[i] == vet_b[j]){
				for(k = 0; k < tam_int_ab; k++){
					if(vet_a[i] == vet_int_ab[k]){
						ja_existe = true;
						break;
					}	
				}
				if(!ja_existe){
					tam_int_ab++;
					vet_int_ab[tam_int_ab-1] = vet_a[i];
				}
				break;
			}
		}
		ja_existe = false;
	}
	return tam_int_ab;
}

int uniao(int vet_a[], int tam_a, int vet_b[], int tam_b, int vet_uni_ab[]){
	int i, j, tam_uni_ab = 0;
	bool ja_existe = false;
	for(i = 0; i < tam_a; i++){
		tam_uni_ab++;
		vet_uni_ab[tam_uni_ab-1] = vet_a[i];	
	}
	for(i = 0; i < tam_b; i++){
		for(j = 0; j < tam_uni_ab; j++){
			if(vet_b[i] == vet_uni_ab[j]){
				ja_existe = true;
				break;
			}
		}
		if(!ja_existe){
			tam_uni_ab++;
			vet_uni_ab[tam_uni_ab-1] = vet_b[i];
		}
		ja_existe = false;
	}
	return tam_uni_ab;
}

void q1(){
	int tam_a, tam_b;
	cout<<"Digite o tamanho do vetor A: ";
	cin>>tam_a;
	int vet_a[tam_a];
	preenche_vetor(vet_a, tam_a);
	
	cout<<"Digite o tamanho do vetor B: ";
	cin>>tam_b;
	int vet_b[tam_b];
	preenche_vetor(vet_b, tam_b);
	
	int vet_int_ab[tam_a+tam_b];
	int tam_ab = intersecao(vet_a, tam_a, vet_b, tam_b, vet_int_ab);
	imprime(vet_int_ab, tam_ab);
}

void q2(){
	int tam_a, tam_b;
	cout<<"Digite o tamanho do vetor A: ";
	cin>>tam_a;
	int vet_a[tam_a];
	preenche_vetor(vet_a, tam_a);
	
	cout<<"Digite o tamanho do vetor B: ";
	cin>>tam_b;
	int vet_b[tam_b];
	preenche_vetor(vet_b, tam_b);
	
	int vet_int_ab[tam_a+tam_b];
	int tam_ab = uniao(vet_a, tam_a, vet_b, tam_b, vet_int_ab);
	imprime(vet_int_ab, tam_ab);
}

int main(int argc, char **argv)
{
	q2();	
	return 0;
}

