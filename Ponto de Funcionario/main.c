#include <stdio.h>
#include <stdlib.h>
#include "JSON.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
    int n = 0;
    Funcionario* Lista = LerBD();




    printf(" %i - %s - %s \n", Lista[0].Codigo, Lista[0].Nome, Lista[0].Ocupacao);
    printf(" %i - %s - %s \n", Lista[1].Codigo, Lista[1].Nome, Lista[1].Ocupacao);
    //printf(" %i - %s - %s \n", Lista[2].Codigo, Lista[2].Nome, Lista[2].Ocupacao);

	//writeBD();
	return 0;
}
