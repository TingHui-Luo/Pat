//
// Created by Dell on 2022-03-16.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n,m,s,d;
int m1;

vector<int> cost(510,5000);
vector<int>pre(550);
struct node{
    int u,v,w1,w2,next,first;

}e[100000];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>q;
bool operator < (pair<int,int> &a,pair<int,int> &b){
    return  a.first>b.first;
}


void add(int u,int v,int w1,int w2) {
    ++m1;
    e[m1].u = u;
    e[m1].w1 = w1;
    e[m1].v = v;
    e[m1].w2 = w2;
    e[m1].next = e[u].first;
    e[u].first = m1;
}

int minnCost = 1e8,minnPath = 1e8;
vector<int>Path;

void djstala(int x){
    vector<int>vis(n+1,0);
    vector<int>dis(n+1,1e8);

    q.push({0,x});
    dis[x] =0;
    cost[x] = 0;
    while(!q.empty()){
        int u = q.top().second;
//        cout<<u<<endl;
        q.pop();
        if(vis[u] == 1) continue;
        vis[u] = 1;

        for(int i = e[u].first;i;i= e[i].next){
            int v = e[i].v,w=e[i].w1;
//            cout<<v;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                cost[v] = cost[u] + e[i].w2;
                pre[v]=u;
                q.push({dis[v],v});
            } else if(dis[v] == dis[u] + w){
                if(cost[v]> cost[u] + e[i].w2){
                    cost[v] = cost[u] + e[i].w2;
                    pre[v]=u;
                }
            }
        }
    }
    minnPath = dis[d];
}
void dfs(int v)
{
    if(v==s)
    {
        Path.push_back(v);
        return;
    }
    dfs(pre[v]);
    Path.push_back(v);
}

int main(){
    cin>>n>>m>>s>>d;

    for(int i = 0;i<m;++i){
        int u,v,w1,w2;
        cin>>u>>v>>w1>>w2;
        add(u,v,w1,w2);
        add(v,u,w1,w2);

    }
    djstala(s);
    int x = d;
    dfs(x);
    for(int i:Path){
        cout<<i<<" ";
    }
    cout<<minnPath<<" "<<cost[d];
    return 0;
}
