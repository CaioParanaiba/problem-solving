#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    double soma = 6, fracao =0;
    for(int i=1;i<=n;i++)
    {
        double soma = (i>1) ? fracao + 6 : 6;
        fracao = 1/soma;
        

    }
    double raiz_10 = 3 + fracao;

    printf("%.10lf\n",raiz_10);

    return 0;
}