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
    printf("\n\nTESTE");





    Teste_Funcio_Visualizar(&Lista_Funcio, &tam);
    Teste_Funcio_Add(&Lista_Funcio, &tam);
    Teste_Funcio_Remove(&Lista_Funcio, &tam);
    Teste_Funcio_Edit(&Lista_Funcio, &tam);


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

/*

    int m=0;
    Log* Lista = Log_LerBD(&m);

    int i;
    printf("\n- Teste De Lista Logs -\n");
    for(i=0; i<m; i++){
        printf("%i - %s - %s - %i\n", Lista[i].Cod_Funcio, Lista[i].Nome_Funcio, Lista[i].Horario, Lista[i].Finalidade);
    }


    //Log_AddToList(&Lista[0], &Funcio_Lista[0], &m, &n, 1, "2015-11-04 15:34:23", 1);
    //Log_AddToList(&Lista[0], &Funcio_Lista[0], &m, &n, 2, "2013-12-10 14:20:26", 2);
    //Log_AddToList(&Lista, &Funcio_Lista[0], &m, &n, 3, "2016-09-14 23:39:23", 4);
    //Log_AddToList(&Lista, &Funcio_Lista[0], &m, &n, 4, "2015-12-04 08:02:23", 3);
    //Log_AddToList(&Lista, &Funcio_Lista[0], &m, &n, 5, "2019-01-20 14:34:01", 1);

    printf("\n- Teste De Lista Logs Depois de ADD -\n");
    for(i=0; i<m; i++){
        printf("\n%i - %s - %s - %i", Lista[i].Cod_Funcio, Lista[i].Nome_Funcio, Lista[i].Horario, Lista[i].Finalidade);
    }

    Log_writeBD(Lista, m);*/
