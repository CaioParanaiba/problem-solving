#include <stdio.h>

int main(){

    double s,r;
    int p;
    scanf("%lf",&s);
    if(s>=0 && s<=400.00){
        p=15;
    }
    else if(s>400 && s<=800.00){
        p=12;
    }
    else if(s>800 && s<=1200.00){
        p=10;
    }
    else if(s>1200 && s<=2000.00){
        p=7;
    }
    else if(s>2000.00){
        p=4;
    }
    else{
        printf("salario incorreto.\n");
    }
    r=s*p/100;
    s+=r;
    printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d \%\n",s,r,p);

    return 0;
}