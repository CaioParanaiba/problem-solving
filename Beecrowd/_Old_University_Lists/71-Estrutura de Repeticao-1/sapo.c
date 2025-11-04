#include <stdio.h>

int main(){
    
    int p,n;
    scanf("%d %d",&p,&n);
    
    int altura;
    scanf("%d",&altura);
    int cano_atual=altura,cano_seguinte;
    int vida_sapo=1;
    
    for(int i=2;i<=n;i++){
        scanf("%d",&altura);
        cano_seguinte=altura;
        
        if((cano_seguinte - cano_atual)>p || (cano_seguinte - cano_atual)<-p){
            vida_sapo=0;
        }
        
        cano_atual=cano_seguinte;
        
    }
    
    if(vida_sapo==1){
        printf("YOU WIN\n");
    }
    else{
        printf("GAME OVER\n");
    }
    
    return 0;
}