#include<stdio.h>
#define MAX 250

/*
O PROGRAMA TEM TR�S ENTRADAS:

A - FRASE PRINCIPAL
B - SEQU�NCIA DE CARACTERES CONTIDO EM A
C - SEQU�NCIA DE CARACTERES QUE ENTRA NO LUGAR DOS CARACTERES B

D - FRASE PRINCIPAL COM AS SUBSTITUI��ES APLICADAS

BASICAMENTE O QUE EU FA�O �: SALVAR CARACTER POR CARACTER DE A EM D DIRETAMENTE, MAS VOU CHECANDO SE VAI TER ALGUMA IGUALDADE COM
B, SE A IGUALDADE FOR COMPLETA ENT�O EU VOLTO NO INDICE DE D ONDE AS IGAULDADES COME�ARAM A SURGIR E VOU TROCANDO CARACTER POR
CARACTER POR C AT� COMPLETAR A TROCA E CONTINUO SEGUINDO NESSE MESMO PROCESSO AT� VARRER TODO O A.
*/

int main(){

    char A[MAX], B[MAX], C[MAX], D[MAX], aux;
    int i, j, b, tamanho_A = 0, tamanho_B = 0, tamanho_C = 0, tamanho_D = 0, qtd_substituicoes = 0, count_igualdade = 0, discrepancia, indice_D = 1;

    //LENDO A FRASE PRINCIPAL
    for(i = 0; i < MAX; i++){
        scanf("%c", &aux);
        if(aux != '\n'){
            A[i] = aux;
            tamanho_A++;
        }
        else
            break;
    }

    //LENDO A FRASE/PALAVRA CONTIDA DENTRO DA FRASE PRINCIPAL
    for(i=0; i<MAX; i++){
        scanf("%c",&aux);
        if(aux != '\n'){
            B[i] = aux;
            tamanho_B++;
        }
        else
            break;
    }

    //LENDO A FRASE/PALAVRA QUE IR� SUBSTITUIR A FRASE B DENTRO DA FRASE PRINCIPAL
    for(i=0; i < MAX; i++){
        scanf("%c",&aux);
        if(aux != '\n'){
            C[i] = aux;
            tamanho_C++;
        }
        else
            break;
    }

    i = 0;
    b = 0; //ITERADOR DA PALAVRA CONTIDA NA FRASE PRINCIPAL
    //DIFEREN�A ENTRE OS TAMANHOS DAS DUAS PALAVRAS
    discrepancia = tamanho_C - tamanho_B;
    //PERCORRE TODA A FRASE PRINCIPAL
    while(i <= tamanho_A){

        //BUSCA POR APARI��ES DE B E A
        if(A[i] == B[b]){
            count_igualdade++;
            b++;
        }
        else{
            //QUEBRA A CONTAGEM DE IGUALDADES DE B EM A, REEINICIA A CONTAGEM PARA OS PR�XIMOS CARACTERES
            b = 0;
            count_igualdade = 0;
            //SE ALGUMA SUBSTITUI��O J� FOI FEITA PODE SER QUE D N�O TENHA O MESMO TAMANHO DE A,
            //INDICE_D SE ENCARREGA DE FAZER A CORRE��O.
            //CASO NENHUMA SUBSTITUI��O TENHA SIDO FEITA BASTA MAPEAR DE INDICE A INDICE COMO FEITO NO ELSE
            if(qtd_substituicoes != 0)
                D[i + indice_D] = A[i];
            else
                D[i] = A[i];
            tamanho_D++;
        }

        //EQUIVALENTE A FALAR count_igualdade == tamanho_B
        if(count_igualdade == tamanho_C - discrepancia){
            qtd_substituicoes++;
            b = 0;
            //SUBSTITUINDO B POR C EM A (QUE EST� COPIADO EM D)
            //COME�AMOS DO INDICE ONDE AS IGUALDADES COME�ARAM A APARECER E VAMOS AT� ONDE FOR NECESS�RIO PARA
            //EXECUTAR A SUBSTITUI��O.
            for(j = i - count_igualdade + 1; j <= i + discrepancia; j++){
                D[j] = C[b];
                b++;
                tamanho_D++;
            }
            //ZERANDO AS IGUALDADES AP�S EXECUTAR A SUBSTITUI��O
            b = 0;
            count_igualdade = 0;
            //VARI�VEL QUE CORRIGE O INDICE DE D QUE RECEBER� O VALOR DE A.
            //TAM_B == TAM_C -> DISCREPANCIA 0 N�O A CORRE��O PARA FAZER
            //TAM_B > TAM_C -> DISCREPANCIA < 0 EX: B TEM DOIS CARACTERES A MENOS, ENT�O NA PRIMEIRA SUBSTITUI��O
            //AO INV�S DE MAPEAR PARA i TEREMOS QUE MAPEAR PARA i - 2 EM D, NA SEGUNDA i - 4 E ASSIM POR DIANTE
            //TAM_B < TAM_C -> DISCREPANCIA > 0 B TEM DOIS CARACTERES A MAIS, ENT�O NA PRIMEIRA SUBSTITUI��O
            //AO INV�S DE MAPEAR PARA i TEREMOS QUE MAPEAR PARA i + 2 EM D, NA SEGUNDA i + 4 E ASSIM POR DIANTE
            indice_D *= discrepancia;
        }
        i++;
    }

    //APRESENTANDO A FRASE PRINCIPAL COM AS DEVIDAS SUBSTITUI��ES
    for(i = 0; i < tamanho_D; i++)
        printf("%c", D[i]);

    printf("\n%d", tamanho_A);
    printf("\n%d", tamanho_D);
    printf("\n%d", qtd_substituicoes);


}
