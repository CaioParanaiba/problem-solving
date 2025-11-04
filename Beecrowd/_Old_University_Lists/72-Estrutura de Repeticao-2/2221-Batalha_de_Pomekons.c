#include <stdio.h>

int main(){

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){

        int B;
        scanf("%d",&B);
        int AD,DD,LD,AG,DG,LG;
        scanf("%d %d %d %d %d %d",&AD,&DD,&LD,&AG,&DG,&LG);

        float valorgolpe_dabriel = (LD%2==0) ? B : 0;
        float valorgolpe_guarte = (LG%2==0) ? B : 0;

        valorgolpe_dabriel+=(AD+DD)/2.0;
        valorgolpe_guarte+=(AG+DG)/2.0;

        if(valorgolpe_dabriel==valorgolpe_guarte){
            printf("Empate\n");
        }
        else if(valorgolpe_dabriel>valorgolpe_guarte){
            printf("Dabriel\n");
        }
        else{
            printf("Guarte\n");
        }

    }

    return 0;
}