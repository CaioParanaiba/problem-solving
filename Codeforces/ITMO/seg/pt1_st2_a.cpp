#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node{
    int sum,pref,suf,seg;
};

Node merge(Node l,Node r){
    Node res;

    res.sum = l.sum + r.sum;
    res.pref = max(l.pref,l.sum+r.pref);
    res.suf = max(r.suf,r.sum+l.suf);
    res.seg = max({r.seg,l.seg,r.pref+l.suf});

    return res;
}

Node build(vector<Node>&s,vector<int>&v,int l,int r,int p){
    if(l==r){
        return s[p]={v[l], max(0LL, v[l]), max(0LL, v[l]), max(0LL, v[l])};
    }

    int m = l + (r-l)/2;
    return s[p]=merge(build(s,v,l,m,p<<1),build(s,v,m+1,r,(p<<1)|1));
}

Node up(vector<Node>&s,vector<int>&v,int l,int r,int p,int i,int x){
    if(l>i || r<i) return s[p];
    if(l==i && r==i) return s[p]={x,max(0LL,x),max(0LL,x),max(0LL,x)};

    int m = l + (r-l)/2;
    return s[p]=merge(up(s,v,l,m,p<<1,i,x),up(s,v,m+1,r,(p<<1)|1,i,x));
}

Node query(vector<Node>&s,vector<int>&v,int l,int r,int p,int i,int j){
    if(l>j || r<i) return {0,0,0,0};
    if(l>=i && r<=j) return s[p];

    int m = l + (r-l)/2;
    return merge(query(s,v,l,m,(p<<1),i,j),query(s,v,m+1,r,(p<<1)|1,i,j));
}

signed main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    vector<Node> s(n*4);

    for(int i=0;i<n;i++) cin >> v[i];

    build(s,v,0,n-1,1);
    cout << s[1].seg << endl;

    while(q--){
        int i,x;
        cin >> i >> x;
        Node a = up(s,v,0,n-1,1,i,x);
        cout << s[1].seg << endl;
    }

}