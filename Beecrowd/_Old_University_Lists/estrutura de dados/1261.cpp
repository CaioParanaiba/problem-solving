#include <bits/stdc++.h>

using namespace std;

int main(){

    int m,n;
    cin >> m >> n;

    map<string,int> cargos;
    for(int i=0;i<m;i++)
    {
        string cargo;
        int salario;

        cin >> cargo >> salario;

        cargos[cargo] = salario;
    }


    for(int i=0;i<n;i++)
    {
        string palavra;
        cin >> palavra;
        int salario_total = 0;
        while(palavra != ".")
        {
            if(cargos.find(palavra)!=cargos.end()) salario_total+=cargos[palavra];

            cin >> palavra;
        }
        cout << salario_total << endl;
    }

    return 0;
}