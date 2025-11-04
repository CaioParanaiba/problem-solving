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
        int soma=1;
        for(int j=2;j<=raiz;j++)
        {

            if(x%j==0)
            {
                soma+=(j+x/j);
            }

        }
        if(soma==x && x!=1){
            printf("%d eh perfeito\n",x);
        }
        else{
            printf("%d nao eh perfeito\n",x);
        }
    }

    return 0;
}