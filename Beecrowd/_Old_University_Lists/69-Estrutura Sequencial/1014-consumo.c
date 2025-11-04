#include <stdio.h>

int main(){

    int X;
    double Y,c;
    scanf("%d %lf", &X,&Y);
    c=X/Y;
    printf("%.3lf km/l\n", c);


    return 0;
}