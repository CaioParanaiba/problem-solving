#include <stdio.h>
/*Escreva um programa que leia 2 valores X e Y e que 
imprima todos os valores entre eles cujo resto da divisão
dele por 5 for igual a 2 ou igual a 3.*/

int main(){

    int x,y;
    scanf("%d %d",&x,&y);
    int maior = (x>y) ? x : y;
    int menor = (x<y) ? x : y;
    for(int i=menor+1;i<maior;i++){
        if(i%5==2 || i%5==3){
            printf("%d\n",i);
        }
    }


    return 0;
}