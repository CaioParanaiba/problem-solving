#include <stdio.h>

int main(){

    int a1,a2,a3,op1,op2,op3,melhor;
    scanf("%d %d %d",&a1,&a2,&a3);
    op1=a2*2+a3*4;
    op2=a1*2+a3*2;
    op3=a1*4+a2*2;
    melhor=op1;
    if(op2<melhor){
        melhor=op2;
    }
    else if(op3<melhor){
        melhor=op3;
    }
    printf("%d\n",melhor);

    return 0;
}