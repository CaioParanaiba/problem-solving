#include <stdio.h>

int main(){

    int n,d;
    while(scanf("%d %d",&n,&d)!=EOF){

        int dia_c,mes_c,ano_c;
        int dias_possiveis=0;

        for(int i=1;i<=d;i++){

            int dia,mes,ano;
            scanf("%d/%d/%d",&dia,&mes,&ano);

            int confirmados=0;
            for(int j=1;j<=n;j++){

                int valor;
                scanf("%d",&valor);
                
                if(valor==1){
                    confirmados++;
                }
            }
            if(confirmados==n && dias_possiveis==0){
                dias_possiveis++;
                dia_c=dia;
                mes_c=mes;
                ano_c=ano;
            }
            else if(confirmados==n && dias_possiveis!=0){
                dias_possiveis++;
                if(ano<ano_c || (ano==ano_c && mes<mes_c) || (ano==ano_c && mes==mes_c && dia<dia_c)){
                    dia_c=dia;
                    mes_c=mes;
                    ano_c=ano;
                }
            }
        }
        if(dias_possiveis==0){
            printf("Pizza antes de FdI\n");
        }
        else{
            printf("%d/%d/%d\n",dia_c,mes_c,ano_c);
        }
    }

    
    
    return 0;
}