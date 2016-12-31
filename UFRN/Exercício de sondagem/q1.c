/*
 * q1.c
 * 
 * Copyright 2016 Caio Alves <caio_alves@outlook.com> 
 * 
 * Problema: dados um inteiro x e um inteiro não-negativo n, calcular e mostrar o valor de X^n
 * 
 */


#include <stdio.h>

	// função que faz a operação matemática
	int func(int x, int n)
	{
		int i, result = 1;
		
		// Laço que se repete n vezes 
		for(i = 0; i < n; i++)
		{
			// Operação de incremento que se repete n vezes
			result = result * x;
		}
		
		return result;
	}


int main(int argc, char **argv)
{
	
	//declaração de variáveis
	int x, n, result;
	
	
	printf("Digite um valor para a base: ");
	scanf("%i", &x);
	
	printf("\nDigite um valor para o expoente: ");
	scanf("%i", &n);
		
	do{
		
		if(n <= 0){
			printf("\nDigite um valor positivo para o expoente: ");
			scanf("%i", &n);			
		}
							
	}while(n <= 0); // Enquanto o usuário digitar um expoente negativo, o laço se repetirá
	
	
	if(x >= 0){ // Verifica se a base é positiva
		
		result = func(x, n);
		printf("\n%i elevado a %i é igual a %i", x, n, result); // O resultado é positivo
		
	}else{ // A base não é positiva
		
		x = x * (-1);
		result = func(x, n);
		
		// Verifica se expoente é par
		if(n % 2 == 0){ 
			
			printf("\n-%i elevado a %i é igual a %i", x, n, result); // O resultado é positivo
			
		}else{ 
			
			result = result * (-1);
			printf("\n-%i elevado a %i é igual a %i", x, n, result); // O resultado é negativo
			
		}		
	} 
	
	return 0;
}

