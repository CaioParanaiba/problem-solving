#include <stdio.h>

int main(){

    int n,t[9][9];

    scanf("%d",&n);
    for(int k=0;k<n;k++)
    {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if((i-j)>=0 && i%2==0 && j%2==0) scanf("%d",&t[i][j]);
                else t[i][j] = 0;
            }
        }

        //ultima linha
        for(int j=0;j<9;j++)
        {
            if(j%2!=0)
            {
                t[8][j] = (t[6][j-1]-t[8][j-1]-t[8][j+1])/2;
            }
        }
        //printf("RODEI 1\n");
        //outras linhas
        for(int i=7;i>0;i--)
        {
            //printf("RODEI 2\n");
            for(int j=0;j<9;j++)
            {
                //printf("RODEI 3\n");
                if((i-j)>=0 && t[i][j]==0)
                {
                    //printf("RODEI\n");
                    t[i][j] = t[i+1][j]+t[i+1][j+1];
                }
            }   
        }
        //imprimir piramide
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(j==0) printf("%d",t[i][j]);
                else if((i-j)>=0) printf(" %d",t[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}