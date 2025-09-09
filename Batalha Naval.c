#include <stdio.h>
#include <stdlib.h>

int main() {
    int linha[10]= {1,2,3,4,5,6,7,8,9,10};
    int coluna[10]= {1,2,3,4,5,6,7,8,9,10};
    int tabuleiro [10][10]= {0};
    int navio_vertical [3]= {3,3,3};
    int navio_horizontal [3]= {3,3,3};
    int navio_diagonal [3]= {3,3,3};
    int navio_diagonal2 [3]= {3,3,3};

    int posicao_diagonal_linha= 0; // variaveis para alocar o primeiro navio na posicao diagonal
    int posicao_diagonal_coluna =0;



    if(posicao_diagonal_coluna+3 <=10 && posicao_diagonal_linha+3 <=10); // codigo de decisao para diagonal de cima para baixo canto esquerdo
        for(int d=0;d<3;d++){
            tabuleiro[posicao_diagonal_linha+d][posicao_diagonal_coluna+d]=navio_diagonal[d];
        }

    int posicao_diagonal_linha2=9 ; // variaveis para alocar o primeiro navio na posicao diagonal 2 invertida na posiçao de baixo para cima
    int posicao_diagonal_coluna2 =0;

    if(posicao_diagonal_coluna2+3 <=10 && posicao_diagonal_linha2-3 <=10); 
    for(int d2=0;d2<3;d2++){
            tabuleiro[posicao_diagonal_linha2-d2][posicao_diagonal_coluna2+d2]=navio_diagonal2[d2]; // codigo para decrementar a linha e fazer a diagonal invertida
        }



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
