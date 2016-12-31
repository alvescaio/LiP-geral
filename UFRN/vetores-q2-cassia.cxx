#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int m, n, o;
	
	cout<<"Digite M: ";
	cin>>m;
	cout<<"Digite N: ";
	cin>>n;
	cout<<"Digite O: ";
	cin>>o;
	
	double A[m], B[n], C[o];
	int i;
	
	for(i = 0; i < m; i++){
		cout<<"Digite o valor de A["<<i<<"]: ";
		cin>>A[i];
	}
	
	cout<<"\n";
	for(i = 0; i < n; i++){
		cout<<"Digite o valor de B["<<i<<"]: ";
		cin>>B[i];
	}
	
	cout<<"\n";
	for(i = 0; i < o; i++){
		cout<<"Digite o valor de C["<<i<<"]: ";
		cin>>C[i];
	}
	
	int tamD = m + n + o;
	double D[tamD];
	
	cout<<"A = [ ";
	for(i = 0; i < m; i++){
		cout<<A[i]<<" ";
		D[i] = A[i];
	}
	cout<<"]\n";
	
	cout<<"B = [ ";
	for(i = 0; i < n; i++){
		cout<<B[i]<<" ";
		D[i+m] = B[i];
	}
	cout<<"]\n";
	
	cout<<"C = [ ";
	for(i = 0; i < o; i++){
		cout<<C[i]<<" ";
		D[i+m+n] = C[i];
	}
	cout<<"]\n";
	
	cout<<"D = [ ";
	for(i = 0; i < tamD; i++){
		cout<<D[i]<<" ";
	}
	cout<<"]\n";
	
	return 0;
}

