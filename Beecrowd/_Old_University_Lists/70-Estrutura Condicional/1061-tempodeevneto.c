#include <stdio.h>

int main(){
    
    int di,hi,mi,si,df,hf,mf,sf,w,x,y,z;
    scanf("Dia %d",&di);
    scanf(" %d : %d : %d",&hi,&mi,&si);
    scanf(" Dia %d",&df);
    scanf(" %d : %d : %d",&hf,&mf,&sf);
    si=si+mi*60+hi*60*60+di*24*60*60;
    sf=sf+mf*60+hf*60*60+df*24*60*60;
    z=sf-si;
    w=z/(24*60*60);
    z=z%(24*60*60);
    x=z/(60*60);
    z=z%(60*60);
    y=z/60;
    z=z%60;
    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n",w,x,y,z);
    
    return 0;
}