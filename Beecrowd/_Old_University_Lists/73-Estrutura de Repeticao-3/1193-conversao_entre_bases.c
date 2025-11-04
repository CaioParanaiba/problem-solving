#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valor_hexa(char c){
    //vou fazer todas as letras serem minusculas
    char c_minusculo = tolower(c);

    //se for um digito
    if(isdigit(c_minusculo)){
        int valor_hexa = c_minusculo - '0';
        return valor_hexa;
    }
    else{
        int valor_hexa = c_minusculo - 'W';
        return valor_hexa;
    }


}

int hex_str_to_int(char valor_str[]){
    int tamanho = strlen(valor_str);
    int decimal=0,potencia=1;
    for (int i = tamanho-1; i>=0; i--){
        char char_atual = valor_str[i];
        int valor_char_atual = valor_hexa(char_atual);
        decimal+=valor_char_atual*potencia;
        potencia=potencia*16;
    }
    return decimal;
}

int dec_int_to_bin(int valor_decimal){

    int resto,potencia=1,binario=0;
    int decimal = valor_decimal;
    while(decimal>0)
    {
        resto = decimal%2;
        decimal = decimal/2;
        binario+=resto*potencia;
        potencia=potencia*10;
    }

    return binario;

}

int valor_bin(char c){
    int valor_bin = c - '0';

    return valor_bin;

}

int bin_str_to_dec(char valor_str[]){
    int tamanho =strlen(valor_str);
    int decimal=0,potencia=1;
    for(int i=tamanho-1;i>=0;i--){
        char char_atual = valor_str[i];
        decimal=valor_bin(char_atual)*potencia;
        potencia=potencia*2;
    }
    return decimal;

}


int main(){

    int casos;
    while(scanf("%d",&casos)!=EOF){

        for(int i=1;i<=casos;i++){

            char tipo[4],valor_str[33];
            scanf("%s %s",valor_str,tipo);

            int numero_decimal,numero_binario;
            if(strcmp(tipo,"hex")==0)
            {
                numero_decimal = hex_str_to_int(valor_str);
                numero_binario = dec_int_to_bin(numero_decimal);
                printf("%d dec\n%d bin\n",numero_decimal,numero_binario);
            }
            else if(strcmp(tipo,"bin")==0)
            {
                numero_decimal = bin_str_to_dec(valor_str);
                printf("%d dec\n",numero_decimal);


            }


        }



    }

    return 0;
}

