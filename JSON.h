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
	char *line;
	
	
	if(fp=fopen("Funcionarios.txt", "r")){
		
		while((fscanf(fp, "%s", line))!=EOF){
			printf("%s - \n", line);
		}
		
		printf("\n\nBALLS");
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
	}
	
	fclose(fp);
}
