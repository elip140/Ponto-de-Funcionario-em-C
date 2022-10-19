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

Funcionario* LerBD(){
	FILE *fp;
	char buffer[150];
	int n=0;


	if(fp=fopen("Teste3.txt", "r")){
		fscanf(fp, "%i", &n);

		printf("NUMERO: %i\n\n", n);

		Funcionario* Lista = malloc(n * sizeof(struct func));


		int Cod;
		char* Nome = (char*)malloc(sizeof(char*));
		char* Ocup = (char*)malloc(sizeof(char*));

        int i = 0;

		while(fscanf(fp, "%i,%[^,],%[^\n]",&Cod, Nome, Ocup)!=EOF){
			Lista[i].Codigo = Cod;

            Lista[i].Nome = (char*)malloc(sizeof(Nome));
			strcpy(Lista[i].Nome, Nome);

			Lista[i].Ocupacao = (char*)malloc(sizeof(Ocup));
			strcpy(Lista[i].Ocupacao, Ocup);

			printf("LerBD %i - %s - %s \n", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
			i++;
		}
		fclose(fp);
		return Lista;

	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
		fclose(fp);
	}


}

void Escrever(Funcionario *func, int Cod, char* Nome, char* Ocup)
{
    func->Codigo = Cod;

    func->Nome = (char*)malloc(sizeof(Nome));
    strcpy(func->Nome, Nome);

    func->Ocupacao = (char*)malloc(sizeof(Ocup));
    strcpy(func->Ocupacao, Ocup);

    printf("Escrever -> %i - %s - %s \n", func->Codigo, func->Nome, func->Ocupacao);
}

void writeBD(){
    //int n = sizeof(Lista)/sizeof(struct func);
    int n = 6;

    Funcionario* Funcionarios = malloc(n * sizeof(struct func));

    Escrever(&Funcionarios[0], 1, "Teste1", "TesteOC");
    Escrever(&Funcionarios[1], 2, "Teste2 LLS", "TesteOC2");
    Escrever(&Funcionarios[2], 3, "Teste3 Ba", "TesteOC3 e");
    Escrever(&Funcionarios[3], 4, "Teste4 ll", "TesteOC4 a");
    Escrever(&Funcionarios[4], 5, "Teste5 o", "TesteOC5 d");
    Escrever(&Funcionarios[5], 6, "Teste6 A", "TesteOC6 - ");


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
        fprintf(outfile, "\n%i\n%s\n%s", Funcionarios[i].Codigo, Funcionarios[i].Nome, Funcionarios[i].Ocupacao);
    }

    printf("Informação Escrita no Arquivo");

    fclose(outfile);
}

void Ler2(){
	Funcionario Funcio[6];
	FILE * infile = fopen("Teste.bin", "r");

	if(infile != NULL)
	{
		int i = 0;
		while(1)
		{
			Funcionario fun;

			// fread ler os dados
			// retorna a quantidade de elementos lidos com sucesso
			size_t r = fread(&fun, sizeof(Funcionario), 1, infile);

			// se retorno for menor que o count, então sai do loop
			if(r < 1)
				break;
			else
				Funcio[i++] = fun;
		}
		fclose(infile); // fecha o arquivo

		i=0;
		printf("\n\nLeitura\n");
		for(i=0; i<6; i++){
			printf("\n %i - %s - %s", Funcio[i].Codigo, Funcio[i].Nome, Funcio[i].Ocupacao);
		}
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
