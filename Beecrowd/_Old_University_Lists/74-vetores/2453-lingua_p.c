#include <stdio.h>

int main(){

    char c,mensagem_dec[1000];
    int i=0;

    //primeira letra é sempre p;
    //getchar();

    //contar letras para saber que tem que sempre ficar pulando uma em uma;
    int contador=0;
    while((c = getchar())!=EOF)
    {
        if(c==' ')
        {
            contador=1;
        }

        if(contador%2!=0)
        {
            mensagem_dec[i]=c;
            i++;
            contador=0;
        }
        else{
            contador=1;
        }
        
        
    }
    mensagem_dec[i]='\0';

    printf("%s\n",mensagem_dec);
    return 0;
}