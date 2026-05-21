#include <bits/stdc++.h>

using namespace std;

int main(){
    int d,time;
    cin >> d >> time;

    vector<int> sum(d),min(d),max(d);

    int at_sum=0,sum_max=0;

    for(int i=0;i<d;i++){
        cin >> min[i] >> max[i];
        at_sum+=min[i];
        sum_max+=max[i];
        sum[i]=min[i];
    }

    if(at_sum>time || sum_max<time) cout << "NO\n";
    else{
        int i=-1;
        while(at_sum<time){
            i++;
            int dif = max[i]-min[i];
            sum[i]+=dif;
            at_sum+=dif;
        }

        if(at_sum>time){
            sum[i]-=(at_sum-time);
        }

        cout << "YES\n";

        for(int i=0;i<d;i++){
            cout << sum[i] << (i==(d-1) ? "\n" : " ");
        }
    }
}