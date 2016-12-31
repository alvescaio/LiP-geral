#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{ //estrutura de data de nascimento
 int dia, mes, ano;
 }Data;
 
typedef struct{//estrutura de endereço
  char rua[50];
  char bairro[50];
  char complemento[50];
  int numero;    
  }Endereco;
  
typedef struct{//estrutura do funcionario
  char nome[50];
  int telefone;
  char *cpf;
  Data datadenascimento;
  float salario;
  char email[50];
  char cargo[50];
  Endereco endereco;
  char sexo[50];
  char estadocivil[50];
  }Funcionario;
  
  
  
void busca(){
	FILE *p = fopen("funcionarios.txt", "a+"); // Abre arquivo para edição e leitura
	Funcionario funcionarioPesquisado; // Variavel do tipo Funcionario para armazenar os valores pesquisados 
	Funcionario funcionarioAserPesquisado; // Variavel para obter os termos que serao pesquisados
	
	// Aloca dinâmicamente 12 espaços de memória do tamanho de char em funcionarioPesquisado.cpf e em funcionarioAserPesquisado.cpf
	funcionarioPesquisado.cpf = (char*) calloc(12, sizeof(char)); 
	funcionarioAserPesquisado.cpf = (char*) calloc(12, sizeof(char));
	
	// preenchendo funcionarioAserUsado com valores padrao
	strcpy(funcionarioAserPesquisado.nome, "#--#--");
	strcpy(funcionarioAserPesquisado.cargo, "#--#--");
	strcpy(funcionarioAserPesquisado.endereco.bairro, "#--#--");
	strcpy(funcionarioAserPesquisado.sexo, "#--#--");
	funcionarioAserPesquisado.salario = 1199842.2131;
	strcpy(funcionarioAserPesquisado.cpf, "#--#--");
	
	// Menu de pesquisa 
	int op; // Variavel para ler opção
	printf("\nEscolha o tipo de dados a ser pesquisado: \n");
	printf("[1] - Nome\n");
	printf("[2] - Cargo\n");
	printf("[3] - Bairro\n");
	printf("[4] - Gênero\n");
	printf("[5] - Salario\n");
	printf("[6] - CPF\n");
	printf("> ");
	do{
		scanf("%d", &op);
	}while(op < 1 || op > 6);	
	
	switch(op){
		case 1:
			printf("Digite o NOME a ser pesquisado: ");
			limpaBuffer(); 
			gets(funcionarioAserPesquisado.nome);
			printf("\n--%s--\n", funcionarioAserPesquisado.nome);
			limpaBuffer(); // Limpa o buffer do teclado
			break;
		case 2:
			printf("Digite o CARGO a ser pesquisado: ");
			limpaBuffer(); 
			gets(funcionarioAserPesquisado.cargo);
			printf("\n--%s--\n", funcionarioAserPesquisado.cargo);
			limpaBuffer(); // Limpa o buffer do teclado
			break;
		case 3:
			printf("Digite o BAIRRO ser pesquisado: ");
			limpaBuffer(); 
			gets(funcionarioAserPesquisado.endereco.bairro);
			printf("\n--%s--\n", funcionarioAserPesquisado.endereco.bairro);
			limpaBuffer(); // Limpa o buffer do teclado
			break;
		case 4:
			printf("Digite o GENERO a ser pesquisado: [M|F]");
			limpaBuffer(); 
			gets(funcionarioAserPesquisado.sexo);
			printf("\n--%s--\n", funcionarioAserPesquisado.sexo);
			limpaBuffer(); // Limpa o buffer do teclado
			break;
		case 5:
			printf("Digite o SALARIO a ser pesquisado: ");
			scanf("%f", funcionarioAserPesquisado.salario);
			limpaBuffer(); // Limpa o buffer do teclado
			break;
		case 6:
			printf("Digite o CPF a ser pesquisado: ");
			limpaBuffer(); 
			gets(funcionarioAserPesquisado.cpf);
			printf("\n--%s--\n", funcionarioAserPesquisado.cpf);
			limpaBuffer(); // Limpa o buffer do teclado
			break;
	}
	
	// Ler primeira linha do arquivo
	while(fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.nome) != EOF){
		
		//Ler as próximas 11 linhas do arquivo, completando as informações de 1 funcionário, o laço (while) garante que todos os dados sejam lidos
		fscanf(p, "%s\n", funcionarioPesquisado.cargo);
		fscanf(p, "%s\n", funcionarioPesquisado.email);
		fscanf(p, "%d\n", &funcionarioPesquisado.telefone);
		fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.endereco.rua);
		fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.endereco.complemento);
		fscanf(p, "%d\n", &funcionarioPesquisado.endereco.numero);
		fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.endereco.bairro);
		fscanf(p, "%f\n", &funcionarioPesquisado.salario);
		fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.estadocivil);
		fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.sexo);
		fscanf(p, "%[0-9a-zA-Z ]\n", funcionarioPesquisado.cpf);
		
		// Compara as informações digitadas com as informações lidas do arquivo
		// Se alguma das informações capturadas na pesquisa bater com a informação lida do arquivo, toda a informação do funcionário será mostrada na tela
		if(strcmp(funcionarioAserPesquisado.nome, funcionarioPesquisado.nome) == 0 ||
		   strcmp(funcionarioAserPesquisado.cargo, funcionarioPesquisado.cargo) == 0 ||
		   strcmp(funcionarioAserPesquisado.endereco.bairro, funcionarioPesquisado.endereco.bairro) == 0 ||
		   strcmp(funcionarioAserPesquisado.sexo, funcionarioPesquisado.sexo) == 0 ||
		   (funcionarioAserPesquisado.salario == funcionarioPesquisado.salario) ||
		   strcmp(funcionarioAserPesquisado.cpf, funcionarioPesquisado.cpf) == 0 ){
			   
			// Imprimindo as informações do funcionario buscado na tela   
			printf("\nNome: %s--\n", funcionarioPesquisado.nome);
			printf("Cargo: %s--\n", funcionarioPesquisado.cargo);
			printf("Email: %s--\n", funcionarioPesquisado.email);
			printf("Tel: %d--\n", funcionarioPesquisado.telefone);
			printf("Rua: %s--\n", funcionarioPesquisado.endereco.rua);
			printf("Complemento: %s--\n", funcionarioPesquisado.endereco.complemento);
			printf("Numero: %d--\n", funcionarioPesquisado.endereco.numero);
			printf("Bairro: %s--\n", funcionarioPesquisado.endereco.bairro);
			printf("Salario: %.2f--\n", funcionarioPesquisado.salario);
			printf("Estado civil: %s--\n", funcionarioPesquisado.estadocivil);
			printf("Sexo: %s--\n", funcionarioPesquisado.sexo);
			printf("Cpf: %s--\n", funcionarioPesquisado.cpf);
		}	
	}
	
	fclose(p); // Fecha o arquivo
	
}
  
