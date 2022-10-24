#include <stdio.h>
#include <stdlib.h>


int escolhageral(int a){
    int x;
    printf("Oque voce deseja fazer?\nDigite (1) para adicionar Funcionarios\nDigite (2) para mudar as informacoes dos Funcionarios\n");
    printf("Digite (3) para excluir funcionarios\nDigite (4) para ver todos os funcionarios na lista\n\ndigite (0): para voltar ao menu principal\n");
    scanf("%i", &x);
    return x;
}

//Função de adicionar funcionários
int adicionar(int escolha){
    int x,y;
    printf("Voce deseja adicionar um funcionario?\nDigite (1) para SIM\nDigite (2): para NAO\n");
    scanf("%i", &x);
    if(x==1){
        return x;
    }
    else{
        return 0;
    }
}

//Função para modificar os dados do usuario
int modificar(int escolha){
    int x;
    printf("Qual informacao voce deseja modificar?\nDigite (1) para o nome\nDigite (2) para a ocupacao\nDigite (0) para cancelar\n");
    scanf("%i", &x);
    if(x!=0 && x<=2){
        return x;
    }
    return 0;
}

//Função para excluir os dados do funcionario
int excluir(int escolha){
    int x;
    printf("Voce deseja excluir este funcionario da lista?\nDigite (1) para SIM\nDigite (2) para NAO\n");
    scanf("%i",&x);
    if(x==1){
        return x;
    }
    else{
        return 0;
    }
}

//Função para ver todos os funcionarios
int vertodos(int escolha){
    int x;
    printf("Digite (0) para voltar\n");
    scanf("%i",&x);
    return x;
}


int aloha(){
    int escolha, escolhaG;

    while(escolha==0){
        escolhaG = escolhageral(escolhaG);

        switch(escolhaG){
            case 0:
                break;
            case 1:
                escolha = adicionar(escolha);
                break;
            case 2:
                escolha = modificar(escolha);
                break;
            case 3:
                escolha = excluir(escolha);
                break;
            case 4:
                escolha = vertodos(escolha);
                break;
        }
    }
    return 1;
}




