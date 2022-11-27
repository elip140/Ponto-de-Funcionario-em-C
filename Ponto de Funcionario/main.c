#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funcionario.h"
#include "Log.h"
#include "TelaInicial.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop

*/


int main(int argc, char *argv[]) {
    int tamF = Funcio_LerTam();
    Funcionario* Lista_Funcio = malloc(tamF * sizeof(Funcionario));
    Funcio_LerBD(&Lista_Funcio);

    int tamL = Log_LerTam();
    Log* Lista_Log = malloc(tamL * sizeof(Log));
    Log_LerBD(&Lista_Log);

    telaInicial(&Lista_Funcio, &tamF, &Lista_Log, &tamL);

    Funcio_writeBD(Lista_Funcio, tamF);
    Log_writeBD(Lista_Log, tamL);

    int i=0;
    for(i=0; i<tamF; i++){
        free(Lista_Funcio[i].Nome);
        free(Lista_Funcio[i].Ocupacao);
    }

	return 0;
}
