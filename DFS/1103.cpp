#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}
int n,k,m;
map<pair<int,int>,int>Map1;
//map<string ,int>Map;
vector<int>ans;
int maxSum = 0;

bool check(vector<int>tem){
    for(int i = 0;i<min(tem.size(),ans.size());++i){
        if(tem[i] < ans[i]) return false;
        if(tem[i] > ans[i]) return true;
    }
    return false;
}

int kuaisumi(int a,int b){
    int ans = 1;
    while(b){
        if(b&1) ans *= a;
        b = b>>1;
        a *= a;
    }
    return ans;
}


void dfs(int sum ,int index,vector<int>tem,int temSum){
    if(sum > n || tem.size() > k|| index <=0)return;

    if(sum == n&& tem.size() == k){
        if(temSum>maxSum){
            ans = tem;
            maxSum = temSum;
        }else if(temSum == maxSum){
            if(check(tem)){
                ans = tem;
            }
        }
        return;
    }
    if(maxSum!= 0 && (k-tem.size())*index + temSum < maxSum) return;
    // 神级优化呀

    dfs(sum,index-1,tem,temSum);
    tem.emplace_back(index);
    dfs(sum + Map1[{index,m}],index,tem,temSum+index);
    tem.pop_back();

}
int main()
{
    n = read();k = read();m = read();
    if(k>n){
        cout<<"Impossible";
        return 0;
    }
    for(int i = sqrt(n);i>=1;--i) {
        Map1[{i,m}] = kuaisumi(i,m);
    }

    vector<int>tem;
    dfs(0, sqrt(n),tem,0);
    if(ans.size()){
        printf("%d = %d^%d",n,ans[0],m);
        for(int i = 1;i<ans.size();++i){
            printf(" + %d^%d",ans[i],m);
        }
    }else{
        cout<<"Impossible";
    }
    return 0;
}