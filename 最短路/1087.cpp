

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
#include <stack>
using namespace std;
typedef long long ll;

inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1;c = getchar();}
    while(c>='0'&&c<='9') { x = x*10+c - '0';c=getchar();}
    return x*y;
}
int n,m,m1;

map<string,int>Map;
string start;
map<string,int>Happy;
struct Edge{
    string v;
    int cost;
};
map<string,vector<Edge> > f;
map<string,vector<string>>pre;
vector<string>cities;
int minCost;
priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>q;
void djstla(){
    map<string,int>vis;
    map<string,int>dis;
    for(string c:cities){
        vis[c] = 0;
        dis[c] = 1e8;
    }
    dis[start] = 0;
    q.push({0,start});
    while(!q.empty()){
        string u = q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(Edge i:f[u]){
            string v = i.v;int w= i.cost;

            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pre[v].clear();
                pre[v].emplace_back(u);

                q.push({dis[v],v});
            }else if(dis[v] == dis[u] + w){
                pre[v].emplace_back(u);
            }
        }
    }
    minCost = dis["ROM"];
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

vector<string>ans;
int routes,maxHappiness = 0;
void bfs(string x,vector<string>Path,int happiness){
    if(x == start){
        ++routes;
        if(maxHappiness < happiness){
            maxHappiness = happiness;
            ans = Path;
        }else if(maxHappiness == happiness && ((happiness/Path.size()) > (maxHappiness/ans.size()))){
            ans = Path;
        }
    }
    for(string v:pre[x]){
        Path.emplace_back(v);
        bfs(v,Path,happiness + Happy[v]);
        Path.pop_back();
    }
}


int main(){
    n = read();m = read();
    cin>>start;
    cities.emplace_back(start);
    for(int i = 0;i<n-1;++i){
        string s;
        cin>>s;
        cities.emplace_back(s);
        Happy[s] = read();
    }
    for(int i = 0;i<m;++i){
        string u,v;
        cin>>u>>v;
        Edge a;
        a.v =v;
        a.cost = read();
        f[u].emplace_back(a);
        a.v = u;
        f[v].emplace_back(a);
    }
    djstla();
    vector<string>tem;
    tem.emplace_back("ROM");
    bfs("ROM",tem,Happy["ROM"]);
    cout<<routes<<" "<<minCost<<" "<<maxHappiness<<" "<<(maxHappiness/(ans.size()-1))<<endl;
    cout<<ans[ans.size()-1];
    for(int i = ans.size()-2;i>=0;--i){
        cout<<"->"<<ans[i];
    }
    return 0;
}
