#include <stdio.h>

int main(){

    double M[12][12];

    char T;
    int linha;
    scanf("%d %c",&linha,&T);

    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++){
            scanf("%lf",&M[i][j]);
        }
    }

    double op=0;
    for(int j=0;j<12;j++)
    {
        op+=M[linha][j];
    }

    if(T=='M'){
        op=op/12;
    }

    printf("%.1lf\n",op);

    return 0;
}