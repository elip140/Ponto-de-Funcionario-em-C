#include <stdio.h>
#include <stdlib.h>
#include "FuncionariosFuncoes.h"
#include "LogFuncoes.h"

//Função de escolhas gerais
int geral(){
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
void telaInicial(Funcionario** listaf, int* tamf, Log** listal, int* taml){
    int escolha = 0, escolhaG;

    while(escolha==0){
        escolhaG = geral();

        switch(escolhaG){
            case 0:
                escolha = 1;
                break;
            case 1:
                escolha = telaF(listaf, tamf);
                break;
            case 2:
                escolha = telaL(listal, taml);
                break;
            case 3:

                break;
        }
    }
}
