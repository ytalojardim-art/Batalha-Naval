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



    if(posicao_diagonal_coluna+3 <=10 && posicao_diagonal_linha+3 <=10)
        for(int d=0; d<3; d++) {
            tabuleiro[posicao_diagonal_linha+d][posicao_diagonal_coluna+d]=navio_diagonal[d];
        }

    int posicao_diagonal_linha2=9 ; // variaveis para alocar o primeiro navio na posicao diagonal 2
    int posicao_diagonal_coluna2 =1;

    if(posicao_diagonal_coluna2+3 <=10 && posicao_diagonal_linha2-3 >=0)
        for(int d2=0; d2<3; d2++) {
            tabuleiro[posicao_diagonal_linha2-d2][posicao_diagonal_coluna2+d2]=navio_diagonal2[d2];
        }



    int posicao_vertical_linha= 0; // variaveis para alocar o primeiro navio na posicao vertical
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


    int cone[5][5]= {0};  // variaveis para de tamanho altura e largura do cone.
    int altura_cone =3 ;
    int coluna_cone =2 ;



    for(int L=0; L<altura_cone; L++) {                      //repetiçao para fazer com que as posições escolhidas fiquem com o valor 1 na hora de imprimir
        for(int C= coluna_cone-L; C<= coluna_cone+L; C++) {
            if(C >=0 && C<5) {
                cone[L][C] = 1;
            }
        }
    }

    int inicio_linha = 0;       //variavel para escolher posicao do cone
    int inicio_coluna = 7;

    for(int L=0; L<5; L++) {    //repetição para percorrer as linhas
        for(int C=0; C<5; C++) { // repetição para percorrer as colunas
            if(cone[L][C]!=0 && inicio_linha+L <10 && inicio_coluna+(C-coluna_cone)>=0 && inicio_coluna + (C - coluna_cone) < 10) { // decisao para que quando as 3 condições forem verdadeiras masrcar a posição com o numero 1
                tabuleiro[inicio_linha+L][inicio_coluna+(C-coluna_cone)]=cone[L][C];
            }
        }
    }

    int cruz [3][5]= {{0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    int inicio_linha_cruz = 3;
    int coluna_desejada =2;
    int inicio_coluna_cruz = coluna_desejada - 2; // a coluna nao estava ficando 2 casas de diferença da casa definida apos pesquisa o melhor soluçao foi subtrair essa duas casas para ficar sincronizado

    for(int Z=0 ; Z <3; Z++) {
        for(int U =0; U <5; U++) {
            if(cruz[Z][U]!=0 && inicio_linha_cruz +Z <10 && inicio_coluna_cruz +U <10) { //inicio_linha_cruz + Z coloca cada linha da cruz na linha correta do tabuleiroinicio_coluna_cruz + U  coloca cada coluna da cruz na coluna correta do tabuleiro
                tabuleiro[inicio_linha_cruz+Z][inicio_coluna_cruz+U]=cruz[Z][U];                                                                            //Condição != 0  só copia onde tem 1

            }
        }
    }

    int octaedro[5][5]=   // usei a mesma lógica da cruz porem usando matriz 5x5 e definindo as posiçao no formato octaedro
    {{0,0,1,0,0},
    {0,1,1,1,0},
    {1,1,1,1,1},
    {0,1,1,1,0},
    {0,0,1,0,0}
};
int inicio_linha_octaedro = 4 ;
int inicio_coluna_octaedro = 5;


for(int O=0 ; O <5; O++){
    for(int T =0; T <5; T++) {
        if(octaedro[O][T]!=0 && inicio_linha_octaedro +O <10 && inicio_coluna_octaedro +T <10) {
            tabuleiro[inicio_linha_octaedro+O][inicio_coluna_octaedro+T]=octaedro[O][T];

        }
    }
}
            printf("  ");  //printf para dar ajustar a coluna com o a matriz,
            for(int c=0; c<10; c++) {
                printf("%2d ",coluna[c]); // for para imprimir a coluna, o 2 na frente da % é para dar um espaço entre os numeros da coluna
            }
            printf("\n");



            for(int L=0; L<10; L++) {   // for para numerar a linha e ja imprimir o tabuleiro
                printf("%2d|",linha[L]);
                for(int c=0; c<10; c++) {
                    printf("%d  ",tabuleiro[L][c]); // comando para imprimir o tabuleiro com o numero da linha e as posiçoes dos navios e habilidades ja setadas no começo do código
                }
                printf("\n");
            }





            return 0;
        }
