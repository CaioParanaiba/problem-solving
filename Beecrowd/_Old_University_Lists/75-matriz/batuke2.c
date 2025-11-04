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
//            VIZUALIZAÇÃO
//-------------------------------------
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d ",m[i][j]);
        }
        printf("\n");
    }
//-------------------------------------

    int i,j;                //posição inicial do cachorro
    printf("Digite a posicao inicial (indices de 0 a %d): ", n-1);
    scanf("%d %d",&i,&j);

    // --- A CORREÇÃO FINAL: Validar a entrada do usuário ---
    if (i < 0 || i >= n || j < 0 || j >= n) {
        printf("Erro: Posicao inicial (%d, %d) esta fora dos limites da matriz.\n", i, j);
        return 1; // Termina o programa se a entrada for inválida
    }

    int i_prox, j_prox;

    int repetido[n*n+1],
        ordem[n*n],
        passos = 0,
        validos = 0,
        comando = 0,
        acrescimo = 0;
    
    memset(repetido, 0, sizeof(repetido)); //zera os repetidos

    while(validos < n*n)
    {
        int numero_atual;
        
        // Estrutura if/else if limpa
        if(comando==0)
        {
            numero_atual = i*n+j+1;
            if (repetido[numero_atual] == 0) {
                ordem[validos] = numero_atual;
                repetido[numero_atual]=1;
                validos++;
            }
            passos++;
        }
        else if(comando==1) 
        {
            acrescimo++;
            j_prox = j + acrescimo;
            for(int k=j+1; k<=j_prox; k++) {
                if(i >= 0 && i < n && k >= 0 && k < n) {
                    numero_atual = i*n+k+1;
                    if(repetido[numero_atual]==0) {
                        ordem[validos++] = numero_atual;
                        repetido[numero_atual]=1;
                    }
                }
                passos++;
            }
            j=j_prox;
        }
        else if(comando==2)
        {
            i_prox = i + acrescimo;
            for(int k=i+1; k<=i_prox; k++) {
                if(k >= 0 && k < n && j >= 0 && j < n) {
                    numero_atual = k*n+j+1;
                    if(repetido[numero_atual]==0) {
                        ordem[validos++] = numero_atual;
                        repetido[numero_atual] = 1;
                    }
                }
                passos++;
            }
            i=i_prox;
        }
        else if(comando==3)
        {
            acrescimo++;
            j_prox = j - acrescimo;
            for(int k=j-1; k>=j_prox; k--) {
                if(i >= 0 && i < n && k >= 0 && k < n) {
                    numero_atual = i*n+k+1;
                    if(repetido[numero_atual]==0) {
                        ordem[validos++] = numero_atual;
                        repetido[numero_atual]=1;
                    }
                }
                passos++;
            }
            j=j_prox;
        }
        else if(comando==4)
        {
            i_prox = i - acrescimo;
            for(int k=i-1; k>=i_prox; k--) {
                if(k >= 0 && k < n && j >= 0 && j < n) {
                    numero_atual = k*n+j+1;
                    if(repetido[numero_atual]==0) {
                        ordem[validos++] = numero_atual;
                        repetido[numero_atual]=1;
                    }
                }
                passos++;
            }
            i=i_prox;
        }
        
        comando++;
        if(comando==5) comando = 1;

        // Medida de segurança final
        if (passos > n*n*4) {
             break;
        }
    }

    printf("\nOrdem de visitacao:\n");
    for(int k=0; k<validos; k++)
    {
        printf("%d ",ordem[k]);
    }

    printf("\n\nPassos totais: %d\n", passos);
    
    return 0;
}