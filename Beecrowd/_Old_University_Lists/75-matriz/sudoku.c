#include <stdio.h>
#include <string.h>

int main(){

    int n;
    scanf("%d",&n);
    for(int w=1;w<=n;w++)
    {
        int solucao=1, //variavel de solução 1=sem erro e 0=com erro
            s[9][9], //matriz do sudoku
            freq[9]; //lista de frequencia dos numero 9-1 9-2...

        //criar lista freq vazia
        memset(freq, 0, sizeof(freq));

        //criar a matriz e já verificar o soma=j e computar as frequencia;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                scanf("%d",&s[i][j]);
                freq[s[i][j]-1]++;
                if(freq[s[i][j]-1]!=(1)) solucao=0;
                //printf("Freq linha(%d) j: %d\n",i,freq[s[i][j]-1]);
            }
            memset(freq, 0, sizeof(freq));
        }

        //se a solucao ainda for valida
        if(solucao!=0)
        {
            //printf("SOLUCAO: %d\n",solucao);
            //verificar a coluna
            for(int j=0;j<9;j++)
            {
                for(int i=0;i<9;i++)
                {
                    freq[s[i][j]-1]++;
                    if(freq[s[i][j]-1]!=1) solucao=0;
                    //printf("Freq coluna(%d) i: %d\n",j,freq[s[i][j]-1]);
                }
                memset(freq, 0, sizeof(freq));
            }

            if(solucao!=0)
            {
                //printf("SOLUCAO: %d\n",solucao);
                //verifica quadrado
                for(int i=0;i<9;i+=3)
                {
                    for(int j=0;j<9;j+=3)
                    {
                        
                        freq[s[i][j]-1]++;
                        freq[s[i][j+1]-1]++;
                        freq[s[i][j+2]-1]++;

                        freq[s[i+1][j]-1]++;
                        freq[s[i+1][j+1]-1]++;
                        freq[s[i+1][j+2]-1]++;

                        freq[s[i+2][j]-1]++;
                        freq[s[i+2][j+1]-1]++;
                        freq[s[i+2][j+2]-1]++;
                        if(freq[s[i][j]-1]!=1) solucao=0;
                        //printf("Freq quadrante(%d %d) valor: %d\n",i,j,freq[s[i][j]-1]);
                        memset(freq, 0, sizeof(freq));
                    }
                }
            }
            
        }

        //printf("SOLUCAO: %d\n",solucao);
        printf("Instancia %d\n",w);
        if(solucao==1) printf("SIM\n");
        else printf("NAO\n");
        printf("\n");
    }
    

    return 0;
}