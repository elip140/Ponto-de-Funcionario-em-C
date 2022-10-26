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
		char Horario[21];

        int i = 0;
		while(fscanf(fp, "%i;%i;%[^\n]",&Cod_Funcio, &Finalidade, &Horario)!=EOF){
            (*Lista)[i].Cod_Funcio = Cod_Funcio;
            (*Lista)[i].Finalidade = Finalidade;
            strcpy((*Lista)[i].Horario, Horario);

            i++;
		}

		fclose(fp);
	}
	else{
		printf("Erro ao abrir o arquivo Log.txt");
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


void Log_AddToList(Log **Lista, int* tam, int Cod, char Horario[21], int Finalidade)
{
    *Lista = realloc(*Lista, ((*tam+1)*sizeof(Log)));

    int i=0;

    if(Finalidade!=1 && Finalidade!=2 && Finalidade!=3 && Finalidade!=4){
        printf("Finalidade não reconhecida\n");
        return;
    }


    (*Lista)[*tam].Cod_Funcio = Cod;
    strcpy((*Lista)[*tam].Horario, Horario);
    (*Lista)[*tam].Finalidade = Finalidade;

    //printf("\nADD LOG LIST -> %i - %s - %i", (*Lista)[*tam].Cod_Funcio, (*Lista)[*tam].Horario, (*Lista)[*tam].Finalidade);

    *tam = *tam+1;
}


