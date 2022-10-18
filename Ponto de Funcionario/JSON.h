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

void LerBD(){
	FILE *fp;
	char buffer[150];
	int n=0;


	if(fp=fopen("Funcionarios.txt", "r")){
		fscanf(fp, "%i", &n);

		Funcionario* Funcionarios = malloc(n * sizeof(struct func));

        int i = 0;
		while((fscanf(fp, "%s", &buffer))!=EOF){
			char *token = strtok(buffer, ",");
			Funcionarios[i].Codigo = atoi(token);
			printf("%s \n", token);

			token = strtok(NULL, ",");
			Funcionarios[i].Nome=(char*)malloc(sizeof(char*));
			strcpy(Funcionarios[i].Nome, token);
			printf("%s \n", token);

			token = strtok(NULL, ",");
			Funcionarios[i].Ocupacao=(char*)malloc(sizeof(char*));
			strcpy(Funcionarios[i].Ocupacao, token);
			printf("%s \n", token);

			i++;
		}
		for (i = 0; i < n; i++){
            free(Funcionarios[i].Nome);
            free(Funcionarios[i].Ocupacao);
            //free(Funcionarios[i]);
        }
		printf(" %i - %s - %s \n", Funcionarios[0].Codigo, Funcionarios[0].Nome, Funcionarios[0].Ocupacao);
		printf(" %i - %s - %s \n", Funcionarios[1].Codigo, Funcionarios[1].Nome, Funcionarios[1].Ocupacao);
		printf(" %i - %s - %s \n", Funcionarios[2].Codigo, Funcionarios[2].Nome, Funcionarios[2].Ocupacao);
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
	}

	fclose(fp);
}

void Escrever(Funcionario *func, int Cod, char* Nome, char* Ocup)
{
    func->Codigo = Cod;

    func->Nome = (char*)malloc(sizeof(Nome));
    strcpy(func->Nome, Nome);

    func->Ocupacao = (char*)malloc(sizeof(Ocup));
    strcpy(func->Ocupacao, Ocup);
}

void writeBD(){
    int n = 6;
    Funcionario* Funcionarios = malloc(n * sizeof(struct func));

    Escrever(&Funcionarios[0], 1, "Teste1", "TesteOC");
    Escrever(&Funcionarios[1], 2, "Teste2 LLS", "TesteOC2");
    Escrever(&Funcionarios[2], 3, "Teste3 Ba", "TesteOC3 e");
    Escrever(&Funcionarios[3], 4, "Teste4 ll", "TesteOC4 a");
    Escrever(&Funcionarios[4], 5, "Teste5 o", "TesteOC5 d");
    Escrever(&Funcionarios[5], 6, "Teste6 A", "TesteOC6 - ");

    printf("%i - %s - %s", Funcionarios[2].Codigo, Funcionarios[2].Nome, Funcionarios[2].Ocupacao);

    FILE *outfile;

    outfile = fopen("Teste.txt", "w");

    if(outfile==NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }

    int i=0;
    for(i=0; i<n; i++){
        fwrite(&Funcionarios[i], sizeof(Funcionarios[i]), 1, outfile);
    }

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    fclose(outfile);
}


