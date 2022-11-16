#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10
typedef struct
{
	char nome[50], endereco[100], telefone[10];
}agenda;

main()
{
	agenda ag[tam];
	char pesq[50];
	int opcao = 0;
	
	while(opcao != 5)
	{
		printf("-------------AGENDA------------\n");
		printf("1 - CADASTRAR\n");
		printf("2 - PESQUISAR\n");
		printf("3 - CLASSIFICAR\n");
		printf("4 - IMPRIMIR\n");
		printf("5 - SAIR\n");
		printf("Digite opcao: ");
		scanf("%d", &opcao);
		switch(opcao)	
		{
			case 1:
				for(int i = 1; i < tam; i++)
				{
					system("cls");
					fflush(stdin);
					printf("\nDigite seu nome: ");
					fgets(ag[i].nome, 50, stdin);
					fflush(stdin);
					printf("\nDigite seu endereco: ");
					fgets(ag[i].endereco, 100, stdin);
					fflush(stdin);
					printf("\nDigite seu telefone: ");
					fgets(ag[i].telefone, 10, stdin);
				}
				system("cls");
				break;
			case 2:  //Pesquisar um registro de cada vez pelo campo nome (usar o metodo sequencial)
				system("cls");
				fflush(stdin);
				printf("Digite o nome para pesquisa: ");
				fgets(pesq, 50, stdin);
				for (int i = 0; i < tam; i++)
				{
					if(strcmp(ag[i].nome,pesq) == 0)
					{
						system("cls");
						printf("\n\tNome: %s", ag[i].nome);
						printf("\n\tEndereco: %s",ag[i].endereco);
						printf("\n\tTelefone: %s", ag[i].telefone);
						printf("\n\n\n\n");
						system("pause");
					}
				}
				system("cls");
				break;
			case 3: //Classificar por ordem de nome os registros cadastrados
				system("cls");
				for(int i=1; i<tam; i++)
				{
        			for(int j=i+1;j<tam;j++)
					{
	        			if(strcoll(ag[i].nome , ag[j].nome) > 0 )
						{
                			ag[0]=ag[i];
                			ag[i]=ag[j];
                			ag[j]=ag[0];
	        			}
        			}
				}
				printf("Agenda classificada com exito!\n\n\n");
				system("pause");
				system("cls");
				break;
			case 4: //Apresentar todos os registros
				system("cls");
				for(int i = 1; i < tam; i++)
				{
					printf("\n\tNome: %s", ag[i].nome);
					printf("\n\tEndereco: %s",ag[i].endereco);
					printf("\n\tTelefone: %s", ag[i].telefone);
				}
				printf("\n\n\n\n");
				system("pause");
				system("cls");
				break;
			case 5: //Sair do programa de cadastro
				break;
			default:
				printf("Opcao Invalida!");
				break;
		}			
	}	
}

