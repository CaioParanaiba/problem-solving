#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};

void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j,int n){

    for(int k=0;k<4;k++){
        int ii = i + di[k];
        int jj = j + dj[k];

        if(ii>=0 && ii<2 && jj >=0 && jj<n){
            if(grid[ii][jj]=='>') jj++;
            else jj--;

            if(!vis[ii][jj]){
                vis[ii][jj]=true;
                dfs(grid,vis,ii,jj,n);
            }
        }
    }
    
}

void solve(){

    int n;
    cin >> n;
    
    vector<vector<char>>  grid(2,vector<char>(n));
    vector<vector<bool>> vis(2,vector<bool>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
            vis[i][j]=0;
        }
    }

    vis[0][0]=true;
    dfs(grid,vis,0,0,n);

    cout << (vis[1][n-1] ? "YES\n" : "NO\n");

    
}

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}