#include <iostream>

using namespace std;

void Ordem(int * x, int * y)
{

    if(*y<*x)
    {
        int aux = *y;
        *y = *x;
        *x = aux;
    }
    if(*x<0 && *y>0)
    {
        if(-*x<*y) *x = -*x-1;
        else *y=-*y +1;
    }
}

int SomaImparesCon(int x, int y)
{
    if(y-x<2) return 0;
    else
    {
        if((y-1)%2!=0)
        {
            return SomaImparesCon(x,y-1) + y-1;
        }
        else return SomaImparesCon(x,y-1);
    }
}

int main(){

    int x,y;
    cin >> x >> y;

    Ordem(&x,&y);

    //cout << x << " " << y << endl;

    int soma = SomaImparesCon(x,y);

    cout << soma << endl;

    return 0;
}

/*

soma(pi,pf) se 
pi=pf       ->0
pi=pf-1     ->0
-----
pf-pi<2     ->0
pf-pi>=2    ->
pi=pf-2 se (pi-(pf-2)%2!=0) = pi-(pf-2)

*/
// 