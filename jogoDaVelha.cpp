#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela() {
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]) {
    int linha, coluna;

    //Populando a matriz
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linha][coluna] = '-';
        }
    }

}

void exibeTabuleiro(char tabuleiro[3][3]) {
    int linha, coluna;

    //Exibindo a matriz
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 3; coluna++) {
            cout << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }
}

void jogo() {

    ///Variáveis gerais
    char tabuleiro[3][3];                               //Tabuleiro do jogo
    int linha, coluna;                                  //Auxiliar matriz

    //Função que inicia/popula o tabuleiro
    iniciaTabuleiro(tabuleiro);

    //Função que exibe o tabuleiro
    exibeTabuleiro(tabuleiro);
}

void menuInicial() {
    int opcao = 0;

    //Laço de repetição que obriga o jogador digitar número correto
    while(opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem-vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER: ";

        //Opção do usuário
        cin >> opcao;

        switch(opcao) {
            case 1:
                //Inicia o jogo
                cout << "Jogo iniciado\n";
                jogo();
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
