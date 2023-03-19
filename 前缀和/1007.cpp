//
// Created by Dell on 2022-03-06.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int>f;
int main(){
    int k;
    cin>>k;
    int temf = 0;
    for(int i = 0;i<k;++i){
       int tem;
       cin>>tem;
       if(tem<0) ++temf;
       f.push_back(tem);
    }
    if(temf == k){
        cout<<0<<" "<<f[0]<<" "<<f[k-1];
        return 0;
    }
    vector<int>dp(k+10,0);

    dp[0] = f[0];

    for(int i = 1;i<k;++i){
        dp[i] = dp[i-1] + f[i];
    }

    int maxn = 0;
    int ans1,ans2,ans=-1e8;
    for(int i = 0;i<k;++i){
        for(int j = i;j<k;++j){
            if(ans < (dp[j]-dp[i]+f[i])){
                ans = (dp[j]-dp[i]+f[i]);
                ans1 = i;ans2 = j;
            }
        }
    }

    cout<<ans<<" "<<f[ans1]<<" "<<f[ans2];


    return 0;
}