#include <iostream>
using namespace std;

int inverterNum(int num){
	int numInvertido = 0;
	int potencia10 = 1;
	int cont = 0;
	
	while(num >= potencia10){
		potencia10 *= 10;
		numInvertido = (numInvertido*10) + (num%potencia10)/(potencia10/10);
		num -= (num%potencia10);
		cont++;
	}
	return numInvertido;
}

bool maiorInvertido(int x){
	if(x < inverterNum(x)){
		return true;
	}
	return false;
}

int main()
{
	int x;
	
	cout<<"Digite x: "; 
	cin>>x;
	
	if(maiorInvertido(x)){
		cout<<"O inverso de "<< x <<" eh maior que ele proprio!";
	}else{
		cout<< x <<" eh maior que seu inverso!";
	}
	
}

