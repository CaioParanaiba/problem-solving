#include <bits/stdc++.h>

using namespace std;

int MDC(long long int x, int a)
{
    for(int i=2;i<sqrt(x)+1;i++)
    {
        if(x%i==0 && a%i==0)
        {
            return i;
        }
    }
    return 1;
}

int main(){

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        set<int> a;
        for(int j=0;j<n;j++)
        {
            int A;
            cin >> A;
            a.insert(A);
        }

        long long int x;

        long long int pot = pow(10,18);
        while(x<=pot)
        {
            for(auto ai : a)
            {
                int valor = MDC(x,ai);
            }

            x++;
        }


    }

    return 0;
}