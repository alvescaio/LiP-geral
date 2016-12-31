#include <iostream>
using namespace std;

void imprime_matriz(int M[][20], int n_lin, int n_col){
	int i, j;
	for(i = 0; i < n_lin; i++){
		for(j = 0; j < n_col; j++){
			cout<<M[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

void preenche_matriz(int M[][20], int n_lin, int n_col){
	int i, j;
	for(i = 0; i < n_lin; i++){
		for(j = 0; j < n_col; j++){
			cout<<"M["<<i<<"]["<<j<<"] = ";
			cin>>M[i][j];
		}
	}
}

bool produto(int A[][20], int lin_a, int col_a, int B[][20], int lin_b, int col_b, int C[][20]){
	if(col_a != lin_b){
		return false;
	}
	
	int i, j, k, soma;
	for(i = 0; i < lin_a; i++){
		for(j = 0; j < col_b; j++){
			soma = 0;
			for(k = 0; k < col_a; k++){
				cout<<"Soma = "<<A[i][k]<<"*"<<B[k][j]<<" = "<<A[i][k]*B[k][j]<<" ";
				soma += A[i][k]*B[k][j];
			}
			C[i][j] = soma;
			
		}
		cout<<"\n";
	}	
	return true;
}

int main(int argc, char **argv)
{
	int n_lin_A, n_col_A;
	cout<<"Qtd de linhas da matriz A: ";
	cin>>n_lin_A;
	cout<<"Qtd de colunas de A: ";
	cin>>n_col_A;
	int A[n_lin_A][20];
	preenche_matriz(A, n_lin_A, n_col_A);	
	imprime_matriz(A, n_lin_A, n_col_A);
	
	int n_lin_B, n_col_B;
	cout<<"Qtd de linhas da matriz B: ";
	cin>>n_lin_B;
	cout<<"Qtd de colunas de B: ";
	cin>>n_col_B;
	int B[n_lin_B][20];
	preenche_matriz(B, n_lin_B, n_col_B);	
	imprime_matriz(B, n_lin_B, n_col_B);
	
	int n_lin_C = n_lin_A, n_col_C = n_col_B;
	int C[n_lin_C][20];
	
	bool vf = produto(A, n_lin_A, n_col_A, B, n_lin_B, n_col_B, C);
	
	if(!vf){
		cout<<"\nNao existe produto entre A e B.\n";
	}else{
		cout<<"\nA x B = \n";
		imprime_matriz(C, n_lin_C, n_col_C);
	}
	
	return 0;
}

