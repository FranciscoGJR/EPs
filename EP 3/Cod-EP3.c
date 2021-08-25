/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   94       - Luciano Digiampietri                               **/
/**                                                                 **/
/**   Terceiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   Francisco Oliveira Gomes Junior                               **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>

#define pecaX 'X'
#define pecaY 'O'
#define espacoVazio ' '

/*
	Lista de Status calculado:
    0 - Jogo nao iniciado: o tabuleiro esta 'vazio', i.e., sem pecas X e O;
    1 - Jogo encerrado1: o primeiro jogador (que usa as pecas X) ganhou;
    2 - Jogo encerrado2: o segundo jogador (que usa as pecas O) ganhou;
    3 - Jogo encerrado3: empate - todas as casas do tabuleiro estao preenchidas com X e O, mas nenhum dos jogadores ganhou;
    4 - Jogo ja iniciado e em andamento: nenhuma das alternativas anteriores.
 */

char horizontalVestical(char tabuleiro[][3]){
    int i = 0;
    //      HORIZONTAL
    for(i = 0; i <= 2; i++){
        if((tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro [i][2]) && tabuleiro[i][0] != espacoVazio){
            return tabuleiro[i][0];
        }

    //      VESTICAL
        if((tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro [2][i]) && tabuleiro[0][i] != espacoVazio){
            return tabuleiro[0][i];
        }
    }
    return 'n';
}


int verificaStatus(char tabuleiro[][3]) {
	int linha, coluna, vazio = 0, cheio = 0;

	//      CONTAR VAZIO E CHEIO
    for(linha = 0; linha <=2; linha++){
        for(coluna = 0; coluna <= 2; coluna++){
            if(tabuleiro[linha][coluna] == espacoVazio)
                vazio += 1;
            if(tabuleiro[linha][coluna] != espacoVazio)
                cheio += 1;
        }
    }

    //      TABULEIRO VAZIO
    if(vazio == 9) return 0;

    //      GANHADOR HORIZONTAL OU VESTIVAL
    if(horizontalVestical(tabuleiro) == pecaX) return 1;
    if(horizontalVestical(tabuleiro) == pecaY) return 2;

    //      DIAGONAL PRINCIPAL
    if((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) && tabuleiro[0][0] != espacoVazio){
        if(tabuleiro[0][0] == pecaX)
            return 1;
        return 2;
    }

    //      DIAGONAL SECUNDÁRIA
    if((tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])&& tabuleiro[0][2] != espacoVazio){
        if(tabuleiro[0][2] == pecaX)
            return 1;
        return 2;
    }

    //      EMPATE
    if(cheio == 9)
        return 3;

    //      JOGO NÃO INICIADO
    return 4;
}

int main(){

	return 0;
}
