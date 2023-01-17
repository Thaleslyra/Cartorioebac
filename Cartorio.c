#include <stdio.h> // biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // biblioteca de aloca��o de mem�ria.
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel or cuidar das strings.



	//  ## definindo as fun��es do programa ##
	
	
	//  Fun�ao respons�vel por cadastrar os usu�rios
	
	int registro()
	{
	
	  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	// In�cio da cria��o das vari�veis
		
	  char arquivo[40];	
	  char cpf[40];	
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	
	//Fim das vari�veis
	/////////////////////  
	
	  
	  printf("Digite o CPF a ser cadastrado: "); // Coletando informa��es dos usu�rios
	  scanf("%s", cpf); // o "%s" referese a string
	  
	  
	  strcpy(arquivo, cpf); // fun��o que copia o valor do cpf para o arquivo
	  
	  
	  FILE *file; // cria o arquivo
	  file = fopen(arquivo, "w"); // o w � respons�vel pela escrita no arquivo
	  fprintf(file,cpf); // salva o valor da vari�vel
	  fclose(file); // fecha o arquivo. 
	  
	  file = fopen(arquivo, "a"); //respons�vel por abrir o arquivo
	  fprintf(file, ", "); //insere a v�rgula para separar os dados
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
	// fim da fun��o inserir.	
	/////////////////////////////////
	
	
	
	
	//  In�cio da fun��o de colsulta
	
	int consulta()
	{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o cpf a ser consultado: "); // coletando informa��es do usu�rio
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf , "r"); // l� o arquivo		
		
		if(file == NULL)
		{
			printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n\n");
		}
		
		while(fgets(conteudo, 200, file)!= NULL) // inserindo a leitura do arquivo com a fun��o fgets
		{
			printf("\n Essas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);		
			printf("\n\n");
		}
		
		 fclose(file);
		 
		system("pause");
	}	
	// fim da fun��o consultar
	/////////////////////////////////////
	
	
	
	
	//  Inicio da fu��o deletar
	
	int deletar()
	{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
			
		char cpf[40];				
		
		printf("Digite o CPF do usu�rio a ser deletado: \n\n");
		scanf("%s", cpf);
		
		remove(cpf);
						
		FILE *file;
		file = fopen(cpf,"r");				
	
		if(file == NULL)
		{
			printf("Usu�rio n�o encontrado no sistema. \n\n");
			system("pause");
		}
	
		
	}// Fim da fun��o deletar
	///////////////////////////
	
	
	
	//Fim das fun��es
	////////////////////////////////////



// Fun��o Principal

int main()
{
	
	
	int opcao = 0; // Definindo vari�veis
	int laco = 1; // definindo o la�o.
	char senhaDigitada[10] = "a";
	int retorno;
	
	 printf("#### Cart�rio da Ebac #### \n\n");
	 
	 printf("Login de administrador!\n\nDigite a sua senha: ");
	 scanf("%s", &senhaDigitada);
	 retorno = strcmp (senhaDigitada, "admin");
	 
    if(retorno == 0)
    {
	 	
	 		
		for(laco=1; laco=1;)
	    {
	    	system("cls"); // respons�vel por limpar a tela
	    	
	    	
	    	setlocale(LC_ALL, "Portuguese");  	// insere a linguagem
	    	
		
		    printf("#### Cart�rio da Ebac #### \n\n");
		
		    printf("# Ecolha a op��o desejada do menu: \n\n");
		    
		
			//  in�cio do menu
			
			printf("\t 1 - Registrar nomes\n");
			printf("\t 2 - Consultar nomes\n");
			printf("\t 3 - Deletar nomes\n");
			printf("\t 4 - Sair do sistema.\n\n");
			printf("\t Op��o: ");
		
			//fim do menu
			///////////////////
		
		
			scanf("%d", &opcao); // armazenando a op��o de menu escolhida
		
			system("cls"); // limpando a tela	
	
		
		
		     // analizando as op��es do menu
		     
			switch(opcao)	
			{
				case 1:
			 	    registro();	// chamada de fun��es		  
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
				 	printf("Op��o inv�lida.\n\n");
				 	system("pause");
					
			}   // fim da an�lise das op��es
			/////////////////////////////////		
	   } 
	}
    
	else 
	printf("Senha incorreta!");
   
	
}
