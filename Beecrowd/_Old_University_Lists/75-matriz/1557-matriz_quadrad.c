#include <stdio.h>
#include <math.h>

int unidade(int numero){

    int potencia=1,quociente=numero;
    while(quociente!=0)
    {   
        potencia=potencia*10;
        quociente=numero/(potencia);
    }

    return potencia;
}

int main(){

    int n;
    scanf("%d",&n);
    while(n!=0)
    {

        int m[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                m[i][j]=pow(2,j+i);
            }
        }

        int maior_pow = pow(2,2*n-2);
        //printf("Maior pow: %d\n",maior_pow);

        //descobrir o maior inteiro
        int potencia=1,quociente=maior_pow;
        while(quociente!=0)
        {   
            //printf("ANTES -> Quociente : %d potenica: %d\n",quociente,potencia);
            potencia=potencia*10;
            quociente=maior_pow/(potencia);
            //printf("DEPOIS -> Quociente : %d potenica: %d\n",quociente,potencia);
        }

        //printf("Maior potencia: %d\n",potencia);

        int potencia_numero;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                potencia_numero = unidade(m[i][j]);
                if(j==0)
                {
                    for(int k=1;k<(potencia/potencia_numero);k=k*10)
                    {
                        printf(" ");
                    }
                }
                else{
                    for(int k=1;k<=(potencia/potencia_numero);k=k*10)
                    {
                        printf(" ");
                    }
                }
                
                printf("%d",m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d",&n);
    }

    return 0;
}

