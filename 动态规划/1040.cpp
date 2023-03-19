#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2000;
string S;//A存序列，dp[i]存以i为结尾的连续序列的最大和
int dp[maxn][maxn];
int main()
{
    getline(cin,S,'\n');

    int len=S.size(),ans=1;
    memset(dp,0,sizeof(dp));
   for(int i = 0;i<len;++i){
       dp[i][i] =1 ;
       if(i<len-1){
           if(S[i] == S[i+1]){
               dp[i][i+1] = 1;
               ans = 2;
           }
       }
   }
   for(int L = 2;L<=len;++L){ // 长度枚举
       for(int i = 0;i+L-1<len;++i){ //左端点枚举
           int j = i+L-1;
           if(S[i] == S[j] &&dp[i+1][j-1]){
               dp[i][j] = 1;
               ans = max(ans,L);
           }
       }
   }
    cout<<ans<<endl;
}
