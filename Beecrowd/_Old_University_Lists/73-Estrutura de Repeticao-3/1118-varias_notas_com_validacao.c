#include <stdio.h>

int main(){

    int novo_calculo=1;
    while(novo_calculo==1)
    {
        int qtd_nota=0;
        double soma=0,nota=0;
        while(qtd_nota<2)
        {
            scanf("%lf",&nota);
            if(nota>=0 && nota<=10){
                soma+=nota;
                qtd_nota++;
            }
            else{
                printf("nota invalida\n");
            }
        }
        double media = soma/2;
        printf("media = %.2lf\n",media);

        

        int valido=0;
        while(valido==0)
        {
            printf("novo calculo (1-sim 2-nao)\n");

            scanf("%d",&novo_calculo);
            if(novo_calculo==1 || novo_calculo==2){
                valido=1;
            }
        }
        
    }

    return 0;
}