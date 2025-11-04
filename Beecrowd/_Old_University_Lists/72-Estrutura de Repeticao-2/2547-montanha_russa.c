#include <stdio.h>

int main(){


    int n,altura_max,altura_min;
    while(scanf("%d %d %d",&n,&altura_min,&altura_max)!=EOF){
        int n_visitantes=0;
        for(int i=1;i<=n;i++){
            int altura;
            scanf("%d",&altura);
            if(altura>=altura_min && altura<=altura_max){
                n_visitantes++;
            }
        }
        printf("%d\n",n_visitantes);
    }
    

    return 0;
}