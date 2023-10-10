#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>

void menu(void);
void menu2(void); 
void menu3(void); 
void menu4(void); 
void Cadastrar(void); 
void listar(void); 
void alterar(void); 

int i;  
int a;
char buf[50];

typedef struct nome{
	char n[30];
}nome;

typedef struct registro{
	nome nome_reg; 
	int idade; 
	int pis;
	int rg;
	int cpf;
}registro;	

registro r1[10][6];
	
FILE* OpenArq(char modo, char caminho[30]){
	
	FILE *arq;
	
	switch(modo){
		case 'g':
			arq = fopen(caminho, "wb");
		break;
		
		case 'l':
			arq = fopen(caminho, "rb");
		break; 
		
		case 'a':
			arq = fopen(caminho, "ab");
		break;
	}	
	if (arq==NULL){
		printf("Não foi possivel abrir o arquivo");
		exit(0);		
	}
	
	return arq; 
}

void CloseArq(FILE *arq){
	fclose(arq); 	
}

int main(){
	system("color A");
	system("title REGISTRO FUNCIONARIO"); 
	setlocale(LC_ALL, "Portuguese"); //Habilita a acentuação! 
	menu(); 
	
	return 0; 
}
	
void menu(void){
	
	char var_entrada; 
	
	system ("cls"); 
	printf("\n\n");
        printf("                                            .::REGISTRO DE FUNCIONARIOS::.  \n\n");
        printf("                                      Veja todas as funcoes disponiveis no menu   \n");
        printf("                                   use os números para selecionar a opção desejada.  \n");
        printf("\n\n");
        printf("                                                 MENU PRINCIPAL:");
        printf("\n                                         +------------------------------ + ");
        printf("\n                                         | (1) - REGISTRAR               |");
        printf("\n                                         | (2) - LISTAR OS REGISTROS     |");
        printf("\n                                         | (3) - ALTERAR OU EXCLUIR      |");
        printf("\n                                         | (0) - Sair                    |");
        printf("\n                                         +------------------------------ + ");


        printf("\n\n                                          Selecione a opção desejada: ");
		
	scanf(" %c", &var_entrada);
	
	switch (var_entrada) 
	{
	case '0': 
		system("cls"); 
		printf("PROGRAMA ENCERRADO, PRESSIONE QUALQUER TECLA PARA SAIR.\n");
		exit(0); 
	
	case '1': 
		system("cls"); 
		Cadastrar(); 
	break; 
	
	case '2': 
		system("cls");
		listar();  
	break; 	
	
	case '3': 
		system("cls"); 
		alterar(); 
	break;  
	
	default:
        system("cls"); 
		printf("OPÇÃO INVALIDA, PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.\n\n");
		system("pause"); 
		menu(); 	
	}
}	
	
void Cadastrar(void){ 
	FILE *arq; 
	
	printf("      +--------------------------------------------------------------------------------------------------- +\n"); 
	printf("      |                                     REGISTRO DE FUNCIONARIO                                        |\n"); 
	printf("      |                                                                                                    |\n"); 
	printf("      |  OBS: ESTE MODO IRÁ RECRIAR O ARQUIVO, SE O ARQUIVO JÁ EXISTIR SELECIONE ALTERAR (3) NO MENU   |\n"); 
	printf("      +--------------------------------------------------------------------------------------------------- +\n");
	printf("\n\nDIGITE O NUMERO DE FUNCIONARIOS QUE DESEJA REGISTRAR: "); 
	scanf("%d", &a); 

	system("cls"); 
	
	for(i=0;i<a;i++){
		printf("            +--------------------------------------------------------------------------------------------+\n"); 
		printf("            |                                REGISTRO DE FUNCIONARIO:                                    |\n"); 
		printf("            +--------------------------------------------------------------------------------------------+\n");
		
		printf("\nDIGITE O NOME %do FUNCIONARIO: ", i+1);  
		fflush(stdin); 
		gets(r1[i][0].nome_reg.n);
			
		printf("\nDIGITE A IDADE  do %do FUNCIONARIO: ", i+1); 
		scanf("%d", &r1[i][1].idade); 
		
		printf("\nDIGITE O PIS DO %do FUNCIONARIO: ", i+1); 
		scanf("%d", &r1[i][2].pis);
		
		printf("\nDIGITE O RG %do FUNCIONARIO: ", i+1); 
		scanf("%d", &r1[i][3].rg);
	
		printf("\nDigite o CPF %do FUNCIONARIO: ", i+1);
		scanf("%d", &r1[i][4].cpf);
	
		system("cls");			 		
	}
		
	arq = OpenArq('g', "Registro.txt"); 
	for(i=0; i<a; i++){
		fprintf(arq, "%do Funcionario \nNome: %s \nIdade: %d \nPIS: %d \nRG: %d \nCPF: %d\n\n", i+1 ,r1[i][0].nome_reg.n, r1[i][1].idade, r1[i][2].pis, r1[i][3].rg, r1[i][4].cpf);
	}
	CloseArq(arq);  
 	system("cls");
	 printf("\n    FUNCIONARIO(S) REGISTRADO(S)!   \n");
	 	 menu2();  
}

