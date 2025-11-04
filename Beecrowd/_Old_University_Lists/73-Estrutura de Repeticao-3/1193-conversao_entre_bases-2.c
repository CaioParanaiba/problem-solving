#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dec_to_bin(long int decimal){
    
    long int resto=0,quociente=decimal;
    long int binario=0,potencia=1;
    while(quociente!=1 && quociente!=0)
    {
        resto=quociente%2;
        quociente/=2;
        binario+=resto*potencia;
        potencia=10*potencia;
    }
    binario+=quociente*potencia;
    return binario;
}

char dec_to_hex(long int decimal){
    char hex[33];
    long int resto=0,quociente=decimal;
    while(quociente!=1 && quociente!=0)
    {
        resto=quociente%16;
        quociente=quociente/16;
        if(resto<10){
            sprintf(hex,"%ld",resto);
        }
        else if(resto==10){
            strcat(hex,"a");
        }
        else if(resto==11){
            strcat(hex,"b");
        }
        else if(resto==12){
            strcat(hex,"c");
        }
        else if(resto==13){
            strcat(hex,"d");
        }
        else if(resto==14){
            strcat(hex,"e");
        }
        else if(resto==15){
            strcat(hex,"f");
        }
        
    }
    return hex[33];
}

int main(){

    int casos;
    while(scanf("%d",&casos)!=EOF){

        for(int i=1;i<=casos;i++){

            char tipo[4],valor_str[33],valor_hex[33];
            long int valor_dec,valor_bin;
            scanf("%s %s",valor_str,tipo);
            
            if(strcmp(tipo,"hex")==0){
                valor_dec = strtol(valor_str,NULL,16);
                valor_bin = dec_to_bin(valor_dec);
                
                printf("%ld dec\n",valor_dec);
                printf("%ld bin\n",valor_bin);
            }
            else if(strcmp(tipo,"bin")==0){
                valor_dec = strtol(valor_str,NULL,2);
                 strcat(valor_hex,dec_to_hex(valor_dec));
                
                printf("%ld dec\n",valor_dec);
                printf("%s hex\n",valor_hex);
            }
            else if(strcmp(tipo,"dec")==0){
                valor_dec = strtol(valor_str,NULL,10);
                valor_bin = dec_to_bin(valor_dec);
                
            }
        }


    }

    return 0;

}

    
