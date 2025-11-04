#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    for(int i=0;i<t;i++)
    {
        int n,m;
        cin >> n >> m;

        vector<pair<string,vector<double>>> renas;
        for(int j=0;j<n;j++)
        {
            string nome;
            cin >> nome;
            vector<double> caract;
            for(int k=0;k<3;k++)
            {
                double valor;
                cin >> valor;
                caract.push_back(valor);
            }

            pair<string,vector<double>> info;
            info = {nome,caract};

            renas.push_back(info);

        }

        sort(renas.begin(),renas.end(), [](auto& a,auto& b){
            if(a.second[0]!=b.second[0]) return a.second[0] > b.second[0];
            else
            {
                if(a.second[1]!=b.second[1]) return a.second[1] < b.second[1];
                else
                {
                    if(a.second[2]!=b.second[2]) return a.second[2] < b.second[2];
                    else return a.first<b.first;
                }
            }
        });

        cout << "CENARIO {" << i+1 << "}" << endl;

        for(int j=0;j<m;j++)
        {
            cout << j+1 << " - " << renas[j].first << endl;
        }
    }


    return 0;
}