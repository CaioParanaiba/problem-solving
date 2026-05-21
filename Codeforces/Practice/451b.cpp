#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> ra=a;

    sort(ra.begin(),ra.end());

    int inicio=-1,fim=-1;

    bool possivel = true;

    for(int i=0;i<n;i++){
        if(a[i]!=ra[i]){
            if(inicio==-1) inicio=i;
            else fim=i;
        }
    }

    if(a==ra) {
        inicio++;
        fim++;
    }
    else{
        for(int i=inicio,f=fim;i<=f;i++,f--){
            swap(a[i],a[f]);
        }
    }

    if(a!=ra) possivel=false;
    

    if(possivel) cout << "yes\n" << inicio+1 << ' ' << fim+1 << '\n';
    else cout << "no\n";
}