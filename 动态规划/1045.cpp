//
// Created by Dell on 2022-03-22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int,int>Map;
int n,m;
vector<int>f;
vector<int>dp(110000);
int main(){
    cin>>n>>m;

    for(int i= 1;i<=m;++i){
        int tem;
        cin>>tem;
        Map[tem] = i;
    }
    cin>>m;

    int num = 0;
    for(int i = 0;i<m;++i){
        int tem;cin>>tem;
        if(Map.find(tem) != Map.end()) {
            f.push_back(Map[tem]);
            ++num;
        }
    }
    int ans = 0;

    for(int i = 0;i<num;++i){
        dp[i] =1;
        for(int j = 0;j<i;++j){
            if(f[i]>=f[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }

        ans = max(ans,dp[i]);

    }
    cout<<ans;
    return 0;


}