#include <stdio.h>

int main(){

    int nc;
    scanf("%d",&nc);

    for(int c=1;c<=nc;c++)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        // morto = 1, vivo=0
        int morto[n];

        int kill_cont=1,mortes=0,ultimo_morto;
        for(int i=0;i<n;i++)
        {
            morto[i]=0;
        }

        while(mortes!=n)
        {
            //printf("------New Round-----\n");
            for(int i=0;i<n;i++)
            {
                //printf("Kill count: %d Pessoa atual: %d\n",kill_cont,i);
                if(morto[i]==0)
                {
                    if(kill_cont==k)
                    {
                        morto[i]=1;
                        mortes++;
                        ultimo_morto=i;
                        kill_cont=0;
                    }
                    kill_cont++;
                }
            }
            
        }
        ultimo_morto++;

        printf("Case %d: %d\n",c,ultimo_morto);
    }

    


    return 0;
}