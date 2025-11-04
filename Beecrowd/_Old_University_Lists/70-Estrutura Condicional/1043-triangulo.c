#include <stdio.h>

int main(){

    double a,b,c,aop;
    scanf("%lf %lf %lf",&a,&b,&c);
    if((a+b)>c && (a+c)>b && (b+c)>a){
        aop=a+b+c;
        printf("Perimetro = %.1lf\n",aop);
    }
    else{
        aop=(a+b)*c/2;
        printf("Area = %.1lf\n",aop);
    }

    return 0;
}