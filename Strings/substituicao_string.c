#include<stdio.h>
#define MAX 250

/*
O PROGRAMA TEM TRÊS ENTRADAS:

A - FRASE PRINCIPAL
B - SEQUÊNCIA DE CARACTERES CONTIDO EM A
C - SEQUÊNCIA DE CARACTERES QUE ENTRA NO LUGAR DOS CARACTERES B

D - FRASE PRINCIPAL COM AS SUBSTITUIÇÕES APLICADAS

BASICAMENTE O QUE EU FAÇO É: SALVAR CARACTER POR CARACTER DE A EM D DIRETAMENTE, MAS VOU CHECANDO SE VAI TER ALGUMA IGUALDADE COM
B, SE A IGUALDADE FOR COMPLETA ENTÃO EU VOLTO NO INDICE DE D ONDE AS IGAULDADES COMEÇARAM A SURGIR E VOU TROCANDO CARACTER POR
CARACTER POR C ATÉ COMPLETAR A TROCA E CONTINUO SEGUINDO NESSE MESMO PROCESSO ATÉ VARRER TODO O A.
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

    //LENDO A FRASE/PALAVRA QUE IRÁ SUBSTITUIR A FRASE B DENTRO DA FRASE PRINCIPAL
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
    //DIFERENÇA ENTRE OS TAMANHOS DAS DUAS PALAVRAS
    discrepancia = tamanho_C - tamanho_B;
    //PERCORRE TODA A FRASE PRINCIPAL
    while(i <= tamanho_A){

        //BUSCA POR APARIÇÕES DE B E A
        if(A[i] == B[b]){
            count_igualdade++;
            b++;
        }
        else{
            //QUEBRA A CONTAGEM DE IGUALDADES DE B EM A, REEINICIA A CONTAGEM PARA OS PRÓXIMOS CARACTERES
            b = 0;
            count_igualdade = 0;
            //SE ALGUMA SUBSTITUIÇÃO JÁ FOI FEITA PODE SER QUE D NÃO TENHA O MESMO TAMANHO DE A,
            //INDICE_D SE ENCARREGA DE FAZER A CORREÇÃO.
            //CASO NENHUMA SUBSTITUIÇÃO TENHA SIDO FEITA BASTA MAPEAR DE INDICE A INDICE COMO FEITO NO ELSE
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
            //SUBSTITUINDO B POR C EM A (QUE ESTÁ COPIADO EM D)
            //COMEÇAMOS DO INDICE ONDE AS IGUALDADES COMEÇARAM A APARECER E VAMOS ATÉ ONDE FOR NECESSÁRIO PARA
            //EXECUTAR A SUBSTITUIÇÃO.
            for(j = i - count_igualdade + 1; j <= i + discrepancia; j++){
                D[j] = C[b];
                b++;
                tamanho_D++;
            }
            //ZERANDO AS IGUALDADES APÓS EXECUTAR A SUBSTITUIÇÃO
            b = 0;
            count_igualdade = 0;
            //VARIÁVEL QUE CORRIGE O INDICE DE D QUE RECEBERÁ O VALOR DE A.
            //TAM_B == TAM_C -> DISCREPANCIA 0 NÃO A CORREÇÃO PARA FAZER
            //TAM_B > TAM_C -> DISCREPANCIA < 0 EX: B TEM DOIS CARACTERES A MENOS, ENTÃO NA PRIMEIRA SUBSTITUIÇÃO
            //AO INVÉS DE MAPEAR PARA i TEREMOS QUE MAPEAR PARA i - 2 EM D, NA SEGUNDA i - 4 E ASSIM POR DIANTE
            //TAM_B < TAM_C -> DISCREPANCIA > 0 B TEM DOIS CARACTERES A MAIS, ENTÃO NA PRIMEIRA SUBSTITUIÇÃO
            //AO INVÉS DE MAPEAR PARA i TEREMOS QUE MAPEAR PARA i + 2 EM D, NA SEGUNDA i + 4 E ASSIM POR DIANTE
            indice_D *= discrepancia;
        }
        i++;
    }

    //APRESENTANDO A FRASE PRINCIPAL COM AS DEVIDAS SUBSTITUIÇÕES
    for(i = 0; i < tamanho_D; i++)
        printf("%c", D[i]);

    printf("\n%d", tamanho_A);
    printf("\n%d", tamanho_D);
    printf("\n%d", qtd_substituicoes);


}
