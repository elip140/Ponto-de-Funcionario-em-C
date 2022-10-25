#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop

*/


void Teste_Funcio_Visualizar(Funcionario* Funcio_Lista, int* n) {
    printf("\n- Teste De Lista Funcionarios -\n");
    int i=0;
    for(i=0; i<*n; i++){
        printf(" %i - %s - %s \n", Funcio_Lista[i].Codigo, Funcio_Lista[i].Nome, Funcio_Lista[i].Ocupacao);
    }
}

void Teste_Funcio_Add(Funcionario **Lista, int* n){

    Funcio_AddToList(Lista, n, 7, "TesteADD", "TesteADDOCUP");
    Funcio_AddToList(Lista, n, 8, "TesteADD2", "TesteADDOCUP2");
    Funcio_AddToList(Lista, n, 9, "TesteADD3", "TesteADDOCUP3");

    printf("\n- Teste De Lista Funcionarios Depois de ADD -\n");

    int i=0;
    for(i=0; i<*n; i++){
        printf(" %i - %s - %s \n", (*Lista+i)->Codigo, (*Lista+i)->Nome, (*Lista+i)->Ocupacao);
    }

}

void Teste_Funcio_Remove(Funcionario* Lista, int* n){

    Funcio_RemoveFromList(&Lista[0], 3, n);
    Funcio_RemoveFromList(&Lista[0], 3, n);
    Funcio_RemoveFromList(&Lista[0], 6, n);

    printf("\n- Teste De Lista Funcionarios Depois de Remove -\n");
    int i=0;
    for(i=0; i<*n; i++){
        printf(" %i - %s - %s \n", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
    }
}

void Teste_Funcio_Edit(Funcionario* Lista, int* n){
    Funcio_EditFromList(Lista, *n, 4, "TesteEDIT", "TesteEDIT OCUP 1");
    Funcio_EditFromList(Lista, *n, 5, "TesteEDIT 2", "TesteEDIT OCUP 2");
    Funcio_EditFromList(Lista, *n, 6, "TesteEDIT 3", "TesteEDIT OCUP 3");


    printf("\n- Teste De Lista Depois de EDIT -\n");
    int i=0;
    for(i=0; i<*n; i++){
        printf(" %i - %s - %s \n", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
    }
}

void Teste_Log_Visualizar(Log **Lista, int* n){
    printf("\n- Teste De Lista Logs -\n");
    int i=0;
    for(i=0; i<*n; i++){
        printf(" %i - %s - %i\n", (*Lista)[i].Cod_Funcio, (*Lista)[i].Horario, (*Lista)[i].Finalidade);
    }
}

void Teste_Log_Add(Log* Lista, int* n, Funcionario* Funcio_Lista, int* tam_F){
    Log_AddToList(&Lista[0], &Funcio_Lista[0], n, tam_F, 1, "2015-11-04 15:34:23", 1);
    Log_AddToList(&Lista[0], &Funcio_Lista[0], n, tam_F, 2, "2013-12-10 14:20:26", 2);
    //Log_AddToList(&Lista, &Funcio_Lista[0], n, tam_F, 3, "2016-09-14 23:39:23", 4);
    //Log_AddToList(&Lista, &Funcio_Lista[0], n, tam_F, 4, "2015-12-04 08:02:23", 3);
    //Log_AddToList(&Lista, &Funcio_Lista[0], n, tam_F, 5, "2019-01-20 14:34:01", 1);

    printf("\n- Teste De Lista Logs Depois de ADD -\n");
    int i=0;
    for(i=0; i<*n; i++){
        printf("\n%i - %s - %i", Lista[i].Cod_Funcio, Lista[i].Horario, Lista[i].Finalidade);
    }
}


    //Log_writeBD(Lista, m);

