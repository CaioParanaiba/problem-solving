#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {

        int gols1_1,gols2_1;
        scanf("%d x %d",&gols1_1,&gols2_1);
        int pts1=0;
        int pts2=0;

        if(gols1_1>gols2_1){
            pts1 = 3;
        }
        else if(gols1_1==gols2_1){
            pts1 = 1;
            pts2 = 1;
        }
        else{
            pts2 = 3;
        }

        int gols1_2,gols2_2;
        scanf("%d x %d",&gols2_2,&gols1_2);

        if(gols1_2>gols2_2){
            pts1 += 3;
        }
        else if(gols1_2==gols2_2){
            pts1 = 1;
            pts2 = 1;
        }
        else{
            pts2 += 3;
        }

        if(pts1>pts2){
            printf("Time 1\n");
        }
        else if(pts2>pts1){
            printf("Time 2\n");
        }
        else{
            if(gols1_1+gols1_2>gols2_2+gols2_1){
                printf("Time 1\n");
            }
            else if(gols1_1+gols1_2<gols2_2+gols2_1){
                printf("Time 2\n");
            }
            else{
                if(gols1_2>gols2_1){
                    printf("Time 1\n");
                }
                else if(gols1_2<gols2_1){
                    printf("Time 2\n");
                }
                else{
                    printf("Penaltis\n");
                }
            }
        }

    }

    return 0;
}