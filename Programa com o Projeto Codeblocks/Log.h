#include <stdio.h>
#include <stdlib.h>
#include "Converter.h"


typedef struct Dados{
	int Cod_Funcio;
	char Horario[21];
	int Finalidade; // 1 = Entrada do Trabalho, 2 = Saida do Trabalho, 3 = Entrada do Almoço, 4 = Saida Para Almoço
}Log;

char Finalidade[5][20] = {"", "Entrada do Trabalho", "Saida do Trabalho", "Entrada do Almoço", "Saida Para Almoço"};


/* Le as informações do txt e coloca a quantidade de elementos da Lista de LOGs
    - Retorna: Quantidade de elementos da Lista
*/
int Log_LerTam(){
    FILE *fp;
    int tam=0;

	if(fp=fopen("Logs.txt", "r")){
		fscanf(fp, "%i", &tam);
		return tam;
	}
	else{
        printf("Erro ao abrir o arquivo Logs.txt");
	}
}

/*  Le as informações do txt e as coloca numa Lista de Logs
     - Recebe: Ponteiro para Lista de Log
     - Retorna: As informações do txt na Lista de Log
*/
void Log_LerBD(Log **Lista){
	FILE *fp;

	if(fp=fopen("Logs.txt", "r")){
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

/* Escreve as informações passadas para um txt para salvar os dados
    - Recebe: Lista de Logs para salvar, Tamanho da Lista
*/
void Log_writeBD(Log* Lista, int tam){
    FILE *outfile;

    outfile = fopen("Logs.txt", "w");

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

    printf("\nInformacao Escrita no Arquivo");

    fclose(outfile);
}

/* Adiciona um novo Log na Lista de Logs
    - Recebe: Ponteiro para Lista de LOG, ponteiro para inteiro do tamanho da Lista, Codigo, Horario, Finalidade
    - Retorna: Lista com o novo elemento, Tamanho atulizado da Lista
*/
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

/* Escreve na tela todos os elementos da lista de Logs com o Nome presente na Lista de Funcionarios
    - Recebe: Lista de Logs, Tamanho da Lista de Logs, Lista de Funcionarios, Tamanho da Lista de Funcionarios
*/
void Log_ShowLogs(Log *Lista_L, int tam_L, Funcionario *Lista_F, int tam_F){
    int i=0;

    printf("\n Todos os Logs ");
    printf("\nCod -- Nome -- Horario -- Finalidade");

    for(i=0; i<tam_L; i++){

        int j=0;
        for(j=0; j<tam_F; j++){
            if(Lista_L[i].Cod_Funcio==Lista_F[j].Codigo){
                printf("\n %i - %s - %s - %s", Lista_L[i].Cod_Funcio, Lista_F[j].Nome, Lista_L[i].Horario, Finalidade[Lista_L[i].Finalidade]);
                break;
            }
        }
    }
}

/* Escreve na tela todos os Logs de um Funcionario Especifico
    - Recebe: Lista de Logs, Tamanho da Lista de Logs, Lista de Funcionarios, Tamanho da Lista de Funcionarios, Codigo do Funcionario
*/
void Log_ShowLogFuncio(Log *Lista_L, int tam_L, Funcionario *Lista_F, int tam_F, int Cod_Funcio){
    int i=0;
    int pos=-1;

    for(i=0; i<tam_F; i++){
        if(Lista_F[i].Codigo==Cod_Funcio){
            pos = i;
            break;
        }
    }

    if(pos==-1){
        printf("\nFuncionario não encontrado");
        return;
    }

    printf("\n Logs do Funcionario de Cod: %i ", Cod_Funcio);
    printf("\nCod -- Nome -- Horario -- Finalidade");
    for(i=0; i<tam_L; i++){
        if(Lista_L[i].Cod_Funcio==Lista_F[pos].Codigo){
            printf("\n %i - %s - %s - %s", Lista_L[i].Cod_Funcio, Lista_F[pos].Nome, Lista_L[i].Horario, Finalidade[Lista_L[i].Finalidade]);
        }
    }
}

void Log_ShowTempoMedio(Log *Lista_L, int tam_L, Funcionario *Lista_F, int tam_F) {
    int i = 0;
    double diff = 0;

    for(i=0; i<tam_F; i++){
        int a = 0;
        time_t entrada;
        double medf = 0;

        int j=0;
        for(j=0; j<tam_L; j++){
            if(Lista_L[j].Cod_Funcio==Lista_F[i].Codigo){
                if(Lista_L[j].Finalidade==3) {
                    entrada = convertStringToDate(&Lista_L[j].Horario);
                }
                if(Lista_L[j].Finalidade==4 && entrada != NULL) {
                    time_t saida = convertStringToDate(&Lista_L[j].Horario);
                    medf = medf + difftime(saida, entrada);
                    a = a + 1;
                }
            }
        }
        if(medf > 0) {
            diff = diff + medf/a;
        }
    }

    if(diff > 0) {
        diff = diff/tam_F;
    }
    int h, m, s;

    h = (diff/3600);

	m = (diff -(3600*h))/60;

	s = (diff -(3600*h)-(m*60));

	printf("%d:%d:%d\n",h,m,s);
}


/* Deleta todos os Logs de um Funcionario especifico e reorganiza a lista para não ficar com indices sem dados
    - Recebe: Lista de Logs, Tamanho da Lista de Logs, Codigo do Funcionario a ser Deletado
    - Retorna: Lista sem os Logs do funcionario especificado.
*/
void Log_DeleteLogs(Log** Lista, int* tam, int Cod_F){
    int i=0, pos=0;
    int len = *tam;

    for(i=0; i<len; i++){
        while((*Lista)[pos].Cod_Funcio==Cod_F && pos<len){
            pos++;
            *tam = *tam -1;
        }


        if(pos<len){
            (*Lista)[i].Cod_Funcio = (*Lista)[pos].Cod_Funcio;
            (*Lista)[i].Finalidade = (*Lista)[pos].Finalidade;
            strcpy((*Lista)[i].Horario, (*Lista)[pos].Horario);
        }
        else{
            (*Lista)[i].Cod_Funcio = 0;
            (*Lista)[i].Finalidade = 0;
            strcpy((*Lista)[i].Horario, "");
        }

        pos++;
    }
}


