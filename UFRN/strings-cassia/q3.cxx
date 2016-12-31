#include <iostream>
using namespace std;

void conta_digitos(int a[], int b[], int tam_a){
	int i, resto;
	for(i = 0; i < 10; i++){
		b[i] = 0;
	}
	for(i = 0; i < tam_a; i++){
		while(a[i] > 0){
			resto = a[i]%10;
			b[resto]++;
			a[i] = a[i]/10;
		}
	}
}

int main(int argc, char **argv)
{
	int a[] = {2014, 324, 652, 4004, 453, 9};
	int b[10];
	int tam_a = sizeof(a)/sizeof(a[0]);
	
	conta_digitos(a, b, tam_a);
	
	int i;
	for(i = 0; i < 10; i++){
		cout<<"Qtd de "<<i<<"s em a: "<<b[i]<<"\n";
	}
	
	
	return 0;
}

