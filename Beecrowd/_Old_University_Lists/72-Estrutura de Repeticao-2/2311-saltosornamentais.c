#include <stdio.h>

int main(){

        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){

            char name[100];
            scanf("%s",name);

            double GD;
            scanf("%lf",&GD);

            //Achar o maior e o menor
            double n1,n2,soma=0;
            scanf("%lf %lf",&n1,&n2);
            double menor = (n1>n2) ? n2 : n1;
            double maior = (n1>n2) ? n1 : n2;
            for(int j=3;j<=7;j++){
                double n0;
                scanf("%lf",&n0);
                if(n0>=menor && n0<=maior){
                    soma+=n0;
                }
                else if(n0>maior){
                    soma+=maior;
                    maior=n0;
                }
                else if(n0<menor){
                    soma+=menor;
                    menor=n0;
                }
            }

            double nota=soma*GD;
            printf("%s %.2lf\n",name,nota);

        }


    return 0;
}