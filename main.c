#include <stdio.h>
#include <stdlib.h>
#include "JSON.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	FILE *fp;
	char *line;
	printf("TESTE");
	
	if(fp=fopen("Funcionarios.txt", "r")){
		printf("TESTE");
		
		while((fscanf(fp, "%s", line))!=EOF){
			printf("%s - \n", line);
		}
		
		printf("\n\nBALLS");
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
	}
	
	fclose(fp);
	return 0;
}
