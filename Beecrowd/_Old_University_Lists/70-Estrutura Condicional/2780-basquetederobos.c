#include <stdio.h>

int main(){

    int d,pt;
    scanf("%d",&d);
    if(d<=800){
        pt=1;
    }
    else if(d<=1400){
        pt=2;
    }
    else if(d<=2000){
        pt=3;
    }
    printf("%d\n",pt);

    return 0;
}