#include <stdio.h>
#include <stdlib.h>

/* Funções relacionadas ao objeto Funcionario:
    - Ler as Informações do txt
    - Escreve as Informações no txt
    - Adiciona um Funcionario em uma Lista de Funcionarios
    - Remove um Funcionario de uma Lista de Funcionarios
    - Edita as informações */

typedef struct funcio{
	int Codigo;
	char *Nome;
	char *Ocupacao;
}Funcionario;

/* Le as informações do txt e as coloca em uma lista de Funcionario
    - Recebe: Ponteiro para Tamanho
    - Retorna: Lista com os dados do txt, Tamanho da Lista para o Ponteiro
    */
Funcionario* Funcio_LerBD(int *tam){
	FILE *fp;

	if(fp=fopen("Funcionarios.txt", "r")){
		fscanf(fp, "%i", tam);

		printf("NUMERO: %i\n\n", *tam);

		Funcionario *Lista = malloc(*tam * sizeof(Funcionario));


		int Cod;
		char* Nome = (char*)malloc(sizeof(char*));
		char* Ocup = (char*)malloc(sizeof(char*));

        int i = 0;

		while(fscanf(fp, "%i;%[^;];%[^\n]",&Cod, Nome, Ocup)!=EOF){
            Funcio_AddToList(&Lista[0], &i, Cod, Nome, Ocup);
		}
		fclose(fp);

		return Lista;
	}
	else{
		printf("Erro ao abrir o arquivo Funcionarios.txt");
		fclose(fp);
	}
}

/* Escreve as informações passadas para um txt para salvar os dados
    - Recebe: Lista para salvar, Tamanho da Lista
*/
void Funcio_writeBD(Funcionario *Lista, int tam){
    FILE *outfile;

    outfile = fopen("Teste.txt", "w");

    if(outfile==NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }

	fprintf(outfile, "%i", tam);

    int i=0;
    for(i=0; i<tam; i++){
        fprintf(outfile, "\n%i;%s;%s", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
    }

    printf("Informação Escrita no Arquivo");

    fclose(outfile);
}

/*  Adiciona as Informações de um Funcionario na Lista com todos os Funcionarios
     - Recebe: Lista para armazenar, Tamanho da lista, Informações Novas (Cod, Nome, Ocup)
     - Retorna: Lista com o Novo Elemento, Tamanho Novo pelo ponteiro
*/
void Funcio_AddToList(Funcionario *Lista, int* tam, int Cod, char* Nome, char* Ocup)
{
    //Lista = realloc(Lista, (n*sizeof(Funcionario)));
    Lista[*tam].Codigo = Cod;

    Lista[*tam].Nome = (char*)malloc(sizeof(Nome));
    strcpy(Lista[*tam].Nome, Nome);

    Lista[*tam].Ocupacao = (char*)malloc(sizeof(Ocup));
    strcpy(Lista[*tam].Ocupacao, Ocup);

    *tam = *tam+1;
}

/*  Remove as Informações de um Funcionario na Lista com todos os Funcionarios
     - Recebe: Lista para armazenar, Tamanho da lista, Codigo do elemento a ser removido
     - Retorna: Lista sem o Elemento, Tamanho Novo pelo ponteiro
*/
void Funcio_RemoveFromList(Funcionario *Lista, int Cod, int* tam)
{
    int i=0, pos=-1;
    for(i=0; i<*tam; i++){
        if(Lista[i].Codigo==Cod){
            pos = i;
        }
    }

    if(pos==-1){
        printf("\nCodigo não Existe na Lista\n");
        return;
    }

    for(i=pos; i<*tam; i++){
        Lista[i] = Lista[i+1];
    }

    *tam = *tam-1;
}


/*  Modifica as Informações de um Funcionario na Lista com as Novas passadas
     - Recebe: Lista dos Funcionarios, Tamanho da lista, Codigo do Funcionario, Informações Novas (Nome, Ocup)
     - Retorna: Lista com as Informações editadas
*/
void Funcio_EditFromList(Funcionario *Lista, int tam, int Cod,  char* NovoNome, char* NovaOcupacao)
{
    int i=0;
    for(i=0; i<tam; i++){
        if(Lista[i].Codigo==Cod){
            Lista[i].Nome = realloc(Lista[i].Nome, sizeof(NovoNome));
            strcpy(Lista[i].Nome, NovoNome);

            Lista[i].Ocupacao = realloc(Lista[i].Ocupacao, sizeof(NovaOcupacao));
            strcpy(Lista[i].Ocupacao, NovaOcupacao);
            return;
        }
    }
}
