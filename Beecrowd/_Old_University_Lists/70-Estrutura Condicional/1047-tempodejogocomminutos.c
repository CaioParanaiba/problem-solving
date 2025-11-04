#include <stdio.h>

int main(){

    int hi,mi,hf,mf,th,tm;
    scanf("%d %d %d %d",&hi,&mi,&hf,&mf);
    mi+=hi*60;
    mf+=hf*60;
    if(mi<mf){
        tm=mf-mi;
        th=tm/60;
        tm=tm%60;
    }
    else{
        mf+=24*60;
        tm=mf-mi;
        th=tm/60;
        tm=tm%60;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",th,tm);

    return 0;
}