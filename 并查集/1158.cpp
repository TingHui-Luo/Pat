

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
vector<int>f[10000];
map<pair<int,int>,int>Map;
unordered_map<int,int>father;
int find(int x){
    int a = x;
    while(x!=father[x]){
        x = father[x];
    }
    while(a!=father[x]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
bool cmp(vector<int> &a,vector<int>&b){
    return a[0]<b[0];
}
void Union(int x,int y){
    x = find(x),y = find(y);
    if (x!=y){
        father[x] = y;
    }
}
int main(){
    int threshold;
    threshold = read(),n = read(),m = read();
    for(int i = 0;i<m;++i){
        int u = read(),v = read(),w = read();
        Map[{u,v}] += w;

    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if(Map[{i,j}] ==0||i == j||Map[{i,j}]>5) continue;
            f[i].emplace_back(j);
        }
    }
    vector<int>ans;
    for(int i = 1;i<=n;++i){
        if(f[i].size()<=threshold) continue;
        int num = 0;
        for(int v:f[i]){
            if(Map[{v,i}]) ++num;
        }
        if(num*10<=f[i].size()*2) {
            ans.emplace_back(i);
        }
    }
    for(int u:ans){
        father[u] = u;
    }
    for(int u:ans){
        for(int v:ans){
            if(u==v) continue;
            if(Map[{u,v}] && Map[{v,u}]){
                Union(u,v);
            }
        }
    }
    unordered_map<int,vector<int>>findAns;


    for(int u:ans){
        findAns[find(u)].emplace_back(u);
    }
    vector<vector<int>>anss;
    for(auto c:findAns){
        anss.emplace_back(c.second);
    }
    sort(anss.begin(),anss.end(),cmp);
    if(anss.size()){

        for(vector<int> aa:anss){
            sort(aa.begin(),aa.end());
            printf("%d",aa[0]);
            for(int i = 1;i<aa.size();++i)
                printf(" %d",aa[i]);
            printf("\n");
        }
    }else{
        printf("None\n");
    }
    return 0;
}

