#include <stdio.h>

int soma_um(long long int numero){

    long long int soma=0,quociente=numero;
    while(numero/10!=0)
    {
        while(quociente/10!=0)
        {
            soma+=quociente%10;
            quociente=quociente/10;
        }
        numero = soma + quociente;
        quociente=numero;
        soma=0;

    }

    return numero;
}

int main(){
    
    long long int n,m;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        if(n==0 && m==0){
            break;
        }

        n = soma_um(n);
        m = soma_um(m);

        if(n>m){
            printf("1\n");
        }
        else if(m>n){
            printf("2\n");
        }
        else{
            printf("0\n");
        }

    }

    return 0;
}

// TRANSFORMAR EM STRING E FAZER COM VETOR