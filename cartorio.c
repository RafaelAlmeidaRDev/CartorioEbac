#include <stdio.h>// biblioteca de comunicação com o usuário
#include <stdlib.h>// biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h>// biblioteca responsável por cuidar das string


int registro()// Função responssavel por cadastrar o usuário no sistema
{
	int escolha; //Definindo variavel

	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa esrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "A" significa atualizar
	fprintf(file, ","); // acrescenta uma vírgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informaçãoes do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "A" significa atualizar
	fprintf(file,nome); // Salva o nome que foi cadastrado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file, " ");// acrescenta um espaço no arquivo
	fclose(file);// fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// Coletando informações do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file,sobrenome); // salvo o sobrenome que foi cadastrado
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file, ",");// acrescenta uma vírgula no arquivo
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// Coletando informações do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");// abre o arquivo e o "A" significa atualizar
	fprintf(file,cargo);// salvo o cargo que foi cadastrado
	fclose(file);// fecha o arquivo	
	
	system("cls");
	printf("\t1 - Adicionar novo usuário.\n");
	printf("\t2 - Voltar ao menu.\n");
	printf("Opção: ");
	scanf("%d", &escolha);
	system("cls");
	
	if (escolha == 1){
		registro();
	}else if(escolha == 2){
		return 0;
	}else if(escolha >= 3){
		printf("Essa opção não esta disponível!\n");
		printf("Iremos retorna-lo ao menu!\n");
		system("pause");
	}
}


int consulta()
{
	int escolha;
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	//Inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abre o arquivo e o "R" significa ler
	
	if(file == NULL) // realiza uma pesquisa para ver se o usuário realmente esta cadastrado
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // retorna as informações do usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", &conteudo);
		printf("\n\n");
	}		
	printf("\t1 - Consultar outro usuário.\n");
	printf("\t2 - Voltar ao menu.\n");
	printf("Opção: ");
	scanf("%d", &escolha);
	system("cls");
	
	if (escolha == 1){
		consulta();
	}else if(escolha == 2){
		return 0;
	} else if (escolha >=3){
		printf("Essa opção não esta disponível!\n");
		printf("Iremos retorna-lo ao menu!\n");
		system("pause");
	}
	
	
}

int deletar()
{
	int escolha;
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando informações para deletar o usuário
	scanf("%s",cpf);
	
	remove(cpf); // remove o usuário
	
	FILE *file;
	file = fopen(cpf,"r"); // abre o arquivo o "R" significa ler
	
	if (file == NULL) // realiza uma pesquisa para ver se o usuário realmente esta cadastrado
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	system("pause");// sim da escolha
	system("cls");
	
	printf("\t1 - Deletar outro usuário.\n");
	printf("\t2 - Voltar ao menu.\n");
	printf("Opção: ");
	scanf("%d", &escolha);
	system("cls");
	
	if (escolha == 1){
		deletar();
	}else if(escolha == 2){
		return 0;
	} else if (escolha >=3){
		printf("Essa opção não esta disponível!\n");
		printf("Iremos retorna-lo ao menu!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // definindo as variavéis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	printf("### Cartório da EBAC ####\n\n");
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
	
			printf("### Cartório da EBAC ####\n\n"); // inicio do menu
			printf("Escolha a opção desejada no menu:\n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n"); 
			printf("\t3- Deletar nomes\n\n"); 
			printf("\t4- Sair do sistema\n\n");
			printf("Opção: "); // fim do menu
	
			scanf("%d", &opcao); // armazenando a escolha do usuário
	
			system("cls"); // limpa a tela
		
			switch(opcao)
			{
				case 1:
				registro(); // chamada de função
				break;
			
				case 2:
				consulta(); // chamada de função
				break;		
		
				case 3:
				deletar(); // chamada de função
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;	
					
				default: // Exibe a mensagem para o usuário caso a opção selecionado não exista
				printf("Essa opção não está disponivel!\n");
				system("pause");	
				break;
			}
		}
	}

	else
		printf("Senha incorreta!");
}

