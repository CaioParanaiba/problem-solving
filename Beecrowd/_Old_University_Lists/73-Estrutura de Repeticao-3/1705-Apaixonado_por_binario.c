#include <stdio.h>
#include <math.h>

int main(){

    long long int numero;
    while(scanf("%lld",&numero)!=EOF){

        long long int multiplo;
        int i=1;
        while(multiplo!=-1){
            multiplo = numero * i;
            // Calculo numero binário
            long long int unidades_nao_binarias=0;
            long long int decompor_numero = multiplo;
            while(decompor_numero>0){
                int unidade;
                unidade = decompor_numero%10;

                if(unidade!=1 && unidade!=0){
                    unidades_nao_binarias++;
                    break;
                }
                decompor_numero=decompor_numero/10;
            }
            i++;

            if(unidades_nao_binarias==0){
                break;
            }
            else if(multiplo>=pow(10,12)){
                multiplo=-1;
            }

        }
        printf("%lld\n",multiplo);

    }  

    return 0;
}