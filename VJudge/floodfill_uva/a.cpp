#include <bits/stdc++.h>

using namespace std;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int mat[26][26];
bool vis[26][26];

void dfs(int n,int i,int j){
    vis[i][j]=true;

    for(int k=0;k<8;k++){
        int ii=i+di[k];
        int jj=j+dj[k];

        if(ii>=0 && ii<n && jj>=0 && jj<n && mat[ii][jj]==1 && !vis[ii][jj]) dfs(n,ii,jj);
    }
}

int main(){
    int n;
    int count = 1;
    while((cin>>n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c;
                cin >> c;
                mat[i][j] = c-'0';
                vis[i][j]=false;
            }
        }

        int war = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && !vis[i][j]){
                    war++;
                    dfs(n,i,j);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",count,war);
        count++;
    }
}