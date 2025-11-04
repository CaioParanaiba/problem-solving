#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> A;
    A.push_back(0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int numtrip = 0;

    for(int i=1;i<(n-1);i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                cout << "Tripleto: " << i << " " << j << " " << k;
                cout << " Valor do Tripleto: " << A[i] << " " << A[j] << " " << A[k] << endl;
                if((A[i]==A[j] && A[i]!=A[k]) || (A[k]==A[j] && A[i]!=A[k]) || (A[k]==A[i] && A[i]!=A[j]))
                {
                    numtrip++;
                    cout <<  "Valido" << endl;
                }
            }
        }
    }
    cout << numtrip << endl;

    return 0;
}