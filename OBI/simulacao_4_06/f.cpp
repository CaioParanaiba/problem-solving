#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<vector<char>> s(n,vector<char>(m));
    vector<vector<int>> st(n,vector<int>(m,1));
    vector<vector<int>> sl(n,vector<int>(m,1));
    pair<int,int> tarta,coel;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
            if(s[i][j]=='P'){
                st[i][j]=2;
            }
            else if(s[i][j]=='F'){
                st[i][j]=0;
            }
            else if(s[i][j]=='A'){
                sl[i][j]=2;
            }
            else if(s[i][j]=='C'){
                sl[i][j]=0;
            }
            else if(s[i][j]=='T') tarta={i,j};
            else if(s[i][j]=='L') coel={i,j};
            else if(s[i][j]=='#'){
                st[i][j]=1e9;
                sl[i][j]=1e9;

            }
        }
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> distc(n, vector<int>(m, 1e9));
    
    int di[4]={1,-1,0,0};
    int dj[4]={0,0,1,-1};

    distc[coel.first][coel.second]=0;
    pq.push({0,coel});
    while(pq.size()){
        auto [wu,ij] = pq.top();
        auto [i,j] = ij;
        pq.pop();
        if(wu>distc[i][j])continue;

        for(int k=0;k<4;k++){
            int ii = i+di[k];
            int jj = j+dj[k];
            if(ii>=0 && ii<n && jj>=0 && jj<m){
                int wv = sl[ii][jj];
                if(distc[i][j]+wv<distc[ii][jj]){
                    distc[ii][jj]=distc[i][j]+wv;
                    pq.push({distc[ii][jj], {ii, jj}});
                }
            }
        }
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq2;
    vector<vector<int>> distt(n, vector<int>(m, 1e9));

    distt[tarta.first][tarta.second]=0;
    pq2.push({0,tarta});
    while(pq2.size()){
        auto [wu,ij] = pq2.top();
        auto [i,j] = ij;
        pq2.pop();
        if(wu>distt[i][j])continue;

        for(int k=0;k<4;k++){
            int ii = i+di[k];
            int jj = j+dj[k];
            if(ii>=0 && ii<n && jj>=0 && jj<m){
                int wv = st[ii][jj];
                if(distt[i][j]+wv<distt[ii][jj]){
                    distt[ii][jj]=distt[i][j]+wv;
                    pq2.push({distt[ii][jj], {ii, jj}});
                }
            }
        }
    }

    int timetarta=1e9,timecoel=1e9;
    for(int i = 0; i < n; i++){
        if(s[i][0] != '#'){
            timetarta= min(timetarta, distt[i][0]);
            timecoel = min(timecoel, distc[i][0]);
        }
        if(s[i][m-1] != '#'){
            timetarta = min(timetarta, distt[i][m-1]);
            timecoel =min(timecoel, distc[i][m-1]);
        }
    }

    for(int i = 0; i < m; i++){
        if(s[0][i] != '#'){
            timetarta=min(timetarta, distt[0][i]);
            timecoel=min(timecoel, distc[0][i]);
        }
        if(s[n-1][i] != '#'){
            timetarta = min(timetarta, distt[n-1][i]);
            timecoel = min(timecoel, distc[n-1][i]);
        }
    }

    if(timetarta == 1e9) timetarta = -1;
    else timetarta += 1;

    if(timecoel == 1e9) timecoel = -1;
    else timecoel += 1;

    cout << timetarta << ' ' << timecoel << "\n";
}