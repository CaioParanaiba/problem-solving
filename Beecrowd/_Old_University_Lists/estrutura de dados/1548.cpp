#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin >> m;
        vector<int> fila;
        vector<int> fila_organizada;
        for(int j=0;j<m;j++)
        {
            int aluno;
            cin >> aluno;
            fila.push_back(aluno);
            fila_organizada.push_back(aluno);
        }

        sort(fila_organizada.begin(),fila_organizada.end(), [](auto&a,auto&b)
            {
                return a>b;
            }
        );

        int cont=0;
        for(int k=0;k<m;k++)
        {
            if(fila[k]==fila_organizada[k]) cont++;
        }

        cout << cont << endl;
    }

    return 0;
}