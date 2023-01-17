#include <stdio.h> // biblioteca de comunicação com o usuário.
#include <stdlib.h> // biblioteca de alocação de memória.
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável or cuidar das strings.



	//  ## definindo as funções do programa ##
	
	
	//  Funçao responsável por cadastrar os usuários
	
	int registro()
	{
	
	  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	// Início da criação das variáveis
		
	  char arquivo[40];	
	  char cpf[40];	
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	
	//Fim das variáveis
	/////////////////////  
	
	  
	  printf("Digite o CPF a ser cadastrado: "); // Coletando informações dos usuários
	  scanf("%s", cpf); // o "%s" referese a string
	  
	  
	  strcpy(arquivo, cpf); // função que copia o valor do cpf para o arquivo
	  
	  
	  FILE *file; // cria o arquivo
	  file = fopen(arquivo, "w"); // o w é responsável pela escrita no arquivo
	  fprintf(file,cpf); // salva o valor da variável
	  fclose(file); // fecha o arquivo. 
	  
	  file = fopen(arquivo, "a"); //responsável por abrir o arquivo
	  fprintf(file, ", "); //insere a vírgula para separar os dados
	  fclose(file); //fecha o arquivo
	  
	  printf("Digite o nome a ser cadastrado: "); 
	  scanf("%s",nome);
	  
	  file = fopen(arquivo, "a"); 
	  fprintf(file,nome);
	  fclose(file);	  
	  
	  file = fopen(arquivo, "a");
	  fprintf(file, ", ");
	  fclose(file);
	  
	  printf("Digite o sobrenome a ser cadastrado: ");
	  scanf("%s", sobrenome);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file,sobrenome);
	  fclose(file);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file, ", ");
	  fclose(file);
	  
	  printf("Digite o cargo a ser cadastrado: ");
	  scanf("%s", cargo);
	  
	  file =fopen(arquivo, "a");
	  fprintf(file,cargo);
	  fclose(file);
	  
	  system("pause"); 
	  
	  	
	}	
	// fim da função inserir.	
	/////////////////////////////////
	
	
	
	
	//  Início da função de colsulta
	
	int consulta()
	{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o cpf a ser consultado: "); // coletando informações do usuário
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf , "r"); // lê o arquivo		
		
		if(file == NULL)
		{
			printf("Não foi possível abrir o arquivo, não localizado.\n\n");
		}
		
		while(fgets(conteudo, 200, file)!= NULL) // inserindo a leitura do arquivo com a função fgets
		{
			printf("\n Essas são as informações do usuário: ");
			printf("%s", conteudo);		
			printf("\n\n");
		}
		
		 fclose(file);
		 
		system("pause");
	}	
	// fim da função consultar
	/////////////////////////////////////
	
	
	
	
	//  Inicio da fução deletar
	
	int deletar()
	{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
			
		char cpf[40];				
		
		printf("Digite o CPF do usuário a ser deletado: \n\n");
		scanf("%s", cpf);
		
		remove(cpf);
						
		FILE *file;
		file = fopen(cpf,"r");				
	
		if(file == NULL)
		{
			printf("Usuário não encontrado no sistema. \n\n");
			system("pause");
		}
	
		
	}// Fim da função deletar
	///////////////////////////
	
	
	
	//Fim das funções
	////////////////////////////////////



// Função Principal

int main()
{
	
	
	int opcao = 0; // Definindo variáveis
	int laco = 1; // definindo o laço.
	char senhaDigitada[10] = "a";
	int retorno;
	
	 printf("#### Cartório da Ebac #### \n\n");
	 
	 printf("Login de administrador!\n\nDigite a sua senha: ");
	 scanf("%s", &senhaDigitada);
	 retorno = strcmp (senhaDigitada, "admin");
	 
    if(retorno == 0)
    {
	 	
	 		
		for(laco=1; laco=1;)
	    {
	    	system("cls"); // responsável por limpar a tela
	    	
	    	
	    	setlocale(LC_ALL, "Portuguese");  	// insere a linguagem
	    	
		
		    printf("#### Cartório da Ebac #### \n\n");
		
		    printf("# Ecolha a opção desejada do menu: \n\n");
		    
		
			//  início do menu
			
			printf("\t 1 - Registrar nomes\n");
			printf("\t 2 - Consultar nomes\n");
			printf("\t 3 - Deletar nomes\n");
			printf("\t 4 - Sair do sistema.\n\n");
			printf("\t Opção: ");
		
			//fim do menu
			///////////////////
		
		
			scanf("%d", &opcao); // armazenando a opção de menu escolhida
		
			system("cls"); // limpando a tela	
	
		
		
		     // analizando as opções do menu
		     
			switch(opcao)	
			{
				case 1:
			 	    registro();	// chamada de funções		  
				break;
				
				case 2:
					consulta();				
				break;
				
				case 3:
					deletar();					
				break;					 
				
				case 4:
					printf("Obrigado por utiizar o sistema.\n\n");				
				return 0;
				break;			
				
				default:
				 	printf("Opção inválida.\n\n");
				 	system("pause");
					
			}   // fim da análise das opções
			/////////////////////////////////		
	   } 
	}
    
	else 
	printf("Senha incorreta!");
   
	
}
