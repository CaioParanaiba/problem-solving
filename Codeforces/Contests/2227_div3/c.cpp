#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int somat = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        somat += a[i];
    }

    vector<int> sufix_min(n + 2, 2e18);
    int somap = 0;
    for (int i = n; i >= 1; i--) {
        sufix_min[i] = min(a[i], sufix_min[i+1]);
        somap += sufix_min[i];
    }

    int atuaism = somat - somap;

    vector<int> E(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            E[i] = st.top();
        }
        st.push(i);
    }

    int novosm = 0;
    for (int j = 1; j <= n; j++) {
        if (a[j] <= sufix_min[j+1]) { 
            int Dj = j - E[j];
            novosm = max(novosm, Dj - 1);
        }
    }

    cout << atuaism + novosm << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}