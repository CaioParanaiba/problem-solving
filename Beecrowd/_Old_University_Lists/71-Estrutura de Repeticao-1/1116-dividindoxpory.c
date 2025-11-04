#include <stdio.h>
/*Escreva um algoritmo que leia 2 números e imprima o
resultado da divisão do primeiro pelo segundo.
Caso não for possível mostre a mensagem “divisao impossivel”
para os valores em questão.*/
int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(y==0){
            printf("divisao impossivel\n");
        }
        else{
            printf("%.1lf\n",(double)x/y);
        }

    }

    return 0;
}