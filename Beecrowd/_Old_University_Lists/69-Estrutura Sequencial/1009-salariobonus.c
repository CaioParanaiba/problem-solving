#include <stdio.h>

int main(){

    char name[20];
    double s,v,st;
    scanf("%s", &name);
    scanf("%lf", &s);
    scanf("%lf", &v);
    st = s + v*0.15;
    printf("TOTAL = R$ %.2lf\n", st);

    return 0;
}