void geraInfo(){
	
	char nomeArquivo[30] = "funcionarios.txt";
	FILE *p = fopen(nomeArquivo, "a+"); // "a+" -> edita e ler arquivo, se n existir cria um novo
	int contLetra = 0, contLinha = 0, contPalavras = 0, contEspaco = 0; // Variáveis contadoras
	char c;

	while((c = fgetc(p)) != EOF){

		// Condição para o caracter lido ser uma letra
		if(c != ' ' && c != '\n' && c != '\0'){ 
			contLetra++;
		}

		// Condição para o caracter lido ser uma quebra de linha
		if(c == '\n'){ 
			contLinha++;
		}

		// Condiçao para o caracter lido ser um divisor de palavras (espaço ou quebra de linha)
		if(c == ' ' || c == '\n'){ 
			contPalavras++;
		}

		// Condição para o caracter lido ser um espaço
		if(c == ' '){  
			contEspaco++;
		}

	}

	fclose(p); // Fecha arquivo "funcionarios.txt"

	p = fopen("info.txt", "w"); // Abre o arquivo "info.txt" em modo escrita


	// Ecreve as informações no arquivo "info.txt":
	fprintf(p, "Nome do arquivo: %s\n", nomeArquivo);
	fprintf(p, "Numero de caracteres: %d\n", contLetra);
	fprintf(p, "Numero de linhas: %d\n", contLinha);
	fprintf(p, "Numero de palavras: %d\n", contPalavras);
	fprintf(p, "Numero de espaços: %d\n", contEspaco);

	fclose(p); // fecha o arquivo
		 
}  
 
