#include <stdio.h>

int main(){

    int novo_grenal=1;
    int n_grenais=0;
    int empate=0,inter=0,gremio=0;


    while(novo_grenal!=2){

        n_grenais++;

        int gols_inter,gols_gremio;
        scanf("%d %d",&gols_inter,&gols_gremio);

        if(gols_gremio==gols_inter){
            empate++;
        }
        else if(gols_inter>gols_gremio){
            inter++;
        }
        else{
            gremio++;
        }

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d",&novo_grenal);
    }
    printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n",n_grenais,inter,gremio,empate);
    if(inter==gremio){
        printf("Nao houve vencedor\n");
    }
    else if(inter>gremio){
        printf("Inter venceu mais\n");
    }
    else{
        printf("Gremio venceu mais\n");
    }

    return 0;
}