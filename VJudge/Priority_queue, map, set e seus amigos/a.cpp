#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    set<string> nomes;
    for(int i=0;i<n;i++)
    {
        string nome;
        cin >> nome;
        if(nomes.find(nome)!=nomes.end()) cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
            nomes.insert(nome);
        }
    }

    return 0;
}