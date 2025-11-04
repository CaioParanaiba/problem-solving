#include <stdio.h>

int main(){

    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {

        int p[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&p[i][j]);
                if(p[i][j]==1) p[i][j]=9;
            }
        }

        //verificar
        int cont=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(p[i][j]==0)
                {
                    if((i+1)!=n && p[i+1][j]==9) cont++;
                    if((j+1)!=m && p[i][j+1]==9) cont++;
                    if((i-1)!=-1 && p[i-1][j]==9) cont++;
                    if((j-1)!=-1 && p[i][j-1]==9) cont++;
                    p[i][j]=cont;
                    cont=0;
                }
                
                printf("%d",p[i][j]);

            }
            printf("\n");
        }

    }

    return 0;
}