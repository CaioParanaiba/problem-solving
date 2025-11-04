#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    map<int,int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(a.find(x)==a.end()) a[x]=1;
        else a[x]++;
    }

    vector<int> b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    long long int cont = 0;
    for(int i=0;i<n;i++)
    {
        int C;
        cin >> C;
        int alvo = b[C-1];
        if(a.find(alvo)!=a.end()) cont += a[alvo];
    }

    cout << cont << endl;



    return 0;
}