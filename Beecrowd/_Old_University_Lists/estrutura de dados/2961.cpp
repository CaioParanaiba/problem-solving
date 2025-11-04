#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();

    vector<int> acertos = {0,0,0,0};
    for(int i=0;i<n;i++)
    {
        string frase;
        getline(cin, frase);

        queue<string> palpite;
        queue<string> vencedores;

        for(int i=0;i<4;i++)
        {
            string P;
            getline(cin,P);
            palpite.push(P);
        }

        getline(cin, frase);

        for(int i=0;i<4;i++)
        {
            string V;
            getline(cin,V);
            vencedores.push(V);
        }

        for(int i=0;i<4;i++)
        {
            if(palpite.front()==vencedores.front()) acertos[i]++;
            palpite.pop();
            vencedores.pop();
        }
    }
    int min = *min_element(acertos.begin(),acertos.end());

    string separador = ""; // Começa vazio
    for(int i=0;i<4;i++)
    {
        if(acertos[i]==min)
        {
            cout << separador << i+1;
            separador = " ";
        }
    }
    cout << endl;

    return 0;
}