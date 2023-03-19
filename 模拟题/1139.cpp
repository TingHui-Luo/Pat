

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m;
map<pair<int,int>,int>Map;
map<int,vector<int>>f;
int main(){
    n = read();m =read();
    for(int i = 0;i<m;++i){
        int a = read(),b =read();
        f[a].emplace_back(b);
        f[b].emplace_back(a);
        Map[{a,b}] = 1;
        Map[{b,a}] = 1;
    }
    int k = read();
    for(int i = 0;i<k;++i){
        int a= read(),b=read();
        vector<int>fa,fb;
        fa.clear();fb.clear();
        for(int v:f[a]){
            if(v*a>=0){
                if(v == b) continue;
                fa.emplace_back(v);
            }
        }
        for(int v:f[b]){
            if(v*b>=0){
                if(v == a) continue;
                fb.emplace_back(v);
            }
        }
        vector<pair<int,int>>ans;
        for(int u:fa){
            for(int v:fb){
                if(u == v) continue;
                if(Map[{u,v}]||Map[{v,u}]){
                    ans.emplace_back(abs(u),abs(v));
                }
            }
        }
        cout<<ans.size()<<endl;
        sort(ans.begin(),ans.end());
        for(auto a:ans){
            printf("%04d %04d\n",a.first,a.second);
        }
    }
    return 0;
}

