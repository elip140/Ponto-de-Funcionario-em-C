#include <stdio.h>
#include <stdlib.h>
#include "Funcionario.h"
#include "Log.h"
#include "TelaInicial.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop

*/


int main(int argc, char *argv[]) {
    int tam = Funcio_LerTam();
    Funcionario* Lista_Funcio = malloc(tam * sizeof(Funcionario));
    Funcio_LerBD(&Lista_Funcio);

    int n = Log_LerTam();
    Log* Lista = malloc(n * sizeof(Log));
    Log_LerBD(&Lista);

    telaInicial(&Lista_Funcio, &tam);

    Funcio_writeBD(Lista_Funcio, tam);
    Log_writeBD(Lista, n);

    int i=0;
    for(i=0; i<tam; i++){
        free(Lista_Funcio[i].Nome);
        free(Lista_Funcio[i].Ocupacao);
    }


	return 0;
}
