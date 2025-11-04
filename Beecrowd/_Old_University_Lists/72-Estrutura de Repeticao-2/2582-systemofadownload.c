#include <stdio.h>

int main(){

    int C;
    scanf("%d",&C);
    
    for(int i=1;i<=C;i++){

        int botao1,botao2;
        scanf("%d %d",&botao1,&botao2);

        int musica = botao1+botao2;
        
        char *musicas[11] = {
            "PROXYCITY",     // Índice 0
            "P.Y.N.G.",      // Índice 1
            "DNSUEY!",       // Índice 2
            "SERVERS",       // Índice 3
            "HOST!",         // Índice 4
            "CRIPTONIZE",    // Índice 5
            "OFFLINE DAY",   // Índice 6
            "SALT",          // Índice 7
            "ANSWER!",       // Índice 8
            "RAR?",          // Índice 9
            "WIFI ANTENNAS"  // Índice 10
        };

        printf("%s\n",musicas[musica]);

        /*if(musica==0){
            printf("PROXYCITY\n");
        }
        else if(musica==1){
            printf("P.Y.N.G.\n");
        }
        else if(musica==2){
            printf("DNSUEY!\n");
        }
        else if(musica==3){
            printf("SERVERS\n");
        }
        else if(musica==4){
            printf("HOST!\n");
        }
        else if(musica==5){
            printf("CRIPTONIZE\n");
        }
        else if(musica==6){
            printf("OFFLINE DAY\n");
        }
        else if(musica==7){
            printf("SALT\n");
        }
        else if(musica==8){
            printf("ANSWER!\n");
        }
        else if(musica==9){
            printf("RAR?\n");
        }
        else if(musica==10){
            printf("WIFI ANTENNAS\n");
        }*/

    }

    return 0;
}