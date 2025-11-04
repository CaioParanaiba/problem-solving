#include <stdio.h>

int main(){

    int N,quadrado;
    scanf("%d",&N);
    for(int i=2;i<=N;i+=2){
        quadrado=i*i;
        printf("%d^2 = %d\n",i,quadrado);
    }

    return 0;
}