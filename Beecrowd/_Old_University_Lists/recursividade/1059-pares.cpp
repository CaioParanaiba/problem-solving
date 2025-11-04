#include <iostream>

using namespace std;

int NumPar(int x)
{
    if(x==100) return 100;
    else{
        if((x+1)%2==0) printf("%d\n",x+1);
        return NumPar(x+1)-1;
    }
}

int main()
{
    
    int x = 1;

    NumPar(x);

    return 0;
}