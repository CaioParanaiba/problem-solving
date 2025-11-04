#include <stdio.h>

int main(){

    int total;
    while(scanf("%d",&total)!=EOF)
    {
        //frequencia de sapatos 30->0 60->29;
        int sapatos_D[31],sapatos_E[31];
        for(int i=0;i<31;i++)
        {
            sapatos_D[i]=0;
            sapatos_E[i]=0;
        }

        char lado;
        int sapato;
        for(int i=0;i<total;i++)
        {
            scanf("%d %c",&sapato,&lado);
            sapato-=30;
            if(lado=='D')
            {
                sapatos_D[sapato]++;
            }
            else if(lado=='E')
            {
                sapatos_E[sapato]++;
            }
            
        }

        //calculo diferença
        int sem_par=0;
        for(int i=0;i<31;i++)
        {
            if(sapatos_D[i]>=sapatos_E[i])
            {
                sem_par+=sapatos_D[i]-sapatos_E[i];
            }
            else{
                sem_par+=sapatos_E[i]-sapatos_D[i];
            }
        }

        int pares = (total-sem_par)/2;

        //retornar valor
        printf("%d\n",pares);
    }
    return 0;
}