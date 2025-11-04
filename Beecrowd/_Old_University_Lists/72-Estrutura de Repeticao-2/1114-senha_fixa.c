#include <stdio.h>
#include <string.h>

int main(){

    int senha_correta=2002;
    int senha_nova;
    while(scanf("%d",&senha_nova)!=EOF){

        if(senha_nova%senha_correta==0){
            printf("Acesso Permitido\n");
            break;
        }
        else{
            printf("Senha Invalida\n");
        }

    }
    
    return 0;
}