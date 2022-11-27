#include <stdio.h>
#include <stdlib.h>
#include "FuncionariosFuncoes.h"
#include "LogFuncoes.h"
#include "TelaPesquisaLogs.h"

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
void telaInicial(Funcionario** listaf, int* tamF, Log** listal, int* tamL){
    int escolha = 0, escolhaG;

    while(escolha==0){
        escolhaG = geral();

        switch(escolhaG){
            case 0:
                escolha = 1;
                break;
            case 1:
                escolha = telaF(listaf, tamF, listal, tamL);
                break;
            case 2:
                escolha = telaL(listal, tamL);
                break;
            case 3:
                escolha = TelaPesquisaLogs(listal, tamL, listaf, tamF);

                break;
        }
    }
}
