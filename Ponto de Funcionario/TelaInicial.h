#include <stdio.h>
#include <stdlib.h>
#include "FuncionariosFuncoes.h"

//Função de escolhas gerais
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

//Função principal da tela inicial
void telaInicial(){
    int escolha = 0, escolhaG;

    while(escolha==0){
        escolhaG = aaa();

        switch(escolhaG){
            case 0:
                break;
            case 1:
                aloha();
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
