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

    printf("%i - %s - %s \n", f.Codigo, f.Nome, f.Ocupacao);



    //Lista = realloc(Lista, (n+1)*sizeof(struct func));
    Lista[6] = f;
    Lista[7] = f;
    Lista[8] = f;
    Lista[9] = f;

    n = sizeof(Lista[]);

    printf("\n\nTamanho: %i", n);

    printf("%i - %s - %s \n", Lista[6].Codigo, Lista[6].Nome, Lista[6].Ocupacao);

	writeBD(Lista);
	return 0;
}
