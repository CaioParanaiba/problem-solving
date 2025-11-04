#include <bits/stdc++.h>

using namespace std;

int main(){

    string texto;
    getline(cin,texto);

    vector<pair<string,int>> palavras;
    int tamanho_inicial = 0;
    int tamanho = tamanho_inicial;
    while(!texto.empty())
    {
        size_t espaco_id = texto.find(' ');

        if(espaco_id != string::npos)
        {
            palavras.push_back({texto.substr(tamanho_inicial,espaco_id),tamanho});
            texto.erase(tamanho_inicial,espaco_id+1);
        }
        else
        {
            palavras.push_back({texto.substr(tamanho_inicial),tamanho});
            texto.erase(tamanho_inicial);
        }
        tamanho +=(espaco_id+1);
        
    }

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        
        string palavra;
        cin >> palavra;
        string separador = "";
        bool encontrado = false;
        for(int j=0;j<palavras.size();j++)
        {
            if(palavra==palavras[j].first)
            {
                cout << separador << palavras[j].second;
                separador = " ";
                encontrado = true;
            }
        }
        if(!encontrado) cout << "-1";
        cout << endl;
    }

    return 0;
}