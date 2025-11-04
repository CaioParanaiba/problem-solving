#include <stdio.h>
#include <stdbool.h>

bool Verificar_Vizinhos(int n, int m, int g[n][m],int i, int j)
{
    //verificar vizinhança cima
    if(g[i-1][j-1]  !=7) return false;
    if(g[i-1][j]    !=7) return false;
    if(g[i-1][j+1]  !=7) return false;
    //verificarem baixo
    if(g[i+1][j-1]  !=7) return false;
    if(g[i+1][j]    !=7) return false;
    if(g[i+1][j+1]  !=7) return false;
    //por ultimo os do lado
    if(g[i][j-1]  !=7) return false;
    if(g[i][j+1]  !=7) return false;

    //se passar em tudo
    return true;
}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    int g[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }

    int sabre_i=0, sabre_j=0;   //posição sabre
    bool encontrado = false;

    for(int i=1;i<(n-1);i++)
    {
        for(int j=1;j<(m-1);j++)
        {
            if(g[i][j]==42)
            {
                if(Verificar_Vizinhos(n,m,g,i,j))
                {
                    sabre_i=i+1;
                    sabre_j=j+1;
                    encontrado=true;
                    break;
                }
            }
        }
        if(encontrado==true) break;
    }

    printf("%d %d\n", sabre_i, sabre_j);

    return 0;
}