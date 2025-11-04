#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int casos;
    while(scanf("%d",&casos)!=EOF){

        for(int i=1;i<=casos;i++){

            char tipo[4],valor_str[33],valor_hex[33],valor_bin[33];
            valor_hex[0]='\0';
            valor_bin[0]='\0';
            long long int valor_dec;
            scanf("%s %s",valor_str,tipo);

            printf("Case %d:\n",i);

            if(strcmp(tipo,"hex")==0){
                valor_dec = strtol(valor_str,NULL,16);
                
                //Conversão para bin
                long long int resto_bin=0,quociente_bin=valor_dec;
                char temp_bin[33];
                int i_bin=0;
                while(quociente_bin>0)
                {
                    char digito_bin;
                        
                    resto_bin=quociente_bin%2;
                    quociente_bin=quociente_bin/2;
                    digito_bin = '0' + resto_bin;

                    temp_bin[i_bin] = digito_bin;
                    i_bin++;
                        
                }
                temp_bin[i_bin]='\0';
                //inverter bin
                char invert_bin[33];
                int invert_i_bin=i_bin-1;
                for(int j=0;j<i_bin;j++){
                    invert_bin[j]=temp_bin[invert_i_bin];
                    invert_i_bin--;
                    }
                invert_bin[i_bin]='\0';

                strcat(valor_bin,invert_bin);

                printf("%ld dec\n",valor_dec);
                printf("%s bin\n",valor_bin);

            }
            
            else if(strcmp(tipo,"bin")==0){
                valor_dec = strtol(valor_str,NULL,2);        
                //Conversão para hex
                long long int resto_hex=0,quociente_hex=valor_dec;
                char temp_hex[33];
                int i_hex=0;
                while(quociente_hex>0)
                {
                    char digito_hex;
                        
                    resto_hex=quociente_hex%16;
                    quociente_hex=quociente_hex/16;

                // conversor para numerico e alfabetico
                    if(resto_hex<10){
                        digito_hex = '0' + resto_hex;
                    }                        else{
                        digito_hex = 'a' + (resto_hex-10);
                    }
                    temp_hex[i_hex] = digito_hex;
                    i_hex++;
                    
                    }
                temp_hex[i_hex]='\0';
                //inverter hex
                char invert_hex[33];
                int invert_i_hex=i_hex-1;
                for(int j=0;j<i_hex;j++){
                    invert_hex[j]=temp_hex[invert_i_hex];
                    invert_i_hex--;
                }
                invert_hex[i_hex]='\0';

                strcat(valor_hex,invert_hex);

                printf("%ld dec\n",valor_dec);
                printf("%s hex\n",valor_hex);
            }
            else if(strcmp(tipo,"dec")==0){
                valor_dec = strtol(valor_str,NULL,10);
                 
                //Conversão para bin
                long long int resto_bin=0,quociente_bin=valor_dec;
                char temp_bin[33];
                int i_bin=0;
                while(quociente_bin>0)
                {
                    char digito_bin;
                        
                    resto_bin=quociente_bin%2;
                    quociente_bin=quociente_bin/2;
                    digito_bin = '0' + resto_bin;

                    temp_bin[i_bin] = digito_bin;
                    i_bin++;
                        
                }
                temp_bin[i_bin]='\0';
                //inverter bin
                char invert_bin[33];
                int invert_i_bin=i_bin-1;
                for(int j=0;j<i_bin;j++){
                    invert_bin[j]=temp_bin[invert_i_bin];
                    invert_i_bin--;
                    }
                invert_bin[i_bin]='\0';

                strcat(valor_bin,invert_bin);


                //Conversão para hex
                long long int resto_hex=0,quociente_hex=valor_dec;
                char temp_hex[33];
                int i_hex=0;
                while(quociente_hex>0)
                {
                    char digito_hex;
                        
                    resto_hex=quociente_hex%16;
                    quociente_hex=quociente_hex/16;

                // conversor para numerico e alfabetico
                    if(resto_hex<10){
                        digito_hex = '0' + resto_hex;
                    }                        else{
                        digito_hex = 'a' + (resto_hex-10);
                    }
                    temp_hex[i_hex] = digito_hex;
                    i_hex++;
                    
                    }
                temp_hex[i_hex]='\0';
                //inverter hex
                char invert_hex[33];
                int invert_i_hex=i_hex-1;
                for(int j=0;j<i_hex;j++){
                    invert_hex[j]=temp_hex[invert_i_hex];
                    invert_i_hex--;
                }
                invert_hex[i_hex]='\0';

                strcat(valor_hex,invert_hex);

                printf("%s hex\n",valor_hex);
                printf("%s bin\n",valor_bin);
            }
            
            printf("\n");
        }


    }

    return 0;

}

    
