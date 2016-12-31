#include <iostream>
using namespace std;

void lucros(float preco_compra[], float preco_venda[], int lucro[]){
	int i;
	float divisao;
	for(i = 0; i < 10; i++){
		divisao = preco_venda[i]/preco_compra[i];
		if(divisao < 1.1){
			lucro[0]++;
		}else if(divisao >= 1.1 && divisao <= 1.2){
			lucro[1]++;
		}else if(divisao > 1.2){
			lucro[2]++;
		}
	}
}

int main()
{	
	float preco_compra[10] = {20, 100, 25.50, 30, 60, 10, 10, 20, 100, 30};
	float preco_venda[10] = {22, 110, 51, 60, 15, 15, 30, 120, 50}; 
	
	//vetor lucro informa quantas mercadorias proporcionam os seguintes lucros:
	//lucro[0] = lucro menor que 10/100
	//lucro[1] = lucro entre 10/100 e 20/100
	//lucro[2] = lucro maior que 20/100
	int lucro[3] = {0, 0, 0}, i;
	
	lucros(preco_compra, preco_venda, lucro);
	
	cout<<"Qtd de mercadorias por faixa de lucro proporcionadas: \n";
	cout<<"Ate 10/100: "<<lucro[0]<<" mercadorias.\n";
	cout<<"Entre 10/100 e 20/100: "<<lucro[1]<<" mercadorias.\n";
	cout<<"Mais de 20/100: "<<lucro[2]<<" mercadorias.\n";
	
	return 0;
}

