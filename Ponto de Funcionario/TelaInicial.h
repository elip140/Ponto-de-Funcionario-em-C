#include <stdio.h>
#include <stdlib.h>
#include "FuncionariosFuncoes.h"


int aaa(){
    int x;
    puts("Oque voce deseja fazer?\n");
    puts("Digite (1) para ir no cadastro de funcionarios");
    puts("Digite (2) para ir nas opcoes de logs");
    puts("Digite (3) para ir na pesquisa de logs\n");
    puts("Digite (0) para sair");
    scanf("%i", &x);
    return x;
}

void telaInicial(){
    int escolha, escolhaG;

    while(escolha==0){
        escolhaG = aaa();

        switch(escolhaG){
            case 0:
                break;
            case 1:
                escolha = aloha();
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
        }
    }
}


