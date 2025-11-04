#include <stdio.h>

int main(){

    int N;
    while(scanf("%d", &N) != EOF){

        int votos_impeachment = 0;
        // Laço idiomático em C (de 0 a N-1)
        for(int i = 0; i < N; i++){
            int voto;
            scanf("%d", &voto);
            if(voto == 1){
                votos_impeachment++;
            }
        }

        // Condição usando apenas matemática inteira (mais robusta)
        // 3 * votos >= 2 * N   é equivalente a   votos >= (2*N)/3
        if(3 * votos_impeachment >= 2 * N){
            printf("impeachment\n");
        }
        else{
            printf("acusacao arquivada\n");
        }
    }

    return 0;
}