#include <stdio.h>

int main(){

    int h,v;
    double l;
    scanf("%d %d", &h,&v);
    l=v*h/12.0;
    printf("%.3lf\n", l);

    return 0;
}