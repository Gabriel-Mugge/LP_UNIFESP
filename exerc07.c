#include<stdio.h>
#include<stdlib.h>

void ImprimaDataExtenso(char data[]);
void ImprimaDataDigitada(char data[]);

int main(){

    char data[11];

    printf("Por favor informe uma data no seguinte formato dd/mm/aaaa ");
    scanf("%s",&data);
    ImprimaDataDigitada(data);
    printf("\n");
    ImprimaDataExtenso(data);

}

void ImprimaDataExtenso(char data[]){
    int k, dia[2], mes[2], ano[4];
    struct meses{
        char mes[20];
    } meses[12];

    meses[0].mes[20] = "Janeiro";
    meses[1].mes[20] = "Fevereiro";
    meses[2].mes[20] = "Março";
    meses[3].mes[20] = "Abril";
    meses[4].mes[20] = "Maio";
    meses[5].mes[20] = "Junho";
    meses[6].mes[20] = "Julho";
    meses[7].mes[20] = "Agosto";
    meses[8].mes[20] = "Setembro";
    meses[9].mes[20] = "Outubro";
    meses[10].mes[20] = "Novembro";
    meses[11].mes[20] = "Dezembro";


    dia[0] = data[0];
    dia[1] = data[1];
    mes[0] = data[3];
    mes[1] = data[4];
    ano[0] = data[6];
    ano[1] = data[7];
    ano[2] = data[8];
    ano[3] = data[9];

    dia[0] = dia[0]*10 + dia[1];
    mes[0] = mes[0]*10 + mes[1];
    ano[0] = ano[0]*1000 + ano[1]*100 + ano[2]*10 + ano[3];

    //FORMULA PARA SABER QUAL DIA DO ANO É.
    k = dia[0] + mes[0]*2 + 2*(mes[0] + 1) + ano[0] + ano[0]/4 - ano[0]/100 + ano[0]/400 + 2;
    k = k%7;

    switch(k){
        case 0:
            printf("A data em extenso é: Sabado, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
        case 1:
            printf("A data em extenso é: Domingo, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
        case 2:
            printf("A data em extenso é: Segunda, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
        case 3:
            printf("A data em extenso é: Terça, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
        case 4:
            printf("A data em extenso é: Quarta, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
        case 5:
            printf("A data em extenso é: Quinta, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
        case 6:
            printf("A data em extenso é: Sexta, %d de %s de %d",dia[0],meses[mes[0]-1].mes,ano[0]);
            break;
    }

}

void ImprimaDataDigitada(char data[]){
    printf("A data fornecida foi %s",data);
}
