#include <bits/stdc++.h>

using namespace std;

char grid[51][51];

int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};

void dfs(int* pt,int i,int j,int n,int m){
    if(grid[i][j]=='G') (*pt)++;
    grid[i][j]='#';

    for(int k=0;k<4;k++){
        int ii=i+di[k];
        int jj=j+dj[k];

        if(ii>=0 && ii<n && jj>=0 && jj<m){
            if(grid[ii][jj]=='T') return;
        }
    }

    for(int k=0;k<4;k++){
        int ii=i+di[k];
        int jj=j+dj[k];

        if(ii>=0 && ii<n && jj>=0 && jj<m){
            if(grid[ii][jj]=='.' || grid[ii][jj]=='G'){
                dfs(pt,ii,jj,n,m);
            }
        }
    }

}

int main(){
    int n,m;
    cin >> m >> n;

    int pt=0;

    int ii,jj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='P') {
                ii=i;
                jj=j;
            }
        }
    }

    dfs(&pt,ii,jj,n,m);

    cout << pt << endl;
}