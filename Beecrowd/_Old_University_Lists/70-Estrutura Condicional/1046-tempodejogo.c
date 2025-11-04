#include <stdio.h>

int main(){

    int inicio,fim,horas;
    scanf("%d %d",&inicio,&fim);
    if(inicio<fim){
        horas = fim-inicio;
    }
    else{
        fim+=24;
        horas=fim-inicio;
    }
    printf("O JOGO DUROU %d HORA(S)\n",horas);

    return 0;
}