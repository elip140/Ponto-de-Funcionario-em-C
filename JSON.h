#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Funcionario{
	int Codigo;
	char *Nome;
	char *Ocupacao;
	
};

struct Log{
	int Cod_Func;
	char *Horario;
	char *Finalidade;
};

void LerBD(){
	FILE *fp;
	char buffer[150];
	int n=0;
	
	
	if(fp=fopen("Funcionarios.txt", "r")){
		fscanf(fp, "%i", &n);
		
		
		
		while((fscanf(fp, "%s", &buffer))!=EOF){
			
			char *token = strtok(buffer, ",");
			printf("Teste1 - %s - a\n", token);
			token = strtok(NULL, ",");
				printf("Teste2 - %s - a\n", token);
				token = strtok(NULL, ",");
					printf("Teste3 - %s - a\n", token);
		}
		
		printf("\n\nBALLS");
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
	}
	
	fclose(fp);
}
