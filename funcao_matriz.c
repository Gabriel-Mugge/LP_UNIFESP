#include<stdio.h>
#define MAX 100

void leituraMatriz(int A[MAX][MAX], int n);
void imprimeMatriz(int A[MAX][MAX], int n);
void quadradoElementosMatriz(int A[MAX][MAX], int B[MAX][MAX], int n);
void multiplicaMatriz(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n);
int tracoMatriz(int C[MAX][MAX], int n);


int main(){

    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], n, traco;

    scanf("%d", &n);

    leituraMatriz(M1, n);
    printf("\n");
    quadradoElementosMatriz(M1, M2, n);
    imprimeMatriz(M2, n);
    multiplicaMatriz(M1, M2, M3, n);
    printf("\n");
    imprimeMatriz(M3, n);
    printf("\n");
    traco = tracoMatriz(M3, n);
    printf("Traco: %d", traco);


}

//RECEBE COMO INPUT VALORES PARA MONTAR UMA MATRIZ QUADRADA
void leituraMatriz(int A[MAX][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j=0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
}

//ELEVA AO QUADRADO TODOS OS ELEMENTOS DA MATRIZ E SALVA O RESULTADO EM UMA NOVA MATRIZ
void quadradoElementosMatriz(int A[MAX][MAX], int B[MAX][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            B[i][j] = A[i][j]*A[i][j];
        }
    }
}

//IMPRIME A MATRIZ NA TELA
void imprimeMatriz(int A[MAX][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

//RETORNA UMA MATRIZ COMO SENDO A MULTIPICAÇÃO DE DUAS OUTRAS
void multiplicaMatriz(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n){
    int i, j, k, prod;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            prod = 0;
            for(k = 0; k < n; k++)
                prod += A[i][k]*B[k][j];
            C[i][j] = prod;
        }

    }
}

//RETORNA A SOMA DOS ELEMENTOS DA DIAGONAL DA MATRIZ
int tracoMatriz(int C[MAX][MAX], int n){
    int i, soma = 0;

    for(i=0; i<n; i++)
        soma += C[i][i];

    return soma;
}





