

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}
int n,m;
vector<int>f;
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }
    sort(f.begin(),f.end());
    vector<int>dp(n+1,0);
    dp[0] = f[0];

    for(int i = 1;i<n;++i){
        dp[i] = dp[i-1] + f[i];
    }
    if(n&1){

        cout<<"1 "<<dp[n-1] - 2*dp[(n-1)/2-1];
    }else{
        cout<<"0 "<<dp[n-1] - 2*dp[n/2 - 1];
    }
    return 0;
}
