#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela() {
    system("CLS");
}

void menuInicial() {
    int opcao = 0;

    //La�o de repeti��o que obriga o jogador digitar n�mero correto
    while(opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem-vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER: ";

        //Op��o do usu�rio
        cin >> opcao;

        switch(opcao) {
            case 1:
                //Inicia o jogo
                cout << "Jogo iniciado";
                break;
            case 2:
                cout << "Informacoes do jogo";
                break;
            case 3:
                cout << "Ate mais!";
                break;

        }
    }
}

int main() {
    menuInicial();

    return 0;
}
