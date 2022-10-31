#include <stdio.h>
#include <stdlib.h>
#include "Funcionario.h"
#include "Log.h"
#include "Teste.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop

*/


int main(int argc, char *argv[]) {
    int tam = Funcio_LerTam();
    Funcionario* Lista_Funcio = malloc(tam * sizeof(Funcionario));
    Funcio_LerBD(&Lista_Funcio);

    int n = Log_LerTam();
    Log* Lista = malloc(n * sizeof(Log));
    Log_LerBD(&Lista);

    Teste_Log_Visualizar(&Lista, &n);
    Teste_Log_Add(&Lista, &n);


    Teste_Funcio_Visualizar(&Lista_Funcio, &tam);
    Teste_Funcio_Add(&Lista_Funcio, &tam);
    Teste_Funcio_Remove(&Lista_Funcio, &tam);
    Teste_Funcio_Edit(&Lista_Funcio, &tam);

    Log_ShowLogs(Lista, n, Lista_Funcio, tam);
    Log_ShowLogFuncio(Lista, n, Lista_Funcio, tam, 1);

    Funcio_ShowLista(Lista_Funcio, tam);


    //Funcio_writeBD(Lista_Funcio, n);


    int i=0;
    for(i=0; i<tam; i++){
        free(Lista_Funcio[i].Nome);
        free(Lista_Funcio[i].Ocupacao);
    }

    //free(Lista_Funcio);
    //free(Lista);


	return 0;
}
