
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
vector<int>degree;
map<int,int>vis;
vector<int>Edge[510];
int count1 = 0;
void dfs(int x){
    vis[x] = 1;
    ++count1;
    for(int v:Edge[x]){
        if(vis[v] == 1) continue;
        dfs(v);
    }
}
int main(){
    n = read();m = read();

    degree.assign(n+1,0);
    for(int i = 0;i<m;++i){
        int a = read(), b = read();
        degree[a] ++;
        degree[b] ++;
        Edge[a] .emplace_back(b);
        Edge[b].emplace_back(a);
    }
    dfs(1);
    int evenNumber = 0;
    for(int i = 1;i<=n;++i){

        if(degree[i] %2 == 0) ++evenNumber;
    }
    cout<<degree[1];
    for(int i = 2;i<=n;++i){
        cout<<" "<<degree[i];
    }
    cout<<endl;
    if(count1 == n&&evenNumber == n) cout<<"Eulerian";
    else if(count1 == n&&evenNumber == n -2) cout<<"Semi-Eulerian";
    else{
        cout<<"Non-Eulerian";
    }
    return 0;

}