#include <stdio.h>

int main(){

    long long int n;
    while(scanf("%lld",&n)!=EOF){

        long long int base_dois=2;
        int interações=1;
        while(n>base_dois){
            base_dois=base_dois*base_dois;
            interações++;
        }

        long long int binario=1,decimal=interações;
        while(binario%n!=0){
            int resto,quociente=decimal;

            //caso 1
            resto=quociente%2;
            binario=resto;

            //casos maiores que 1
            long long int potencia=10;
            while(quociente!=1){
                quociente=quociente/2;
                resto=quociente%2;
                binario=binario+resto*potencia;
                potencia=potencia*10;
            }
            decimal++;
            if(potencia>=1000000000000){
                binario=-1;
                break;
            }
        }

        printf("%lld\n",binario);

    }

    

    return 0;
}