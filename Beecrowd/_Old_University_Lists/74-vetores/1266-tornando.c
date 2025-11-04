#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int postes[n+2];

        //criar postes, continuo o primeiro é o ultimo e o ultimo o primeiro
        for(int i=1;i<(n+1);i++)
        {
            scanf("%d",&postes[i]);
        }
        postes[0]=postes[n];
        postes[n+1]=postes[1];

        //preciso fazer duas abordagens direita para esquerda e esquerda para direita
        int postes_invert[n+2];
        for(int i=0;i<(n+1);i++)
        {
            postes_invert[i]=postes[(n+1-i)];
        }

        //vamos calcular as duas abordagens
        int novos_postes=0,novos_postes_invert=0;
        for(int i=1;i<=n;i++)
        {
            if(postes[i-1]==0 && postes[i]==postes[i-1])
            {
                novos_postes++;
                postes[i]=1;
            }

            if(postes_invert[i-1]==0 && postes_invert[i]==postes_invert[i-1])
            {
                novos_postes_invert++;
                postes_invert[i]=1;
            }
        }

        int min_postes = (novos_postes>novos_postes_invert) ? novos_postes_invert : novos_postes;

        printf("%d\n",min_postes);

        
        //finalização caso 0 o programa termina
        scanf("%d",&n);
    }

    return 0;
}
