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
struct Edge{
    int v;
    int distance;
    int Time;
};
map<pair<int,int>,int>TimeMap;
vector<Edge>f[510];
vector<int>DistanceAns;
vector<int>TimeAns;
vector<int>DisPre[510];
vector<int>TimePre[510];
int minnDistance,minnTime;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>DisQ;
bool operator < (pair<int,int> &a,pair<int,int> &b){
    return  a.first>b.first;
}
int sx,tx;

void DjstlaDistance(){
    vector<int>dis(n+1,1e8);
    vector<int>vis(n+1,0);
    DisQ.push({0,sx});
    dis[sx] = 0;
    while(!DisQ.empty()){
        int u = DisQ.top().second;DisQ.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(Edge e:f[u]){
            int v = e.v, w = e.distance;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                DisPre[v].clear();
                DisPre[v].push_back(u);
                DisQ.push({dis[v],v});
            }else if(dis[v] == dis[u] + w){
                DisPre[v].push_back(u);
            }
        }
    }
    minnDistance = dis[tx];
}
void DjstlaTime(){
    vector<int>dis(n+1,1e8);
    vector<int>vis(n+1,0);
    while(!DisQ.empty()) DisQ.pop();

    DisQ.push({0,sx});
    dis[sx] = 0;

    while(!DisQ.empty()){
        int u = DisQ.top().second;DisQ.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(Edge e:f[u]){
            int v = e.v, w = e.Time;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                TimePre[v].clear();
                TimePre[v].push_back(u);
                DisQ.push({dis[v],v});
            }else if(dis[v] == dis[u] + w){
                TimePre[v].push_back(u);
            }
        }
    }
    minnTime = dis[tx];
}

int minSum = 1e8;
void dfsDistance(int x,int sum,vector<int>ans){

    if(x == sx) {
        if(minSum > sum){
            minSum = sum;
            DistanceAns = ans;
        }
        return;
    }
    for(int v:DisPre[x]){
        ans.emplace_back(v);
        dfsDistance(v,sum + TimeMap[{x,v}],ans);
        ans.pop_back();
    }
}
int minSize = 1e8;
void dfsTime(int x,int sum,vector<int>ans){

    if(x == sx) {
        if(TimeAns.size() == 0){
            TimeAns = ans;
        }else if(ans.size()<TimeAns.size()){
            TimeAns = ans;
        }
        return;
    }
    for(int v:TimePre[x]){

        ans.emplace_back(v);
        dfsTime(v,sum + 1,ans);
        ans.pop_back();
    }
}
int main(){
    n = read();m =read();

    for(int i = 0;i<m;++i){
        int u =read(),v = read(),sym = read(),dis = read(),times = read();
        Edge e;
        e.v = v;e.distance = dis;e.Time = times;
        f[u].emplace_back(e);
        TimeMap[{u,v}] = times;
        if(!sym) {
            e.v = u;
            f[v].emplace_back(e);
            TimeMap[{v,u}] = times;
        }
    }
    sx = read(),tx = read();
    DjstlaDistance();
    vector<int>ans;
    ans.push_back(tx);
    dfsDistance(tx,0,ans);

    DjstlaTime();
    ans.clear();
    ans.emplace_back(tx);
    minSum = 1e9;
    dfsTime(tx,1,ans);
    int sym = 0;
    if(DistanceAns.size() == 0||TimeAns.size() == 0) { while (1);}
    if(DistanceAns.size() == TimeAns.size()){
        int index = 0;
        for(int i = 0;i<DistanceAns.size();++i){
            if(DistanceAns[i] == TimeAns[i]) ++index;
            else break;
        }
        if(index == DistanceAns.size()){
            cout<<"Distance = "<<minnDistance<<"; Time = "<<minnTime<<": ";
            reverse(DistanceAns.begin(),DistanceAns.end());
            cout<<DistanceAns[0];
            for(int i = 1;i<DistanceAns.size();++i)
                cout<<" -> "<<DistanceAns[i];
            sym = 1;
        }
    }
    if(!sym){

        reverse(DistanceAns.begin(),DistanceAns.end());
        reverse(TimeAns.begin(),TimeAns.end());
        cout<<"Distance = "<<minnDistance<<": ";
        cout<<DistanceAns[0];
        for(int i = 1;i<DistanceAns.size();++i)
            cout<<" -> "<<DistanceAns[i];
        cout<<endl;
        cout<<"Time = "<<minnTime<<": ";
        cout<<TimeAns[0];
        for(int i = 1;i<TimeAns.size();++i)
            cout<<" -> "<<TimeAns[i];
    }
    return 0;
}