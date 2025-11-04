#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    while((cin >> n >> k) && (n!=0 && k!=0))
    {
        stack<pair<int,int>> estacionamento;

        bool possivel = true;
        for(int i=0;i<n;i++)
        {
            int ej,sj;
            cin >> ej >> sj;

            if(estacionamento.empty())
            {
                estacionamento.push({ej,sj});
            }
            else
            {
                int ei=estacionamento.top().first;
                int si=estacionamento.top().second;

                if(ej>=si)
                {
                    
                }
                else
                {
                    if(sj>si) possivel = false;
                }


                estacionamento.push({ej,sj});
            }
            if(estacionamento.size()>k) possivel = false;
        }

        if(possivel) cout << "Sim" << endl;
        else cout << "Nao" << endl;
    }

    

    return 0;
}