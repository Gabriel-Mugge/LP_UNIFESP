#include<stdio.h>

int main(){

    int matriz1[5][5], matriz2[5][5], matriz3[5][5];

    //PREENCEHENDO AS DUAS MATRIZES INICIAIS COM NÚMEROS ALEATÓRIOS.
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriz1[i][j] = rand()%3;
            matriz2[i][j] = rand()%3;
        }
    }

    //REALIZANDO A MULTIPLICAÇÃO ENTRE AS MATRIZES
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriz3[i][j] = matriz1[i][j]*matriz2[i][j] + matriz1[i][j+1]*matriz2[i+1][j] + matriz1[i][j+2]*matriz2[i+2][j] + matriz1[i][j+3]*matriz2[i+3][j] + matriz1[i][j+4]*matriz2[i+4][j];
        }
    }

    //APRESENTANDO AS TRÊS MATRIZES
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d  ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d  ", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d  ", matriz3[i][j]);
        }
        printf("\n");
    }
}
