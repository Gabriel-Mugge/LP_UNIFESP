#include<stdio.h>

int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
float divisao(float c, float d);

int main(){

    int escolha, a, b, resultado;
    float c, d, result_divisao;

    do{
        menu();
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Informe valores inteiros de a e b para serem somados\n");
                scanf("%d %d",&a ,&b);
                resultado = soma(a, b);
                printf("%d + %d = %d", a, b, resultado);
                break;
            case 2:
                printf("Informe valores inteiros de a e b para serem subtraídos\n");
                scanf("%d %d", &a ,&b);
                resultado = subtracao(a, b);
                printf("%d - %d = %d", a, b, resultado);
                break;
            case 3:
                printf("Informe valores inteiros de a e b para serem multiplicados\n");
                scanf("%d %d", &a ,&b);
                resultado = multiplicacao(a, b);
                printf("%d * %d = %d", a, b, resultado);
                break;
            case 4:
                printf("Informe valores de a e b para serem divididos\n");
                scanf("%f %f", &c ,&d);
                result_divisao = divisao(c, d);
                printf("%.2f / %.2f = %.2f", c, d, result_divisao);
                break;
        }

        printf("\n");
    }while(escolha!=0);
}

int soma(int a, int b){
    return a + b;
}

int subtracao(int a, int b){
    return a - b;
}

int multiplicacao(int a, int b){
    return a * b;
}

float divisao(float c, float d){
    return c / d;
}

void menu(){
    printf("[1] - soma\n");
    printf("[2] - subtração\n");
    printf("[3] - Multiplicação\n");
    printf("[4] - Divisão\n");
    printf("[0] - Sair\n");
}


