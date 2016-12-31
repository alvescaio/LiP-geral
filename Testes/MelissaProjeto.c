/* 
Universidade do Estado do Rio Grande do Norte - UERN
Nome: Catálogo de Loja de Roupas e Sapatos (Código, Nome, Categoria,
Marca, Material, Numeração, Cor, Preço);

Discentes: Ana Melissa e Andresa Dantas; 
Disciplina: Liguagem de Programação Estruturada;
Professora: Camila
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char tipo[30];
	char marca[30], material[30], cor[20];
	int numeracao, codigo;
	float preco;
}Produtos;

void cadastrar(){
	Produtos produtos;
	FILE *p;
	
	printf("Tipo: ");
	scanf("%s", &produtos.tipo);
	fflush(stdin);
	printf("Marca: ");
	scanf("%s", &produtos.marca);
	fflush(stdin);
	printf("Material: ");
	scanf("%s", &produtos.material);
	fflush(stdin);
	printf("Cor: ");
	scanf("%s", &produtos.cor);
	fflush(stdin);
	printf("Numeracao: ");
	scanf("%d", &produtos.numeracao);
	fflush(stdin);
	printf("Codigo: ");
	scanf("%d", &produtos.codigo);
	fflush(stdin);
	printf("Preco: ");
	scanf("%f", &produtos.preco);
	fflush(stdin);
	
	p = fopen("Produtos.txt", "a");
	fprintf(p,"Tipo: %s\n", produtos.tipo);
    fprintf(p,"Marca: %s\n", produtos.marca);
    fprintf(p,"Material: %s\n", produtos.material);
    fprintf(p,"Cor: %s\n", produtos.cor);
    fprintf(p,"Numeracao: %d\n", produtos.numeracao);
    fprintf(p,"Codigo: %d\n", produtos.codigo);
    fprintf(p,"Preco: %2.f\n", produtos.preco);
    fclose(p);

}
void listarProdutos(){
	char c;
	FILE *p;
	
	p = fopen("Produtos.txt", "r");
	while((c=getc(p))!= EOF){
		printf("%c", c);
	}
	fclose(p);
	system("pause");
}
void informacoesProdutos(){ //ANALISAR ESSA PARTE DO CÓDIGO;
	char ch;
	int cont, cont1;
	FILE *p;
	
	ch = getc(p);
	
	p = fopen("info.txt", "a");
	while(ch!=EOF){
		putchar(ch);
		ch = getc(p);
		if(ch=="\n"){
			cont++;
		}
		if(ch==' '){
			cont1++;
		}
	}
	fclose(p);
	fprintf(p, "Quantidade de linhas: %d\n", cont);
	fprintf(p, "Quantidade de espacos: %d\n", cont1);
	fclose(p);
	system("pause");
	
}
void menu(){
	int op = 0;
	FILE *p;
	
	do{
		printf("1 - CADASTRAR PRODUTOS\n");
		printf("2 - PESQUISAR PRODUTOS\n");
		printf("3 - INFORMACOES\n");
		printf("4 - LIMPAR A TELA\n");
		printf("5 - SAIR\n");
		printf("Escolha a opcao desejada: ");
		scanf("%d", &op);
	}while(op<1 || op>6);
	
	if(op==1){
		cadastrar();
	}else if(op==2){
		listarProdutos();
	}else if(op==3){
		informacoesProdutos();
	}else if(op==4){
		p = fopen("Produtos.txt", "w");
		fprintf(p, " ");
		fclose(p);
	}else{
		system("pause");
		exit(1);
	}
}
int main(){
	/*
	while(1){
		system("clear");
		menu();
	}
	*/
	char c;
	FILE *p;
	
	p = fopen("Produtos.txt", "r");
	while((c=getc(p))!= EOF){
		printf("%c", c);
	}
	fclose(p);
	system("pause");
}
