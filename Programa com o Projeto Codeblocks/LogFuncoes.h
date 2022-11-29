#include <stdio.h>
#include <stdlib.h>

int escolhageralL(){
    int x;
    puts("Oque voce deseja fazer?\n");
    puts("Digite (1) para adicionar log de funcionarios");
    puts("Digite (0) para sair");
    scanf("%i", &x);
    return x;
}

int addLog(int escolha, Log** listal, int* taml){
    puts("Digite o codigo do funcionario: ");
    int cod;
    scanf("%i", &cod);

    puts("Digite a finalidade: ");
    puts(" -Digite (1) para Entrada do Trabalho");
    puts(" -Digite (2) para Saida do Trabalho");
    puts(" -Digite (3) para Entrada do Almoço");
    puts(" -Digite (4) para Saida Para Almoço\n");
    int fin;
    scanf("%i", &fin);

    time_t t;
    time(&t);
    struct tm  tm = *localtime(&t);
    char hor[21];
    const size_t N = 21;
    strftime(hor, N, "%Y-%m-%d %H:%M:%S", &tm);


    Log_AddToList(listal, taml, cod, hor, fin);
    return 0;
}

int telaL(Log** listal, int* taml){
    int escolha = 0, escolhaG;

    while(escolha==0){
        escolhaG = escolhageralL(escolhaG);

        switch(escolhaG){
            case 0:
                return 0;
            case 1:
                escolha = addLog(escolha, listal, taml);
                break;
        }
    }
}
