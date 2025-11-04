#include <stdio.h>

int main(){

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        long int pa,pb;
        double ga,gb;

        scanf("%ld %ld %lf %lf",&pa,&pb,&ga,&gb);

        int anos=0;
        while(pa<=pb){
            pa=pa+pa*ga/100;
            pb=pb+pb*gb/100;
            

            anos++;

            if(anos>100){
                printf("Mais de 1 seculo.\n");
                break;
            }
        }
        if(anos<=100){
            printf("%d anos.\n",anos);
        }
    }

    return 0;
}