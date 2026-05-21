#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int acharmex(int L,int R,int n,vector<int>& a) {
    vector<int> freq(n + 1, 0);
    for(int i = L; i <= R; i++) {
        if(a[i] <= n) freq[a[i]]++;
    }
    int mex = 0;
    while(freq[mex] > 0) mex++;
    return mex;
}

void solve() {
    int n;
    cin >> n;
    int tam = 2 * n;
    vector<int> a(tam);
    
    int p1 = -1, p2 = -1;

    for (int i = 0; i < tam; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }

    int max_mex = 1;
    int L, R;

    L =p1; 
    R =p1;
    while (L - 1 >= 0 && R + 1 < tam && a[L - 1] == a[R + 1]) {
        L--;
        R++;
    }
    max_mex = max(max_mex, acharmex(L, R, n, a));

    L = p2; 
    R = p2;
    while (L - 1 >= 0 && R + 1 < tam && a[L - 1] == a[R + 1]) {
        L--;
        R++;
    }
    max_mex = max(max_mex, acharmex(L, R, n, a));

    int soma = p1 + p2;
    if (soma % 2 == 0) {
        L = soma / 2;
        R = soma / 2;
    } else {
        L = soma / 2;
        R = (soma / 2) + 1;
    }

    if (a[L] ==a[R]) {
        while (L - 1 >= 0 && R + 1 < tam && a[L - 1] == a[R + 1]) {
            L--;
            R++;
        }
        if ((L <= p1 && p1 <= R) || (L <= p2 && p2 <= R)) {
            max_mex = max(max_mex, acharmex(L, R, n, a));
        }
    }
    cout << max_mex << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}