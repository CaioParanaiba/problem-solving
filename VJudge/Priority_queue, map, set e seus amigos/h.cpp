#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x;
    cin >> n >> x;

    vector<pair<int,int>> m;
    for(int i=1;i<=n;i++)
    {
        int xi;
        cin >> xi;
        m.push_back({xi,i});
    }

    sort(m.begin(),m.end());

    
    bool possivel = false;
    int x1,x2,x3;
    for(int i=0;i<n;i++)
    {
        int valor_x1 = m[i].first;

        int alvo1 = x - valor_x1;

        int esquerda = i+1;
        int direita = n-1;

        while(esquerda < direita)
        {
            int valor_x2 = m[esquerda].first;
            int valor_x3 = m[direita].first;

            int alvo2 = valor_x2+valor_x3;

            if(alvo1==alvo2)
            {
                possivel = true;
                x1 = m[i].second;
                x2 = m[esquerda].second;
                x3 = m[direita].second;
                break;
            }
            else if(alvo2 < alvo1) esquerda++;
            else direita--;
        }
        if(possivel) break;
    }

    if(possivel) cout << x1 << " " << x2 << " " << x3 << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}