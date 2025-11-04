#include <stdio.h>

int main(){

    int c,n;
    double v,s;
    scanf("%d %d %lf", &c,&n,&v);
    s=n*v;
    scanf("%d %d %lf", &c,&n,&v);
    s=s+n*v;
    printf("VALOR A PAGAR: R$ %.2lf\n", s);

    return 0;
}