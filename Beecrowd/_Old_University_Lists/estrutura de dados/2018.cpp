#include <bits/stdc++.h>

using namespace std;

int main(){

    string categoria;
    map<string, vector<int>> rank;
    while(getline(cin,categoria))
    {
        for(int i=0;i<3;i++)
        {
            string pais;
            getline(cin,pais);

            if(rank.find(pais)==rank.end())
            {
                if(i==0) rank[pais]={1,0,0};
                else if(i==1) rank[pais]={0,1,0};
                else rank[pais]={0,0,1};
            }
            else rank[pais][i] ++;
        }
    }

    vector<pair<string, vector<int>>> rank_ordenado;
    for(auto pair : rank)
    {
        rank_ordenado.push_back(pair);
    }

    sort(rank_ordenado.begin(),rank_ordenado.end(), [](auto& a, auto& b)
    {
        if(a.second[0]!=b.second[0]) return a.second[0] > b.second[0];
        else if(a.second[1]!=b.second[1]) return a.second[1] > b.second[1];
        else if(a.second[2]!=b.second[2]) return a.second[2] > b.second[2];
        else return a.first < b.first;
    });

    cout << "Quadro de Medalhas" << endl;

    for(auto posi : rank_ordenado)
    {
        cout << posi.first << ' ' << posi.second[0] << ' ' << posi.second[1] << ' ' << posi.second[2] << endl;
    }

    return 0;
}