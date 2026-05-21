#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<pair<int,double>> pd(n+1);
        
        double melhor_futuro = 0;

        vector<pair<int,int>> tarefa(n);

        for(int i=0;i<n;i++) cin >> tarefa[i].first >> tarefa[i].second;

        for(int i=n-1;i>=0;i--){
            double ganho_pular = melhor_futuro;
            double ganho_fazer = tarefa[i].first + (1-tarefa[i].second/100.0)*melhor_futuro;

            melhor_futuro = max(ganho_fazer,ganho_pular);
        }

        cout << fixed << setprecision(10) <<melhor_futuro << '\n';
    }
}