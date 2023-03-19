//
// Created by Dell on 2022-03-04.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace  std;
struct node{
    int u,v,w,first,next;
}e[10010];
int m1 = 0;

void add(int u,int v,int w){
    m1++;
    e[m1].u = u;e[m1].v = v;e[m1].w = w;
    e[m1].next = e[u].first;e[u].first = m1;

}
int c,n,sp,m;
vector<int>f;
vector<int>ans;
int minnRoad = 1e8;
int maxnBike = -1e8;
int maxNeedBike = -1e8;
//void bfs(vector<int> Path){
//    queue<int>q;
//    vector<int>vis(n+10,0);
//    vis[0] = 1;
//    q.push(0);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = e[u].first;i;i=e[i].next){
//            int v = e[i].v,w=e[i].w;
//
//        }
//    }
//}

vector<int>vis;
void dfs(int x,vector<int> Path,int temAns,int temBike,int maxneedBy){
    if(maxneedBy > temBike){
        maxneedBy = temBike;
    }
    if(x == sp){
        if(minnRoad > temAns){
            ans = Path;
            minnRoad = temAns;
            maxnBike = temBike;
            maxNeedBike = maxneedBy;
        }else if(minnRoad == temAns){
            if(maxNeedBike < maxneedBy){
                ans = Path;
                maxnBike = temBike;
                maxNeedBike = maxneedBy;
            }else if(maxNeedBike == maxneedBy){
                if(maxnBike>temBike){
                    ans = Path;
                    maxnBike = temBike;
                }
            }
        }
        return;
    }

    for(int i = e[x].first;i;i = e[i].next){
        int v = e[i].v,  w = e[i].w;
        if(vis[v] == 1) continue;

        vis[v] = 1;
        Path.push_back(v);
        dfs(v,Path,temAns+w,temBike+ (f[v]-c/2),maxneedBy);
        Path.pop_back();
        vis[v] = 0;
    }
    return;
}
int main(){
    cin>>c>>n>>sp>>m;
    f.push_back(0);
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        f.push_back(tem);
    }
    vis.assign(n+10,0);
    for(int i = 0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    vis[0] = 1;
    vector<int>temV;
    temV.push_back(0);
    dfs(0,temV,0,0,1e8);
    cout<<((maxNeedBike>=0)?0:abs(maxNeedBike))<<" 0";
    for(int i = 1;i<ans.size();++i){
        cout<<"->"<<ans[i];
    }
    maxnBike += abs(maxNeedBike);

    cout<<" "<<((maxnBike<=0)?0:maxnBike);
    return 0;
}