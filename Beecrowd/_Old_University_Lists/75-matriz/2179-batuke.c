#include <stdio.h>
#include <string.h>

int main(){
    
    int n;              //tamanho da matriz
    scanf("%d",&n);
    
    //criar matriz
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j] = i*n+j+1;
        }
    }
    
//-------------------------------------
//            VIZUALIZÇÃO
//-------------------------------------
/*   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
*/ 
//-------------------------------------
//            VIZUALIZÇÃO
//-------------------------------------

    int i,j;                //posição inicial do cachorro
    
    scanf("%d %d",&i,&j);

    int i_prox, j_prox;     //posição final do cachorro

    int repetido[n*n+1],      //verifica se o numero já foi repetido
        ordem[n*n],           //cria a lista da ordem
        passos = 0,         //contador de passos
        validos = 0,        //conta os passos validos
        comando = 1,        //0-> incial 1->direita 2->baixo 3->esquerda 4->cima
        acrescimo = 0;      //numero que ira crescer junto com as voltas
    
    memset(repetido, 0, sizeof(repetido)); //zera os repetidos

    // ponto inicial
    int numero_atual = i*n+j+1;
    ordem[validos] = numero_atual;
    repetido[numero_atual]=1;
    validos++;
    passos++;

    while(validos!=(n*n))
    {        
        if(comando==1) 
        {
            acrescimo++;
            j_prox = j + acrescimo;

            for(int k=(j+1);k<=j_prox;k++)
            {
                if(i >= 0 && i < n && k>=0 && k<n)
                {
                    numero_atual = i*n+k+1;         //atualiza a posição atual

                    if(repetido[numero_atual]==0)   //verifica se já foi percorrido
                    {
                        ordem[validos] = numero_atual;
                        validos++;
                        repetido[numero_atual]=1;
                    }
                }                
                passos++;
                if(validos==n*n) break;             // evito ele contnuar dando mais passos depois de acabar
            }
            j=j_prox;
        }
        else if(comando==2)
        {
            i_prox = i + acrescimo;

            for(int k=(i+1);k<=i_prox;k++)
            {
                if(k >= 0 && k < n && j>=0 && j<n)
                {
                    numero_atual = k*n+j+1;         //atualiza a posição atual

                    if(repetido[numero_atual]==0)   //verifica se já foi percorrido
                    {
                        ordem[validos] = numero_atual;
                        repetido[numero_atual] = 1;
                        validos++;
                        
                    }
                }
                
                passos++;
                if(validos==n*n) break;             // evito ele contnuar dando mais passos depois de acabar
            }
            i=i_prox;
        }
        else if(comando==3)
        {
            acrescimo++;
            j_prox = j - acrescimo;

            for(int k=(j-1);k>=j_prox;k--)
            {
                if(i >= 0 && i < n && k>=0 && k<n)
                {
                    numero_atual = i*n+k+1;         //atualiza a posição atual

                    if(repetido[numero_atual]==0)   //verifica se já foi percorrido
                    {
                        ordem[validos] = numero_atual;
                        validos++;
                        repetido[numero_atual]=1;
                    }
                }
                
                passos++;
                if(validos==n*n) break;             // evito ele contnuar dando mais passos depois de acabar
            }
            j=j_prox;
        }
        else if(comando==4)
        {
            i_prox = i - acrescimo;

            for(int k=(i-1);k>=i_prox;k--)
            {
                if(k >= 0 && k < n && j>=0 && j<n)
                {
                    numero_atual = k*n+j+1;         //atualiza a posição atual

                    if(repetido[numero_atual]==0)   //verifica se já foi percorrido
                    {
                        ordem[validos] = numero_atual;
                        validos++;
                        repetido[numero_atual]=1;
                    }
                }
                
                passos++;
                if(validos==n*n) break;             // evito ele contnuar dando mais passos depois de acabar
            }
            i=i_prox;
        }
        comando++;
        if(comando==5) comando =1;
        
    }

    //imprimir a ordem
    for(int k=0;k<validos;k++)
    {
        if (k == validos - 1) {
            printf("%d", ordem[k]);
        } else {
            printf("%d ", ordem[k]);
        }
    }

    printf("\n%d\n",passos);
    
    return 0;
}