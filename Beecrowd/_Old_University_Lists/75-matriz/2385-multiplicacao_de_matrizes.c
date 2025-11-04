#include <stdio.h>

int main(){

    int n, //tamanho matriz
        i,j; 
    long long int p,q,r,s,x,y; //parametros
    
    scanf("%d %lld %lld %lld %lld %lld %lld",&n,&p,&q,&r,&s,&x,&y);
    scanf("%d %d",&i,&j);

    long long int a,b,c=0;
    for(int k=0;k<n;k++)
    {
            a=(p*(i)+q*(k+1))%x;
            b=(r*(k+1)+s*(j))%y;
            c+=a*b;
    }

    
    printf("%lld\n",c);

    return 0;
}