#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct func{
	int Codigo;
	char *Nome;
	char *Ocupacao;

}Funcionario;

struct Log{
	int Cod_Func;
	char *Horario;
	char *Finalidade;
};

Funcionario* LerBD( int *n){
	FILE *fp;

	if(fp=fopen("Funcionarios.txt", "r")){
		fscanf(fp, "%i", n);

		printf("NUMERO: %i\n\n", *n);

		Funcionario *Lista = malloc(*n * sizeof(struct func));


		int Cod;
		char* Nome = (char*)malloc(sizeof(char*));
		char* Ocup = (char*)malloc(sizeof(char*));

        int i = 0;

		while(fscanf(fp, "%i,%[^,],%[^\n]",&Cod, Nome, Ocup)!=EOF){

            AddToList(&Lista[0], &i, Cod, Nome, Ocup);

			printf("LerBD %i - %s - %s \n", Lista[i-1].Codigo, Lista[i-1].Nome, Lista[i-1].Ocupacao);
			//i++;
		}
		fclose(fp);

		return Lista;
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
		fclose(fp);
	}


}

void AddToList(Funcionario *Lista, int* n, int Cod, char* Nome, char* Ocup)
{
    Lista[*n].Codigo = Cod;

    Lista[*n].Nome = (char*)malloc(sizeof(Nome));
    strcpy(Lista[*n].Nome, Nome);

    Lista[*n].Ocupacao = (char*)malloc(sizeof(Ocup));
    strcpy(Lista[*n].Ocupacao, Ocup);

    *n = *n+1;
}

void writeBD(Funcionario *Lista, int n){


    //printf("\n\n Teste Write = %i", n);

    /*Funcionario* Funcionarios = malloc(n * sizeof(struct func));

    Escrever(&Funcionarios[0], 1, "Teste1", "TesteOC");
    Escrever(&Funcionarios[1], 2, "Teste2 LLS", "TesteOC2");
    Escrever(&Funcionarios[2], 3, "Teste3 Ba", "TesteOC3 e");
    Escrever(&Funcionarios[3], 4, "Teste4 ll", "TesteOC4 a");
    Escrever(&Funcionarios[4], 5, "Teste5 o", "TesteOC5 d");
    Escrever(&Funcionarios[5], 6, "Teste6 A", "TesteOC6 - ");*/


    FILE *outfile;

    outfile = fopen("Teste.txt", "w");

    if(outfile==NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }

	fprintf(outfile, "%i", n);

    int i=0;
    for(i=0; i<n; i++){
        fprintf(outfile, "\n%i,%s,%s", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
    }

    printf("Informação Escrita no Arquivo");

    fclose(outfile);
}
