#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int ano_atual = 2015;
    for(int i=1;i<=n;i++)
    {

        int anos_decorridos;
        scanf("%d",&anos_decorridos);
        if(anos_decorridos<ano_atual){
            int ano_passado = ano_atual- anos_decorridos;
            printf("%d D.C.\n",ano_passado);
        }
        else{
            int anoo_passado = anos_decorridos-ano_atual + 1;
            printf("%d A.C.\n",anoo_passado);
        }

    }

    return 0;
}