#include <bits/stdc++.h>
using namespace std;

int dp[105][1005]; 
int q[105];

int main() {
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> q[i];

    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c <= d; c++) {
            
            int compro = (c>=q[i]) ? dp[i+2][c-q[i]]+1 : 0;
            int naocompro = dp[i+1][c];

            dp[i][c]=max(compro,naocompro);
        }
    }

    cout << dp[0][d] << "\n";

    return 0;
}