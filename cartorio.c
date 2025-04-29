#include <stdio.h>// biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca��es de texto por regi�o
#include <string.h>// biblioteca respons�vel por cuidar das string


int registro()// Fun��o responssavel por cadastrar o usu�rio no sistema
{
	int escolha; //Definindo variavel

	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa esrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "A" significa atualizar
	fprintf(file, ","); // acrescenta uma v�rgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��oes do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "A" significa atualizar
	fprintf(file,nome); // Salva o nome que foi cadastrado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file, " ");// acrescenta um espa�o no arquivo
	fclose(file);// fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// Coletando informa��es do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file,sobrenome); // salvo o sobrenome que foi cadastrado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file, ",");// acrescenta uma v�rgula no arquivo
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// Coletando informa��es do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file,cargo);// salvo o cargo que foi cadastrado
	fclose(file);// fecha o arquivo	
	
	system("cls");
	printf("\t1 - Adicionar novo usu�rio.\n");
	printf("\t2 - Voltar ao menu.\n");
	printf("Op��o: ");
	scanf("%d", &escolha);
	system("cls");
	
	if (escolha == 1){
		registro();
	}else if(escolha == 2){
		return 0;
	}else if(escolha >= 3){
		printf("Essa op��o n�o esta dispon�vel!\n");
		printf("Iremos retorna-lo ao menu!\n");
		system("pause");
	}
}


int consulta()
{
	int escolha;
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	//Inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abre o arquivo e o "R" significa ler
	
	if(file == NULL) // realiza uma pesquisa para ver se o usu�rio realmente esta cadastrado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // retorna as informa��es do usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", &conteudo);
		printf("\n\n");
	}		
	printf("\t1 - Consultar outro usu�rio.\n");
	printf("\t2 - Voltar ao menu.\n");
	printf("Op��o: ");
	scanf("%d", &escolha);
	system("cls");
	
	if (escolha == 1){
		consulta();
	}else if(escolha == 2){
		return 0;
	} else if (escolha >=3){
		printf("Essa op��o n�o esta dispon�vel!\n");
		printf("Iremos retorna-lo ao menu!\n");
		system("pause");
	}
	
	
}

int deletar()
{
	int escolha;
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��es para deletar o usu�rio
	scanf("%s",cpf);
	
	remove(cpf); // remove o usu�rio
	
	FILE *file;
	file = fopen(cpf,"r"); // abre o arquivo o "R" significa ler
	
	if (file == NULL) // realiza uma pesquisa para ver se o usu�rio realmente esta cadastrado
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	system("pause");// sim da escolha
	system("cls");
	
	printf("\t1 - Deletar outro usu�rio.\n");
	printf("\t2 - Voltar ao menu.\n");
	printf("Op��o: ");
	scanf("%d", &escolha);
	system("cls");
	
	if (escolha == 1){
		deletar();
	}else if(escolha == 2){
		return 0;
	} else if (escolha >=3){
		printf("Essa op��o n�o esta dispon�vel!\n");
		printf("Iremos retorna-lo ao menu!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // definindo as variav�is
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	printf("### Cart�rio da EBAC ####\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	system("cls");
	
	if(comparacao == 0)
	{
		for (laco=1; laco=1;)
		{	
		
			system("cls"); // limpa a tela
		
			setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
			printf("### Cart�rio da EBAC ####\n\n"); // inicio do menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n"); 
			printf("\t3- Deletar nomes\n\n"); 
			printf("\t4- Sair do sistema\n\n");
			printf("Op��o: "); // fim do menu
	
			scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
			system("cls"); // limpa a tela
		
			switch(opcao)
			{
				case 1:
				registro(); // chamada de fun��o
				break;
			
				case 2:
				consulta(); // chamada de fun��o
				break;		
		
				case 3:
				deletar(); // chamada de fun��o
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;	
					
				default: // Exibe a mensagem para o usu�rio caso a op��o selecionado n�o exista
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");	
				break;
			}
		}
	}

	else
		printf("Senha incorreta!");
}

