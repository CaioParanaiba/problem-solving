#include <stdio.h>

int main(){

    int l,c,cor;
    scanf("%d %d",&l,&c);
    cor = ((c+l)%2==0) ? 1 : 0;
    printf("%d\n",cor);

    return 0;
}