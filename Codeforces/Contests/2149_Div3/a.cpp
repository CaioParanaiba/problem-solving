#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int a[n],op=0,num_neg=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]==0) op++;
            else if(a[j]<0) num_neg++;
        }

        if(num_neg%2!=0) op = op + 2;

        cout << op << endl;
    }


    return 0;
}