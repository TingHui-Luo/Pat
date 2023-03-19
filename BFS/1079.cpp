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

inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}

int n;
double price ,r,ans;
map<int,double>Map;
vector<int>E[100010];
vector<int>f;
void bfs(){

    vector<int>vis(n+1,0);
    vector<double>dis(n+1,0);
    vis[0] = 1;
    queue<int>q;
    q.push(0);
    dis[0] = price;
    int temsize = 1;
    while(!q.empty()){
        for(int i = 0;i<temsize;++i){
            int u = q.front();q.pop();
            for(int v:E[u]){
                if(vis[v]) continue;
                vis[v] = 1;
                dis[v] = dis[u]*(1.0+r/100.0);
                q.push(v);
            }
        }
        temsize = q.size();
    }
    for(int i:f){
        ans += Map[i] *dis[i];
    }
}

int main(){
    n =read();
    cin>>price>>r;

    for(int i= 0;i<n;++i){
        int num =read();
        if(num == 0){
            int val = read();
            Map[i] = val;
            f.emplace_back(i);
        }
        else {
            for (int j = 0; j < num; ++j) {
                int v = read();
                E[i].emplace_back(v);
            }
        }
    }
    bfs();
    printf("%.1f",ans);

    return 0;
}