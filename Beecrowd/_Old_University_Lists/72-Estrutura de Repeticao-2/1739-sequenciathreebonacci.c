#include <stdio.h>

int main(){

    int N;
    while(scanf("%d",&N)!=EOF){

        //Fibonacci
        int N_threebonacci=0;
        long int n0=1,n1=1,valor_threefibonacci;
        while(N_threebonacci!=N){
            long int n2;

            //Encontrar digito 3
            long int numero=n0,ultimo_digito;
            int encontrou_3=0;
            while(numero>0){
                ultimo_digito=numero%10;
                if(ultimo_digito==3){
                    encontrou_3=1;
                    break;
                }
                numero=numero/10;
            }

            //Condições do threebonacci
            if(n0%3==0 || encontrou_3==1){
                N_threebonacci++;
                valor_threefibonacci=n0;
            }

            n2=n1+n0;
            n0=n1;
            n1=n2;
        }

        printf("%ld\n",valor_threefibonacci);

    }

    return 0;
}