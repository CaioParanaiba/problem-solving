#include <stdio.h>
#include <math.h>

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {

        int x;
        scanf("%d",&x);
        int raiz=sqrt(x);
        int primo=0;
        for(int j=2;j<=raiz;j++)
        {
            if(x%j==0){
                primo=1;
                j=raiz;
            }

        }

        //verificando se é ou nào primo
        if(primo==1){
            printf("Not Prime\n");
        }
        else{
            printf("Prime\n");
        }

    }

    return 0;
}