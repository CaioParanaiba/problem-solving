#include <stdio.h>

int main(){

    double A,B,C,atr,ac,at,aq,ar;
    scanf("%lf %lf %lf", &A,&B,&C);
    atr=A*C/2;
    ac=3.14159*C*C;
    at=(A+B)*C/2;
    aq=B*B;
    ar=A*B;

    printf("TRIANGULO: %.3lf\n", atr);
    printf("CIRCULO: %.3lf\n", ac);
    printf("TRAPEZIO: %.3lf\n", at);
    printf("QUADRADO: %.3lf\n", aq);
    printf("RETANGULO: %.3lf\n", ar);

    return 0;
}