#include <stdio.h>
#include <stdlib.h>

typedef struct Dados{
	int Cod_Funcio;
	char *Nome_Funcio;
	char *Horario;
	int Finalidade; // 1 = Entrada do Trabalho, 2 = Saida do Trabalho, 3 = Entrada do Almoço, 4 = Saida Para Almoço
}Log;

Log* Log_LerBD(int *tam){
	FILE *fp;

	if(fp=fopen("Logs.txt", "r")){
		fscanf(fp, "%i", tam);

		printf("NUMERO: %i\n\n", *tam);

		Log *Lista = malloc(*tam * sizeof(Log));


		int Cod_Funcio;
		int Finalidade;
		char* Nome_Funcio = (char*)malloc(sizeof(char*));
		char* Horario = (char*)malloc(sizeof(char*));

        int i = 0;

		while(fscanf(fp, "%i;%i;%[^;];%[^\n]",&Cod_Funcio, &Finalidade, Nome_Funcio, Horario)!=EOF){
            //Log_AddToList2(&Lista[0], &i, Cod_Funcio, Nome_Funcio, Horario, Finalidade);

            Log L = {Cod_Funcio, Nome_Funcio, Horario, Finalidade};

            //printf("\nL -> %i - %s - %s - %i", L.Cod_Funcio, L.Nome_Funcio, L.Horario, L.Finalidade);

            Lista[i] = L;

            /*Lista[i].Cod_Funcio = L.Cod_Funcio;

            Lista[i].Finalidade = L.Finalidade;

            Lista[i].Horario = (char*)malloc(sizeof(L.Horario));
            strcpy(Lista[i].Horario, L.Horario);

            Lista[i].Nome_Funcio = (char*)malloc(sizeof(L.Nome_Funcio));
            strcpy(Lista[i].Nome_Funcio, L.Nome_Funcio);*/


            //printf("\nADD LOG LIST Function -> %i - %s - %s - %i", Lista[i].Cod_Funcio, Lista[i].Nome_Funcio, Lista[i].Horario, Lista[i].Finalidade);

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

/*
*/
void Log_writeBD(Log* Lista, int tam){
    FILE *outfile;

    outfile = fopen("Teste2.txt", "w");

    if(outfile==NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }

	fprintf(outfile, "%i", tam);

    int i=0;
    for(i=0; i<tam; i++){
        fprintf(outfile, "\n%i;%s;%s;%i", Lista[i].Cod_Funcio, Lista[i].Nome_Funcio, Lista[i].Horario, Lista[i].Finalidade);
    }

    printf("Informação Escrita no Arquivo");

    fclose(outfile);
}

/*
*/
void Log_AddToList(Log *Lista, Funcionario* Lista_F, int* tam, int* tam_Funcionario, int Cod, char* Horario, int Finalidade)
{
    int i=0;
    char* Nome_Funcio;
    int bol = 0;


    for(i=0; i<*tam_Funcionario; i++){
        if(Lista_F[i].Codigo==Cod){
           Nome_Funcio = (char*)malloc(sizeof(Lista_F[i].Nome));
           strcpy(Nome_Funcio, Lista_F[i].Nome);

           printf("\n%s - %s\n", Nome_Funcio, Lista_F[i].Nome);
           bol = 1;
        }
    }


    if(bol==0){
        printf("Codigo não encontrado\n");
        return;
    }

    if(Finalidade!=1 && Finalidade!=2 && Finalidade!=3 && Finalidade!=4){
        printf("Finalidade não reconhecida\n");
        return;
    }




    Lista[*tam].Cod_Funcio = Cod;

    Lista[*tam].Horario = (char*)malloc(sizeof(Horario));
    strcpy(Lista[*tam].Horario, Horario);

    Lista[*tam].Nome_Funcio = (char*)malloc(sizeof(Nome_Funcio));
    strcpy(Lista[*tam].Nome_Funcio, Nome_Funcio);

    Lista[*tam].Finalidade = Finalidade;

    printf("\nADD LOG LIST -> %i - %s - %s - %i", Lista[*tam].Cod_Funcio, Lista[*tam].Nome_Funcio, Lista[*tam].Horario, Lista[*tam].Finalidade);

    *tam = *tam+1;
}

void Log_AddToList2(Log *Lista, int* tam, int Cod, char* Nome, char* Horario, int Finalidade)
{

    /*//printf("\nADD LOG LIST F -> %i - %s - %s - %i", Cod, Nome, Horario, Finalidade);
    printf("\n\nADD LOG LIST FUNCTION");
    printf("\n%i", Cod);
    printf("\n%s", Nome);
    printf("\n%s", Horario);
    printf("\n%i", Finalidade);*/

    Lista[*tam].Cod_Funcio = Cod;

    Lista[*tam].Finalidade = Finalidade;

    Lista[*tam].Horario = (char*)malloc(sizeof(Horario));
    strcpy(Lista[*tam].Horario, Horario);

    Lista[*tam].Nome_Funcio = (char*)malloc(sizeof(Nome));
    strcpy(Lista[*tam].Nome_Funcio, Nome);


    printf("\nADD LOG LIST Function -> %i - %s - %s - %i", Lista[*tam].Cod_Funcio, Lista[*tam].Nome_Funcio, Lista[*tam].Horario, Lista[*tam].Finalidade);

    *tam = *tam+1;
}
void Logf_AddToList(Funcionario *Lista, int* tam, int Cod, char* Nome, char* Ocup)
{
    //Lista = realloc(Lista, (n*sizeof(Funcionario)));
    Lista[*tam].Codigo = Cod;

    Lista[*tam].Nome = (char*)malloc(sizeof(Nome));
    strcpy(Lista[*tam].Nome, Nome);

    Lista[*tam].Ocupacao = (char*)malloc(sizeof(Ocup));
    strcpy(Lista[*tam].Ocupacao, Ocup);

    *tam = *tam+1;
}


