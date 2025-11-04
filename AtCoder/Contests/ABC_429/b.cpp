#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    vector<int> A;
    int soma=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
        soma+=a;
    }
    int ai = soma-m;

    bool possivel = false;
    for(auto num : A)
    {
        if(ai == num) possivel = true;
    }

    if(possivel) cout << "Yes" << endl;
    else cout <<  "No" << endl;

    return 0;
}