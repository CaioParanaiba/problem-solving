#include <bits/stdc++.h>

using namespace std;

int build(vector<int>&seg,vector<int>&v,int l,int r,int p){
    if(l==r) return seg[p]=v[l];

    int m = l+((r-l)>>1);

    return seg[p]=build(seg,v,l,m,p<<1)+build(seg,v,m+1,r,(p<<1)|1);
}

int up(vector<int>&seg,vector<int>&v,int l,int r,int p, int i){
    if(l>i || r<i) return seg[p];
    if(l>=i && r<=i) return seg[p]=v[l]=v[l]^1;

    int m = l + ((r-l)>>1);

    return seg[p]=up(seg,v,l,m,p<<1,i)+up(seg,v,m+1,r,(p<<1)|1,i);
}

int query(vector<int>&seg,vector<int>&v,int l,int r,int p,int x){
    if(l==r) return l;
    int m = l + ((r-l)>>1);
    if(seg[p<<1]>x) return query(seg,v,l,m,p<<1,x);
    return query(seg,v,m+1,r,(p<<1)|1,x-seg[p<<1]);
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> seg(n*4);

    for(int i=0;i<n;i++) cin >> v[i];

    build(seg,v,0,n-1,1);

    while(q--){
        int i,x;
        cin >> i >> x;
        if(i&1) up(seg,v,0,n-1,1,x);
        else cout << query(seg,v,0,n-1,1,x) << endl;
    }
    

}