void listar(void){
	FILE* arq; 			
		arq = OpenArq('l', "Registro.txt"); 	
			while(!feof(arq)){
		fgets(buf, sizeof(buf), arq); 
		puts(buf); 
			}

	CloseArq(arq); 
 	
	 menu3(); 
	
}

void alterar(void, int;){
	FILE *arq; 
	int id;
	char info;
	
		
		printf("DIGITE QUAL FUNCIONARIO DESEJA ALTERAR: ");
		scanf("%d", &id);
		
		printf("DIGITE QUAL INFORMACAO DESEJA ALTERAR NOME(n), IDADE(i), PIS(p), RG(r) e CPF(c): ");
		scanf("%s", &info);
		
		
	//	teste =============================================================================
		arq = OpenArq('a', "Registro.txt");
		if(info=='n')
		{
			printf("\nDIGITE O NOME %do FUNCIONARIO: ", i+1);  
			fflush(stdin);
			scanf("%d", &r1[id][0].nome_reg.n);
			 
			
	//	teste =============================================================================
		}
	CloseArq(arq); 
		menu4(); 
}

void menu2(void){
	   char sair; 
		printf("   +---------------------------+\n");
        printf("   |     DESEJA SAIR? [S/N]    |\n");
        printf("   +---------------------------+\n");
       	printf("                 "); 
	    scanf ("%s",&sair);

        if((sair == 'S') || (sair == 's')){
            system("cls");
            printf("PROGRAMA ENCERRADO, PRESSIONE QUALQUER TECLA PARA SAIR.\n");
            system(0);
        
		}else if((sair == 'N') || (sair == 'n')){
                system("cls");
                    menu();
				}
}

void menu3(void){
	   char sair; 
		printf("   +---------------------------+\n");
        printf("   |     DESEJA SAIR? [S/N]    |\n");
        printf("   |                           |\n");
		printf("   |    IR PARA ALTERAÇÃO [A]  |\n");
		printf("   +---------------------------+\n");
       	printf("                 "); 
	    scanf ("%s",&sair);

        if((sair == 'S') || (sair == 's')){
            system("cls");
            printf("PROGRAMA ENCERRADO, PRESSIONE QUALQUER TECLA PARA SAIR.\n");
            system(0);
        
		}else if((sair == 'N') || (sair == 'n')){
                system("cls");
                    menu();
				}else if((sair=='A') || (sair == 'a')){
					system("cls");
					alterar(); 
				}
}

void menu4(void){
	   char sair; 
		printf("   +---------------------------+\n");
        printf("   |     DESEJA SAIR? [S/N]    |\n");
        printf("   |                           |\n");
		printf("   |    IR PARA REGISTROS [R]  |\n");
		printf("   +---------------------------+\n");
       	printf("                 "); 
	    scanf ("%s",&sair);

        if((sair == 'S') || (sair == 's')){
            system("cls");
            printf("PROGRAMA ENCERRADO, PRESSIONE QUALQUER TECLA PARA SAIR.\n");
            system(0);
        
		}else if((sair == 'N') || (sair == 'n')){
                system("cls");
                    menu();
				}else if((sair=='r') || (sair == 'R')){
					system("cls");
					listar(); 
				}
}
