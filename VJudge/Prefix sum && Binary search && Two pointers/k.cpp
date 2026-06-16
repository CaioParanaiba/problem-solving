#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while((cin >> n)){
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        int k;cin >> k;

        sort(a.begin(),a.end());

        int i=0,j=n-1;
        
        int b1,b2,diff=1e9;

        while(i<j){
            if(a[i]+a[j]==k){
                if((a[j]-a[i])<diff){
                    diff=a[j]-a[i];
                    b1=a[i];
                    b2=a[j];
                }
                i++;j--;
                
            }
            else if(a[i]+a[j]<k) i++;
            else j--;
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",b1,b2);

        //cin.ignore();
    }   
}