#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<string> pq;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        pq.push_back(s);
    }

    sort(pq.begin(),pq.end(), [](auto&a,auto&b)
    {
        return a+b < b+a;
    });

    for(auto ii : pq)
    {
        cout << ii;
    }
    cout << endl;

    return 0;
}