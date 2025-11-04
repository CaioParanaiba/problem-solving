#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin >> m;

        char letra;

        int erros=0;
        for(int i=0;i<m;i++)
        {
            cin >> letra;
            if(letra!=(65+i)) erros++;
        }

        if(erros>2) cout << "There aren't the chance." << endl;
        else cout << "There are the chance." << endl;
    }

    return 0;
}