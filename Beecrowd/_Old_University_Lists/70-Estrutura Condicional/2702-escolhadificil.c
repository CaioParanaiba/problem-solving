#include <stdio.h>

int main(){

    int ca,ba,pa,cr,br,pr,t;
    scanf("%d %d %d",&ca,&ba,&pa);
    scanf("%d %d %d",&cr,&br,&pr);
    t=0;
    t +=(cr>ca) ? (cr-ca) : 0;
    t +=(br>ba) ? (br-ba) : 0;
    t +=(pr>pa) ? (pr-pa) : 0;
    printf("%d\n",t);

    return 0;
}