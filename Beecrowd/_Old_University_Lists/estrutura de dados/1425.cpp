#include <bits/stdc++.h>

using namespace std;

void Pular_frente(stack<int>& pedra, int p)
{
    for(int i=0;i<p;i++) pedra.push(pedra.top()+1);
}

void Pular_tras(stack<int>& pedra, int p)
{
    for(int i=0;i<p;i++) pedra.pop();
}

int main(){

    int n,m;
    cin >> n >> m;

    stack<int> pedra;
    pedra.push(1);
    cout << pedra.top() << endl;

    int i=1,p=2*i-1;

    bool encontrou = (m==1) ? true : false;
    while(!pedra.empty() && pedra.top()<=n && encontrou==false)
    {
        i++;
        p=2*i-1;

        //cout << "Tamanho Pulo " << p << " Top+p " << pedra.top()+p << " Top-p " << pedra.top()-p << endl;

        if(pedra.top()+p<=n) Pular_frente(pedra,p);
        else if(pedra.top()-p>0) Pular_tras(pedra,p);
        else pedra.push(n+1);
        //cout << pedra.top() << endl;
        if(pedra.top()==m) encontrou = true;
    }

    return 0;
}