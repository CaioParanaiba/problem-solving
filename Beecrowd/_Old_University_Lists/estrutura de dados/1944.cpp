#include <bits/stdc++.h>

using namespace std;

void AddPalavra(stack<char>& jogo, string palavra)
{
    for(int i=0;i<palavra.size();i++)
    {
        jogo.push(palavra[i]);
    }
}

void RemovePalavra(stack<char>& jogo)
{
    for(int i=0;i<4;i++)
    {
        jogo.pop();
    }
}

bool VerifPalavra(stack<char> jogo, string palavra)
{
    bool invertido = true;
    for(int i=0;i<palavra.size();i++)
    {
        if(jogo.top()!=palavra[i]) invertido = false;
        jogo.pop();
    }

    return invertido;
}

int main(){

    int n;
    cin >> n;
    int pont=0;

    stack<char> jogo;
    for(int i=0;i<n;i++)
    {
        if(jogo.empty()) AddPalavra(jogo, "FACE");

        string palavra = "";
        for(int j=0;j<4;j++)
        {
            char c;
            cin >> c;
            palavra+=c;
        }

        if(VerifPalavra(jogo,palavra))
        {
            RemovePalavra(jogo);
            pont++;
        }
        else AddPalavra(jogo,palavra);
    }

    cout << pont << endl;

    return 0;
}