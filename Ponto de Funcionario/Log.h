#include <stdio.h>
#include <stdlib.h>

typedef struct Dados{
	int Cod_Funcio;
	char Horario[21];
	int Finalidade; // 1 = Entrada do Trabalho, 2 = Saida do Trabalho, 3 = Entrada do Almoço, 4 = Saida Para Almoço
}Log;

int Log_LerTam(){
    FILE *fp;
    int tam=0;

	if(fp=fopen("Teste_Log.txt", "r")){
		fscanf(fp, "%i", &tam);
		return tam;
	}
	else{
        printf("Erro ao abrir o arquivo Logs.txt");
	}
}

void Log_LerBD(Log **Lista){
	FILE *fp;

	if(fp=fopen("Teste_Log.txt", "r")){
        int tam;
		fscanf(fp, "%i", &tam);



		int Cod_Funcio;
		int Finalidade;
		//char *Nome_Funcio = (char*)malloc(sizeof(char*));
		char Horario[21];

        int i = 0;
		while(fscanf(fp, "%i;%i;%[^\n]",&Cod_Funcio, &Finalidade, &Horario)!=EOF){

            (*Lista)[i].Cod_Funcio = Cod_Funcio;

            (*Lista)[i].Finalidade = Finalidade;

            //(*Lista)[i].Horario = (char*)malloc(sizeof(char*));
            strcpy((*Lista)[i].Horario, Horario);

            /*(*Lista)[i].Nome_Funcio = (char*)malloc(sizeof(char*));
            strcpy((*Lista)[i].Nome_Funcio, Nome_Funcio);*/


            //printf("\nADD LOG LIST Function -> %i - %s - %i", (*Lista)[i].Cod_Funcio, (*Lista)[i].Horario, (*Lista)[i].Finalidade);

            i++;
		}
		//free(Nome_Funcio);
		//free(Horario);
		fclose(fp);
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
        fprintf(outfile, "\n%i;%i;%s", Lista[i].Cod_Funcio, Lista[i].Finalidade, Lista[i].Horario);
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

    //Lista[*tam].Horario = (char*)malloc(sizeof(Horario));
    strcpy(Lista[*tam].Horario, Horario);

    /*Lista[*tam].Nome_Funcio = (char*)malloc(sizeof(Nome_Funcio));
    strcpy(Lista[*tam].Nome_Funcio, Nome_Funcio);*/

    Lista[*tam].Finalidade = Finalidade;

    printf("\nADD LOG LIST -> %i - %s - %i", Lista[*tam].Cod_Funcio, Lista[*tam].Horario, Lista[*tam].Finalidade);

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


