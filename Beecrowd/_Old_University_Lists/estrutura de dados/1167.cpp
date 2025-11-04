#include <bits/stdc++.h>

using namespace std;

void Vizu(queue<pair<string, int>>& jogador)
{
    for(int i=0;i<jogador.size();i++)
    {
        cout << jogador.front().first << " ";
        jogador.push(jogador.front());
        jogador.pop();
    }
    cout << endl;
}

void Giro(queue<pair<string, int>>& jogador,int cont)
{
    int rotacao=cont%jogador.size();
    for(int i=0;i<cont;i++)
    {
        pair<string, int> p = jogador.front();
        jogador.pop();
        jogador.push(p);
    }
}

void Invert(queue<pair<string, int>>& jogador)
{
    stack<pair<string, int>> pilha_jogador;
    //pilhar
    int n = jogador.size();
    for(int i=0;i<n;i++)
    {
        pilha_jogador.push(jogador.front());
        jogador.pop();
    }
    n = pilha_jogador.size();
    for(int i=0;i<n;i++)
    {
        jogador.push(pilha_jogador.top());
        pilha_jogador.pop();
    }
}

int main(){

    int n;
    cin >> n;
    while(n!=0)
    {
        queue<pair<string, int>> jogador;

        //montar o circulo
        for(int i=0;i<n;i++)
        {
            string nome;
            int num;
            cin >> nome >> num;
            jogador.push({nome, num});;
        }

        cout << "Ordem Inicial: ";
        Vizu(jogador);

        int cont=jogador.front().second;
        if(cont%2==0) Giro(jogador,1);
        else Invert(jogador);
        

        cout << "GIRO Inicial: ";
        Vizu(jogador);

        while(jogador.size()>1)
        {
            
            
            cout << "Antes do Giro: ";
            Vizu(jogador);

            Giro(jogador,cont-1);

            cout << "Depois do Giro: ";
            Vizu(jogador);

            cont=jogador.front().second;

            cout << "Eliminado: " << jogador.front().first << endl;

            int cont_eli = jogador.front().second;

            jogador.pop();

            if((cont+cont_eli)%2!=0) Invert(jogador);
            cont=cont_eli;

        }
        cout << "Vencedor(a): " << jogador.front().first << endl;
        cin >> n;
    }
    
    return 0;
}