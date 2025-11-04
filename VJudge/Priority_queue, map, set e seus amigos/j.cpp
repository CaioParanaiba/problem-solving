#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> p;
    
    int cont = 0;
    long long int vida = 0;
    for(int i=0;i<n;i++)
    {
        int potion;
        cin >> potion;
        if(potion>=0)
        {
            vida+=potion;
            cont++;
        }
        else p.push_back(potion);
    }

    sort(p.begin(),p.end(), [](auto&a,auto&b)
    {
        return a>b;
    });

    
    for(auto ii : p)
    {
        vida+=ii;
        if(vida>=0) cont++;
        else break;
    }

    cout << cont << endl;

    return 0;
}