    #include <bits/stdc++.h>

    using namespace std;

    #define int long long
    #define endl '\n'

    signed main(){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        int soma_atual=0;
        int id=0;
        for(int i=0;i<k;i++) soma_atual+=a[i];

        int melhor=soma_atual;
        for(int i=k;i<n;i++){
            soma_atual=soma_atual+a[i]-a[i-k];

            if(melhor>soma_atual){
                melhor=soma_atual;
                id=i-k+1;
            }
        }

        cout << id+1 << endl;

    }