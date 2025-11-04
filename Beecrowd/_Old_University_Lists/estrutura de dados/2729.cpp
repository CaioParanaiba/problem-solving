#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    cin.ignore();

    for(int i=0;i<n;i++)
    {
        set<string> palavras;
        string texto;

        getline(cin,texto);

        stringstream ss(texto);
        string palavra_individual;

        while(ss >> palavra_individual)
        {
            palavras.insert(palavra_individual);
        }

        string separador = "";
        for(auto p : palavras)
        {
            cout << separador << p;
            separador = " ";
        }
        cout << endl;
    }

    return 0;
}