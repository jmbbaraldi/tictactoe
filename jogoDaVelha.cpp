#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//Definição da função
void menuInicial();

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
    cout << "\n";
    //Exibindo a matriz
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 3; coluna++) {
            cout << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }
}

//1 = X venceu; 2 = O venceu; 0 = Nada aconteceu
int confereTabuleiro(char tabuleiro[3][3]) {
    int linha, coluna;

    //Confere se o jogo acabou em linhas
        for(linha = 0; linha < 3; linha++) {
            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
                return 1;
            }
            else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
                return 2;
            }
        }

        //Confere as colunas
        for(coluna = 0; coluna < 3; coluna++) {
            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
                return 1;
            }
            else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
                return 2;
            }
        }

        //Diagonal principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
            if(tabuleiro[0][0] == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }

        //Diagonal principal
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
            if(tabuleiro[0][2] == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }

        return 0;
}

void jogo() {

    ///Variáveis gerais
    string nomeJogadorUm, nomeJogadorDois, jogadorAtual;    //Nomes dos jogadores
    char tabuleiro[3][3];                                   //Tabuleiro do jogo
    int linha, coluna;                                      //Auxiliar matriz
    int linhaJogada, colunaJogada;                          //Jogador posiciona sua jogada
    int estadoDeJogo = 1;                                   //0=sem jogo; 1=com jogo
    int turnoDoJogador = 1;                                 //1 = X; 0 = O;
    int rodada = 0;                                         //Quantas vezes os jogadores jogaram no total
    int opcao;                                              //Opção de reinicio

    //Função que inicia/popula o tabuleiro
    iniciaTabuleiro(tabuleiro);

    cout << "Digite o nome do jogador 1: ";
    cin >> nomeJogadorUm;
    cout << "Digite o nome do jogador 2: ";
    cin >> nomeJogadorDois;

    while(rodada < 9 && estadoDeJogo == 1) {

        limpaTela();

        //Função que exibe o tabuleiro
        exibeTabuleiro(tabuleiro);

        cout << "\nRodada: " << rodada << "\n";

        //Atualiza o nome do jogador atual
         if(turnoDoJogador == 1) {
            jogadorAtual = nomeJogadorUm;
         }
         else {
            jogadorAtual = nomeJogadorDois;
         }

        cout << jogadorAtual << ", digite uma linha: ";
        cin >> linhaJogada;
        cout << jogadorAtual << ", digite uma coluna: ";
        cin >> colunaJogada;

        if(turnoDoJogador == 1) {                       //Jogador do X
            tabuleiro[linhaJogada][colunaJogada] = 'X';

            turnoDoJogador = 2;
        }
        else {                                          //Jogador do O
            tabuleiro[linhaJogada][colunaJogada] = 'O';

            turnoDoJogador = 1;
        }

        //Confere posicionamento de vitória
        if(confereTabuleiro(tabuleiro) == 1) {
            cout << "\nO jogador X venceu!";
            estadoDeJogo = 0;
        }
        else if(confereTabuleiro(tabuleiro) == 2) {
            cout << "\nO jogador O venceu!";
            estadoDeJogo = 0;
        }

        //Incrementa a rodada
        rodada++;
    }

    exibeTabuleiro(tabuleiro);
    cout << "\nFim de jogo!";
    cout << "\nDeseja reiniciar o jogo?";
    cout << "\n1 - Sim";
    cout << "\n2 - Nao\n";
    if(opcao == 1) {
        menuInicial();
    }
    else {
        cout << "Ate mais!";
    }
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
