#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    queue<int> fila;
    while(n>0)
    {
        fila.push(n%10);
        n/=10;
    }

    stack<int> pilha;
    for(int i=0;i<9;i++)
    {
        if(!fila.empty())
        {
            pilha.push(fila.front());
            fila.pop();
        }
        else pilha.push(0);
    }
    
    vector<int> soro;
    while(!pilha.empty())
    {
        soro.push_back(pilha.top());
        pilha.pop();
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(i=0)
            {
                if(soro[j]>=5) cout << '0';
                else cout << '1';
            }
            else if(i==1)
            {
                if(soro[j]>=5)
                {
                    cout << '1';
                    soro[j]-=5;
                }
                else cout << '0';
            }
        }
        cout<< endl;
    }

    return 0;
}