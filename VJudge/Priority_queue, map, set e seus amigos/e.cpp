#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    while(n!=0)
    {

        deque<int> postos;
        for(int i=0;i<n;i++)
        {
            int posto;
            cin >> posto;
            postos.push_back(posto);
        }
        sort(postos.begin(),postos.end());

        int po_inicial = 0;
        bool possible = true;
        for(auto ii : postos)
        {
            if(ii-po_inicial>200) possible = false;
            po_inicial=ii;

        }
        int po_final = 1422;
        if(2*(po_final-po_inicial)>200) possible = false;

        if(possible) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;

        cin >> n;
    }

    return 0;
}

// 0 200 400 600 800 1000 1200 1400
// 1422 1400 1200 1000 800 600 400 200 0