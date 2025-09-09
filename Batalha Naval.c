#include <stdio.h>


int main() {
    int linha[10]= {1,2,3,4,5,6,7,8,9,10}; // vetor para numerar as linhas do tabuleiro
    int coluna[10]= {1,2,3,4,5,6,7,8,9,10};// vetor para numerar as colunas do tabulerio
    int tabuleiro [10][10]= {0}; // matriz do tabuleiro
    int navio_vertical [3]= {3,3,3};//vetor para declarar o tamanho do navio vertical
    int navio_horizontal [3]= {3,3,3};//vetor para declarar o tamanho do navio horizontal



    // primeiro navio
    int posicao_vertical_linha= 1; // variaveis para alocar o primeiro navio na posicao vertical
    int posicao_vertical_coluna =4;

    if(posicao_vertical_linha+3 <=10) {         // if para que nao passe o limite do tabuleiro e + 3 é o tamanho de casas que o navio vai ocupar
        for(int P=0; P < 3; P++) { //repeticao para identificar a posicao do navio ja declarada na variavel acima
            tabuleiro[posicao_vertical_linha+P][posicao_vertical_coluna]=navio_vertical[P]; // +P serve para avançar cada parte do navio ao longo das casas do tabuleiro
        }
    }
    int posicao_horizontal_linha= 9; // variaveis para alocar o primeiro navio na posicao horizontal
    int posicao_horizontal_coluna =4;

    if(posicao_horizontal_coluna + 3 <=10) {
        for(int P=0; P < 3; P++) {
            tabuleiro[posicao_horizontal_linha][posicao_horizontal_coluna+P]=navio_horizontal[P];
        }
    }

    printf("  ");  //printf para dar ajustar a coluna com o a matriz,
    for(int c=0; c<10; c++) {
        printf("%2d ",coluna[c]); // for para imprimir a coluna, o 2 na frente da % é para dar um espaço entre os numeros da coluna
    }
    printf("\n");



    for(int L=0; L<10; L++) {   // for para numerar a linha e ja imprimir o tabuleiro
        printf("%2d|",linha[L]);
        for(int coluna=0; coluna<10; coluna++) {
            printf("%d  ",tabuleiro[L][coluna]); // comando para imprimir o tabuleiro com o numero da linha e as posiçoes dos navios ja setadas no começo do codigo
        }
        printf("\n");
    }

    return 0;
}
