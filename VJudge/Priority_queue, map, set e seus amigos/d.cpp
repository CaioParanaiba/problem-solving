#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    while(n!=0 || m!=0)
    {

        set<int> ja;
        set<int> ji;

        for(int i=0;i<n;i++)
        {
            int cd;
            cin >> cd;

            ja.insert(cd);
        }
        for(int i=0;i<m;i++)
        {
            int cd;
            cin >> cd;

            ji.insert(cd);
        }
        int vendas=0;
        for(auto ia : ja)
        {
            auto ii = ji.find(ia);
            if(ii!=ji.end()) vendas++;
        }

        cout << vendas << endl;
        

        cin >> n >> m;
    }

    return 0;
}