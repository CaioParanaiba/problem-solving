#include <stdio.h>

int Crescimento(int pa, int pb, double ga, double gb)
{
    int anos=0;
    while(pa<=pb)
    {
        pa += (int)pa*ga/100;
        pb += (int)pb*gb/100;
        anos++; 
        if(anos>100) break;
    }

    return anos;
}

int main(){

    int T;
    scanf("%d",&T);

    for(int k=0;k<T;k++)
    {

        int pa,pb;          //populacao
        double ga,gb;      //crescimento populacional

        scanf("%d %d %lf %lf",&pa,&pb,&ga,&gb);

        int anos = Crescimento(pa,pb,ga,gb);

        if(anos<=100) printf("%d anos.\n",anos);
        else printf("Mais de 1 seculo.\n");
    }

    return 0;
}