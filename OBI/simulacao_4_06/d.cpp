#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    int soma_total=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        soma_total+=a[i];
        }
        vector<int> lastup(n+1,0);

        int ultimo_valor=0;
        int ultima_vez=-1;

        for(int k=1;k<=q;k++){
            int op;
            cin >> op;
            if(op==1){
                int i,x;
                cin >> i >>x;
                int valor_at;
                if(lastup[i]<ultima_vez){
                    valor_at=ultimo_valor;
                }
                else valor_at=a[i];

                soma_total+=x-valor_at;
                a[i]=x;
                lastup[i]= k;
            }
            else{
                int valor;
                cin >> valor;
                ultima_vez=k;
                ultimo_valor=valor;
                soma_total=n*valor;
            }

            cout << soma_total << '\n';
        }

    }