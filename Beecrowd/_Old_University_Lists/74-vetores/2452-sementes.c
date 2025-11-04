#include <stdio.h>

int main(){

    int f,r;
    scanf("%d %d",&f,&r);

    int semente[r];

    int distance=0;
    scanf("%d",&semente[0]);
    for(int i=1;i<r;i++)
    {
        scanf("%d",&semente[i]);
        if(semente[i]-semente[i-1]>distance)
        {
            distance=semente[i]-semente[i-1];
        }

    }

    int distance_0 = semente[0]-1;
    int distance_f = f - semente[r-1];

    int bigger_bord = (distance_0>=distance_f) ? distance_0 : distance_f;

    if(bigger_bord>(distance/2))
    {
        distance=bigger_bord;
    }
    else{
        distance=distance/2;
    }

    printf("%d\n",distance);

    return 0;
}