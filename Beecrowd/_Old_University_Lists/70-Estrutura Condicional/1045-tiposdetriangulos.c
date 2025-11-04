#include <stdio.h>

int main(){

    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(b>a && b>c){
        double b1;
        b1=a;
        a=b;
        b=b1;
    }
    else if(c>a && c>b){
        double c1;
        c1=a;
        a=c;
        c=c1;
    }
    if(a>=(b+c)){
        printf("NAO FORMA TRIANGULO\n");
    }
    else{
        a=a*a;
        b=b*b;
        c=c*c;
        if(a==(b+c)){
            printf("TRIANGULO RETANGULO\n");
        }
        else if(a>(b+c)){
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else{
            printf("TRIANGULO ACUTANGULO\n");
        }
        if(a==b && a==c){
            printf("TRIANGULO EQUILATERO\n");
        }
        else if(a==b || b==c || a==c){
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    


    return 0;
}