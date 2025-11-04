#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int quadrado = i*i;
        int cubo = quadrado*i;
        printf("%d %d %d\n",i,quadrado,cubo);
    }

    return 0;
}