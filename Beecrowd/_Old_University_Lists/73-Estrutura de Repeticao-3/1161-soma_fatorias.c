#include <stdio.h>

int main(){

    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        m = (m==0) ? 1 : m;
        n = (n==0) ? 1 : n;

        //m
        long long int fat_m=1;
        long long int fat_n=1;
        if(m==n)
        {
            for(int i=1;i<=m;i++)
            {
                fat_m=fat_m*i;
            }
            fat_m=fat_m*2;
        }
        else if(m>n)
        {
            for(int i=1;i<=n;i++)
            {
                fat_n=fat_n*i;
            }
            fat_m=fat_n;
            for(int i=n+1;i<=m;i++)
            {
                fat_m=fat_m*i;
            }
            fat_m+=fat_n;
        }
        else if(m<n)
        {
            for(int i=1;i<=m;i++)
            {
                fat_m=fat_m*i;
            }
            fat_n=fat_m;
            for(int i=m+1;i<=n;i++)
            {
                fat_n=fat_n*i;
            }
            fat_m+=fat_n;
        }
        
        printf("%lld\n",fat_m);
    }
    

    return 0;
}