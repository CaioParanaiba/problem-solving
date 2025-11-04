#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    cin.ignore();

    map<string, string> idioma_frase;
    for(int i=0;i<n;i++)
    {
        string idioma,frase;
        getline(cin,idioma);
        getline(cin,frase);

        idioma_frase[idioma] = frase;
    }

    int m;
    cin >> m;
    cin.ignore();


    for(int i=0;i<m;i++)
    {
        string name;
        getline(cin,name);
        string idioma;
        getline(cin,idioma);

        cout << name << endl;
        cout << idioma_frase[idioma] << endl;
        cout <<endl;
    }

    return 0;
}