#include <stdio.h>

int main(){

    double s;
    scanf("%lf",&s);
    if(s<=2000){
        printf("Isento\n");
    }
    else{
        double i;
        i=0;
        if((s-4500)>0){
            i+=(s-4500)*28/100;
            s=4500;
        }
        if((s-3000)>0){
            i+=(s-3000)*18/100;
            s=3000;
        }
        if((s-2000)>0){
            i+=(s-2000)*8/100;
        }
        printf("R$ %.2lf\n",i);
    }
    return 0;
}
