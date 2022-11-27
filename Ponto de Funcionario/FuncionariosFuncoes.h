#include <stdio.h>
#include <stdlib.h>

//Função de escolhas gerais sobre funcionarios
int escolhageralF(int escolhaG){
    int x;
    printf("Oque voce deseja fazer?\nDigite (1) para adicionar Funcionarios\nDigite (2) para mudar as informacoes dos Funcionarios\n");
    printf("Digite (3) para excluir funcionarios\nDigite (4) para ver todos os funcionarios na lista\n\ndigite (0): para voltar ao menu principal\n");
    scanf("%i", &x);
    return x;
}

//Função de adicionar funcionários
int adicionar(int escolha, Funcionario** listaf, int* tam){
    puts("Digite o codigo do novo funcionario: ");
    int cod;
    scanf("%i", &cod);

    puts("Digite o nome do novo funcionario: ");
    char nome[100];
    scanf("%s", &nome);

    puts("Digite a ocupacao do novo funcionario: ");
    char ocup[100];
    scanf("%s", &ocup);

    Funcio_AddToList(listaf, tam, cod, nome, ocup);
    return 0;
}

//Função para modificar os dados do usuario
int modificar(int escolha, Funcionario** listaf, int* tam){
    puts("Digite o codigo do novo funcionario: ");
    int cod;
    scanf("%i", &cod);

    puts("Digite o novo nome do novo funcionario: ");
    char nome[100];
    scanf("%s", &nome);

    puts("Digite a nova ocupacao do novo funcionario: ");
    char ocup[100];
    scanf("%s", &ocup);

    int x;
    printf("Voce deseja confirmar esta operacao?\nDigite (1) para SIM\nDigite (2) para NAO\n");
    scanf("%i",&x);

    if(x==1){
        Funcio_EditFromList(listaf, tam, cod, nome, ocup);
    }

    return 0;
}

//Função para excluir os dados do funcionario
int excluir(int escolha, Funcionario** listaf, int* tam){
    puts("Digite o codigo do novo funcionario: ");
    int cod;
    scanf("%i", &cod);

    int x;
    printf("Voce deseja excluir este funcionario da lista?\nDigite (1) para SIM\nDigite (2) para NAO\n");
    scanf("%i",&x);

    if(x==1){
        Funcio_RemoveFromList(listaf, cod, tam);
    }
    return 0;
}

//Função para ver todos os funcionarios
int vertodos(int escolha, Funcionario** listaf, int* tam){
    int x;
    Funcio_ShowLista(listaf, *tam);
    printf("\nDigite (0) para voltar\n");
    scanf("%i",&x);
    return x;
}

//Função principal da tela de funcionarios
int telaF(Funcionario** listaf, int* tam){
    int escolha = 0, escolhaG;

    while(escolha==0){
        escolhaG = escolhageralF(escolhaG);

        switch(escolhaG){
            case 0:
                return 0;
            case 1:
                escolha = adicionar(escolha, listaf, tam);
                break;
            case 2:
                escolha = modificar(escolha, listaf, tam);
                break;
            case 3:
                escolha = excluir(escolha, listaf, tam);
                break;
            case 4:
                escolha = vertodos(escolha, listaf, tam);
                break;
        }
    }
}




