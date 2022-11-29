#include <stdio.h>
#include <stdlib.h>

//Função de escolhas gerais
int geralPesquisa(int escolhaG){
    int x;
    puts("Oque voce deseja fazer?\n");
    puts("Digite (1) para ver o Log de todos os Funcionarios");
    puts("Digite (2) para ver o Log de um funcionario em especifico");
    puts("Digite (3) para ver o Tempo medio de almoco dos funcionarios");
    puts("Digite (0) para sair");
    scanf("%i", &x);
    return x;
}

//Ver Logs de todos os Funcionarios
// - Recebe: Lista de Logs, Tamanho da Lista de Logs, Lista de Funcionarios, Tamanho da Lista de Funcionarios
int VerTodos(int escolha, Log** listal, int* taml,Funcionario** listaf, int* tamF){
    Log_ShowLogs(*listal, *taml, *listaf, *tamF);

    printf("\nDigite (0) para voltar\n");
    int x;
    scanf("%i",&x);
    return x;
}

//Ver logs de um Funcionario em especifico
// - Recebe: Lista de Logs, Tamanho da Lista de Logs, Lista de Funcionarios, Tamanho da Lista de Funcionarios, Codigo do Funcionario
int VerFuncio(int escolha, Log** listal, int* taml,Funcionario** listaf, int* tamF){
    puts("Digite o codigo do funcionario: ");
    int cod;
    scanf("%i", &cod);
    Log_ShowLogFuncio(*listal, *taml, *listaf, *tamF, cod);

    printf("\nDigite (0) para voltar\n");
    int x;
    scanf("%i",&x);
    return x;
}

int VerDiff(int escolha, Log** listal, int* taml,Funcionario** listaf, int* tamF){
    Log_ShowTempoMedio(*listal, *taml, *listaf, *tamF);


    printf("\nDigite (0) para voltar\n");
    int x;
    scanf("%i",&x);
    return x;
}

//Função principal da tela inicial
int TelaPesquisaLogs(Log** listal, int* taml,Funcionario** listaf, int* tamF){
    int escolha = 0, escolhaG;

    while(escolha==0){
        escolhaG = geralPesquisa(escolhaG);
        switch(escolhaG){
            case 0:
                return 0;
            case 1:
                escolha = VerTodos(escolha,listal, taml, listaf, tamF);
                break;
            case 2:
                escolha = VerFuncio(escolha,listal, taml, listaf, tamF);
                break;
            case 3:
                escolha = VerDiff(escolha,listal, taml, listaf, tamF);
                break;
        }
    }
}
