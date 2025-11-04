#include <stdio.h>

int main(){

    int n,m;
    double nota;

    scanf("%d",&n);
    scanf("%d %lf",&m,&nota);

    int melhor_m=m;
    double melhor_nota=nota;

    for(int i=2;i<=n;i++){
        scanf("%d %lf",&m,&nota);

        if(nota>melhor_nota){
            melhor_nota=nota;
            melhor_m=m;
        }
    }
    if(melhor_nota<8){
        printf("Minimum note not reached\n");
    }
    else{
        printf("%d\n",melhor_m);
    }

    return 0;
}