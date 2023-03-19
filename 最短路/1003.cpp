//
// Created by Dell on 2022-03-06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
typedef  long  long ll;


struct node{
    int u,v,w,first,next;
}e[10010];
int m1,n,m,c0,c1,ansr=0,ansm=0;
vector<int>f;
vector<int> pre[510];

void add(int u,int v,int w){
    m1++;
    e[m1].u =u ;e[m1].v =v;e[m1].w=w;
    e[m1].next = e[u].first;e[u].first = m1;
}


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>q;
bool operator < (pair<int,int> &a,pair<int,int> &b){
    return  a.first>b.first;
}
void Djstala(int x){
    vector<int>vis(n+1,0);
    vector<int>dis(n+1,1e8);
    dis[x] = 0;
    q.push({0,x});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = e[u].first;i;i=e[i].next){
            int v = e[i].v,w= e[i].w;
            if(dis[v] > dis[u] +w){
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
                pre[v].clear();
                pre[v].emplace_back(u);
            }else if(dis[v] == dis[u] + w){
                pre[v].emplace_back(u);
            }
        }
    }
}


void dfs(int x,int temans){
    if(x == c0){
        ++ansr;
        ansm = max(temans,ansm);
        return;
    }
    for(int v:pre[x]){
        dfs(v,temans+f[v]);
    }
}


int main(){
    cin>>n>>m>>c0>>c1;
    f.assign(n+1,0);
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        f[i]=tem ;
    }

    for( int i = 0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    Djstala(c0);
    dfs(c1,f[c1]);
    cout<<ansr<<" "<<ansm;
    return 0;
}