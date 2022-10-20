#include <stdio.h>
#include <stdlib.h>
#include "JSON.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
    int n = 0;
    Funcionario* Lista = LerBD(&n);


    printf("\n- Teste De Lista -\n");
    int i=0;
    for(i=0; i<n; i++){
        printf(" %i - %s - %s \n", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
    }

    Funcionario f = {7, "TesteADD", "TesteADDOC"};


    AddToList(&Lista[0], &n, 7, "TesteADD", "TesteADDOCUP");
    AddToList(&Lista[0], &n, 8, "TesteADD2", "TesteADDOCUP2");
    AddToList(&Lista[0], &n, 9, "TesteADD3", "TesteADDOCUP3");


    //Lista = realloc(Lista, (n+1)*sizeof(struct func));
    /*Lista[6] = f;
    Lista[7] = f;
    Lista[8] = f;
    Lista[9] = f;*/

    //n = sizeof(Lista[]);

    //printf("\n\nTamanho: %i", n);

    printf("\n- Teste De Lista Depois de ADD -\n");
    for(i=0; i<n; i++){
        printf(" %i - %s - %s \n", Lista[i].Codigo, Lista[i].Nome, Lista[i].Ocupacao);
    }

    printf("\n\nTamanho: %i", sizeof(Lista));
	//writeBD(Lista, n);
	return 0;
}
