#include <stdio.h>

int main(){

    char data[9];
    while(scanf("%s",data)!=EOF)
    {
        char d0=data[0],d1=data[1];
        char m0=data[3],m1=data[4];
        char a0=data[6],a1=data[7];
        printf("%c%c/%c%c/%c%c\n",m0,m1,d0,d1,a0,a1);
        printf("%c%c/%c%c/%c%c\n",a0,a1,m0,m1,d0,d1);
        printf("%c%c-%c%c-%c%c\n",d0,d1,m0,m1,a0,a1);

    }
    

    return 0;
}