// Função de cadastramento
void cadastrar(){ 
	
	Funcionario funcionario; 
	
	printf("Digite um nome: ");
	limpaBuffer(); // limpa o buffer do teclado
	gets(funcionario.nome);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o cargo: ");
	gets(funcionario.cargo);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o email: ");
	gets(funcionario.email);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite telefone para contato: ");
	scanf("%d", &funcionario.telefone);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite a rua: ");
	gets(funcionario.endereco.rua);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o complemento: ");
	gets(funcionario.endereco.complemento);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o numero da casa: ");
	scanf("%d", &funcionario.endereco.numero);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o bairro: ");
	gets(funcionario.endereco.bairro);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o salario: ");
	scanf("%f", &funcionario.salario);
	limpaBuffer(); // limpa o buffer do teclado

	printf("Digite o estado civil: ");
	gets(funcionario.estadocivil);
	limpaBuffer(); // limpa o buffer do teclado

	do{
		
		printf("Digite o sexo: [M|F] ");
		gets(funcionario.sexo);
		limpaBuffer(); // limpa o buffer do teclado
		
	}while(strcmp(funcionario.sexo, "M") != 0 
			&& strcmp(funcionario.sexo, "m") != 0 
			&& strcmp(funcionario.sexo, "F") != 0 
			&& strcmp(funcionario.sexo, "f") != 0);

	funcionario.cpf = (char*) calloc(11, sizeof(char)); //Aloca 11 posições de memória do tamanho de um char para a variavel funcionario.cpf

	do{	
		printf("Digite o CPF: ");
		gets(funcionario.cpf);
		limpaBuffer(); // limpa o buffer do teclado
	}while(strlen(funcionario.cpf) != 11);

	FILE *p = fopen("funcionarios.txt", "a"); // abrir o arquivo para editar ''a''

	//Escrever informações dentro do arquivo:

	fprintf(p,"%s\n", funcionario.nome);
	fprintf(p,"%s\n", funcionario.cargo);
	fprintf(p,"%s\n", funcionario.email);
	fprintf(p,"%d\n", funcionario.telefone);
	fprintf(p,"%s\n", funcionario.endereco.rua);
	fprintf(p,"%s\n", funcionario.endereco.complemento);
	fprintf(p,"%d\n", funcionario.endereco.numero);
	fprintf(p,"%s\n", funcionario.endereco.bairro);
	fprintf(p,"%.2f\n", funcionario.salario);
	fprintf(p,"%s\n", funcionario.estadocivil);
	fprintf(p,"%s\n", funcionario.sexo);
	fprintf(p,"%s\n", funcionario.cpf);

	fclose(p); //fechar arquivo
}

// Listagem de funcionários
void listarfuncionario(){
	char linhaLida[30]; //Variavel para armazenar a string referente à linha lida
	FILE *p = fopen("funcionarios.txt", "r"); // abrir o arquivo para leitura
	int contLinha = 1; //Variavel para informar o numero da linha lida

	while(fgets(linhaLida, 30, p) != NULL){
	
		switch(contLinha){
			case 1: 
				printf("Nome: %s", linhaLida);
				break;
			case 2: 
				printf("Cargo: %s", linhaLida);
				break;
			case 3: 
				printf("Email: %s", linhaLida);
				break;
			case 4: 
				printf("Telefone: %s", linhaLida);
				break;
			case 5: 
				printf("Rua: %s", linhaLida);
				break;
			case 6: 
				printf("Complemento: %s", linhaLida);
				break;
			case 7: 
				printf("Numero: %s", linhaLida);
				break;
			case 8: 
				printf("Bairro: %s", linhaLida);
				break;
			case 9: 
				printf("Salario: %s", linhaLida);
				break;
			case 10: 
				printf("Estado civil: %s", linhaLida);
				break;
			case 11: 
				printf("Sexo: %s", linhaLida);
				break;
			case 12: 
				printf("CPF: %s", linhaLida);
				break;			
		}
	
		contLinha++;
	
		if(contLinha > 12){
			printf("\n");
			contLinha = 1;
		}
	}    
 
	fclose(p);
	system("pause");
}

// Imprime o menu na tela e controla as orecoes tomadas
void menu(){ 
	
	int op = 0;
	
	do{
		
		printf("\n----------------------------\n");
		printf("  CONTROLE DE FUNCIONARIOS\n");
		printf("----------------------------\n");
		printf("1 - cadastar funcionarios\n");
		printf("2 - Listar funcionarios\n");
		printf("3 - Limpar lista\n");
		printf("4 - gerar arquivo de informacoes\n");
		printf("5 - buscar funcionarios\n");
		printf("6 - Sair\n");
		printf("> ");
		scanf("%d", &op);
	  
	}while(op < 1 || op > 6);
  
	if(op == 1){
	
		cadastrar();
	
	}else if(op == 2){
	
	
		listarfuncionario();
 
	}else if(op == 3){
	
        FILE *p = fopen("funcionarios.txt", "w");
		fprintf(p, "");
		fclose(p);
	
	}else if(op == 4){
	  
		geraInfo();
		system("pause");
	  
	}else if(op == 5){
	  
		busca();
		system("pause");
	
	}else{
		
		system("pause");
		exit(1);
	
	}
}
 
// Função auxiliar para limpar o buffer do teclado
void limpaBuffer(void){
	 char c;
	 while((c = getchar()) != '\n' && c != EOF);
}


int main(){
	while(1){
		system("cls");
		menu();
	}
	system("pause");
  
}
