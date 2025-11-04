/*
E ai goftou da nofa tarde funtof?
E ai gostou da nossa tarde juntos?

Fem melhor que ir ao foológico, não é mefmo?
Bem melhor que ir ao zoológico, não é mesmo?

s/ss->f
b/z/s->f

A 4 maratona de frogramação da UF efta infelifmente acafando, maf eferamof que efte fim fignifique
A 4 maratona de porgramação da UF esta inflizmente acabando, mas esperamos que este fim signifique

p/s/b

A entrada é composta for varias linhas de texto. Não vamos revelar o número fofitifo de linhas
nem tampouco o limite de caracteres por linha de texto.

s/ss/b/z/p/x/v/j

*/
#include <stdio.h>

int main(){

    char c, c_anterior;
    int primeiro=1;
    while((c = getchar())!=EOF)
    {
        if(c=='s' || c=='b' || c=='z' || c=='p' || c=='x' || c=='v' || c=='j'){
            c='f';
        }
        else if(c=='S' || c=='B' || c=='Z' || c=='P' || c=='X' || c=='V' || c=='J'){
            c='F';
        }
        if(primeiro==1){
            putchar(c);
            c_anterior = c;
            primeiro=0;
        }
        else if(primeiro==0){
            if((c_anterior == c && (c=='f' || c=='F')) || (c_anterior=='f' && c=='F') || (c_anterior=='F' && c=='f')){
                c_anterior = c;
            }
            else{
                putchar(c);
            }
        }
        
        
    }

    return 0;
}