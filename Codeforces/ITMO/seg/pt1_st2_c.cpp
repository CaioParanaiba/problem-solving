#include <bits/stdc++.h>

using namespace std;


int build(vector<int>&seg,vector<int>&a,int l,int r,int p){
    if(l==r) return seg[p]=a[l];

    int m = l + (r-l)/2;

    return seg[p]=max(build(seg,a,l,m,p<<1),build(seg,a,m+1,r,(p<<1)|1));
}

int query(vector<int>&seg,vector<int>&a,int l, int r, int p,int x){
    if(l==r) return l;

    int m = l + (r-l)/2;

    if(seg[p*2]>=x) return query(seg,a,l,m,p*2,x);
    return query(seg,a,m+1,r,p*2+1,x);
}

int up(vector<int>&seg,vector<int>&a,int l, int r, int p, int i, int v){
    if(l>i || r<i) return seg[p];
    if(l>=i && r<=i) return seg[p]=v;

    int m = l + ( r-l)/2;

    return seg[p]=max(up(seg,a,l,m,p*2,i,v),up(seg,a,m+1,r,p*2+1,i,v));
}

int main(){
    int n,q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> seg(4*n);

    for(int i=0;i<n;i++) cin >> a[i];

    build(seg,a,0,n-1,1);

    while(q--){
        int type;
        cin >> type;
        if(type&1){
            int i,v;
            cin >> i >> v;
            up(seg,a,0,n-1,1,i,v);
        }
        else{
            int x;
            cin >> x;
            if(seg[1]<x)
                cout << -1 << endl;
            else
                cout << query(seg,a,0,n-1,1,x) << endl;
        }

    }
}