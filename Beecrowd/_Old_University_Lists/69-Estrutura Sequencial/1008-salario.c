#include <stdio.h>

int main(){

    int f,h;
    double sh, s;
    scanf("%d", &f);
    scanf("%d", &h);
    scanf("%lf", &sh);
    s=sh*h;
    printf("NUMBER = %d\n", f);
    printf("SALARY = U$ %.2lf\n", s);


    return 0;
}