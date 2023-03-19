

//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
vector<ll>f;
ll n,p;

inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1;c = getchar();}
    while(c>='0'&&c<='9') { x = x*10+c - '0';c=getchar();}
    return x*y;
}

ll find(ll x,ll r){
    ll minn = int(double (x)/ double (p) + 0.999999);
    ll left = 0,right =r-1 ;
    while(left<=right){
        ll mid = left + (right - left)/2;
        if(f[mid]<minn){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return left;
}
int main(){
    n = read();p =read();
    for(int i = 0;i<n;++i){
        ll tem =read();
        f.emplace_back(tem);
    }
    sort(f.begin(),f.end());
    ll maxn = 0,ans;
    for(int i = 0;i<f.size();++i){
        ll left = find(f[i],i);

        if(maxn < (i - left+1)){
            maxn = (i - left + 1);

        }
    }
    cout<<maxn;
    return 0;
}
