#include <stdio.h>
#include <stdlib.h>

/* Funções relacionadas ao objeto Funcionario:
    - Ler as Informações do txt
    - Escreve as Informações no txt
    - Adiciona um Funcionario em uma Lista de Funcionarios
    - Remove um Funcionario de uma Lista de Funcionarios*/

typedef struct funcio{
	int Codigo;
	char *Nome;
	char *Ocupacao;

}Funcionario;

/* Le as informações do txt e as coloca em uma lista de Funcionario */
Funcionario* LerBD( int *n){
	FILE *fp;

	if(fp=fopen("Funcionarios.txt", "r")){
		fscanf(fp, "%i", n);

		printf("NUMERO: %i\n\n", *n);

		Funcionario *Lista = malloc(*n * sizeof(Funcionario));


		int Cod;
		char* Nome = (char*)malloc(sizeof(char*));
		char* Ocup = (char*)malloc(sizeof(char*));

        int i = 0;

		while(fscanf(fp, "%i,%[^,],%[^\n]",&Cod, Nome, Ocup)!=EOF){
            AddToList(&Lista[0], &i, Cod, Nome, Ocup);
		}
		fclose(fp);

		return Lista;
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
		fclose(fp);
	}
}


void writeBD(Funcionario *Lista, int n){
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


void AddToList(Funcionario *Lista, int* n, int Cod, char* Nome, char* Ocup)
{
    //Lista = realloc(Lista, (n*sizeof(Funcionario)));
    Lista[*n].Codigo = Cod;

    Lista[*n].Nome = (char*)malloc(sizeof(Nome));
    strcpy(Lista[*n].Nome, Nome);

    Lista[*n].Ocupacao = (char*)malloc(sizeof(Ocup));
    strcpy(Lista[*n].Ocupacao, Ocup);

    *n = *n+1;
}

void RemoveFromList(Funcionario *Lista, int pos, int* n)
{
    if(pos>*n){
        printf("\nPosição maior que o tamanho do Vetor\n");
        return;
    }
    int i=0;
    for(i=pos-1; i<*n; i++){
        Lista[i] = Lista[i+1];
    }
    *n = *n-1;
}
