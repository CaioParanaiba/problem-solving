#include <stdio.h>

int main(){
    
    int mes,dia;
    while(scanf("%d %d",&mes,&dia)!=EOF){
        
        if(mes==12 && dia==25){
            printf("E natal!\n");
        }
        else if(mes==12 && dia==24){
            printf("E vespera de natal!\n");
        }
        else{
            
            int dias_do_mes[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int dia_natal=360;
            int dia_atual=dia;
            
            for(int i=1;i<=(mes-1);i++){
                
                dia_atual+=dias_do_mes[i];
            
            }
            
            if(dia_atual<dia_natal){
                printf("Faltam %d dias para o natal!\n", dia_natal - dia_atual);
            }
            else{
                printf("Ja passou!\n");
            }
        }
        
    }
    
    return 0;
}








