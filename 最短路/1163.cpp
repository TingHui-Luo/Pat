

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
struct Edge{
    int w;
    int v;
};
vector<Edge>e[10000];

bool djstla(vector<int>f){


    vector<int>dis(n+1,1e8);
    vector<int>vis(n+1,0);

    dis[f[0]] = 0;
    for(int i = 0;i<n;++i){
        int minn = 1e8,index = -1;
        for(int j = 1;j<=n;++j){
            if(!vis[j]&&dis[j]<minn){
                minn = dis[j];
            }
        }
        if(dis[f[i]] == minn) index = f[i];
        else return false;
        vis[index] = 1;
        for(Edge v:e[index]){
            if(!vis[v.v]&&dis[v.v]>dis[index]+v.w){
                dis[v.v] = dis[index] + v.w;
            }
        }
    }
    return true;
}
int main(){

    n = read(); m = read();
    for(int i = 0;i<m;++i){
        int u = read(), v= read(),w =read();
        Edge a;
        a.v = v;a.w= w;
        e[u].emplace_back(a);
        a.v = u;
        e[v].emplace_back(a);
    }
    int k = read();
    for(int i = 0;i<k;++i){
        vector<int>f;
        f.clear();
        unordered_map<int,int>Map;

        for(int j = 0;j<n;++j){
            int tem = read();
            f.emplace_back(tem);
        }
        if(djstla(f)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

