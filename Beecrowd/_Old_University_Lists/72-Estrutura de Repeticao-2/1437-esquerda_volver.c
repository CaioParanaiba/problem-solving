#include <stdio.h>
#include <string.h>

int main(){

    int N;
    while(scanf("%d",&N)!=EOF){
        if(N==0){
            break;
        }

        char lado;
        int soma=0;
        for(int i=1;i<=N;i++){
            scanf(" %c",&lado);

            if(lado=='D'){
                soma++;
            }
            else if(lado=='E'){
                soma--;
            }

        }

        if(soma%4==0){
            printf("N\n");
        }
        else if(soma%4==1 || soma%4==-3){
            printf("L\n");
        }
        else if(soma%4==2 || soma%4==-2){
            printf("S\n");
        }
        else if(soma%4==3 || soma%4==-1){
            printf("O\n");
        }

    }

    return 0;
}