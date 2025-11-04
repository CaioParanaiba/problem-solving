#include <stdio.h>

int main(){

    for(int I=1;I<=9;I+=2){
        for(int J=I+6;J>=I+4;J--){
            printf("I=%d J=%d\n",I,J);
        }
    }

    return 0;
}