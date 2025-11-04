#include <stdio.h>
#include <string.h>

int main(){

    int qt;
    scanf("%d",&qt);
    for(int i=1;i<=qt;i++){
        char jogador1[10],escolha1[6],jogador2[10],escolha2[6];
        int jogada1,jogada2;
        scanf("%s %s %s %s",jogador1,escolha1,jogador2,escolha2);
        scanf("%d %d",&jogada1,&jogada2);

        //printf("NOMES: '%s' '%s'\nESCOLHAS: '%s' '%s'\n---FIM DO PRINTF---\n", jogador1, jogador2, escolha1, escolha2);

        
        char escolha_vencedora[6];
        if((jogada1+jogada2)%2==0){
            strncpy(escolha_vencedora, "PAR",6);
        }
        else{
            strncpy(escolha_vencedora,"IMPAR",6);
        }

        int vencerdor = strcmp(escolha1,escolha_vencedora)==0 ? 1 : 2;
        if(vencerdor==1){
            printf("%s\n",jogador1);
        }
        else if(vencerdor==2){
            printf("%s\n",jogador2);
        }

    }

    return 0;
}