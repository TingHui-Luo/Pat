//
// Created by Dell on 2022-04-02.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c = getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c- '0';c= getchar();}
    return x*y;
}
int m1;
struct node{
    int u,v,w,next,first;
}e[20010];

void add(int u,int v,int w){
    ++m1;
    e[m1].u = u;e[m1].v = v;e[m1].w = w;
    e[m1].next = e[u].first;e[u].first = m1;
}

int zhuan(string s){
    int ans = 0;
    for(char c:s){
        ans = ans * 10 + (c - '0');
    }
    return ans;
}

int n,m,k,range;
struct station{
    double all;
    double average;
    double minn;
    int index;
};

vector<station>ans;

bool cmp(const station &a,const station &b){
    if(a.minn!=b.minn) return a.minn>b.minn;
    if(a.average!=b.average) return a.average<b.average;
    return a.index<b.index;
}

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;


void djstla(int x){
    while(!q.empty()) q.pop();
    vector<int> dis(n+m+1,1e8);
    vector<int> vis(n+m+1,0);
    dis[x] = 0;
    q.push({0,x});
    while(!q.empty()){
        int u = q.top().second;q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;

        for(int i =e[u].first;i;i=e[i].next){

            int v = e[i].v,w=e[i].w;
            if(dis[v] > dis[u] +w){
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }

    }
    double all = 0.0;
    int minn = 1e8;
    int sym = 1;
    for(int i = 1;i<=n;++i){
        if(dis[i]>range) {sym = 0;break;}

        minn = min(minn,dis[i]);
        all += dis[i];
    }


    if(sym == 0) return;
    station a;
    a.index = x-n;
    a.minn = minn;
    a.all = all;
    a.average = a.all/double (n);
    ans.push_back(a);
}
int main(){
    cin>>n>>k>>m>>range;
    for(int i = 0;i<m;++i){
        string u,v;
        int a,b,w;
        cin>>u>>v>>w;
        if(u[0] == 'G'){
            a = n + zhuan(u.substr(1));
        }else{
            a = zhuan(u);
        }
        if(v[0] == 'G'){
            b = n + zhuan(v.substr(1));
        }else{
            b = zhuan(v);
        }
        add(a,b,w);
        add(b,a,w);
    }
    for(int j = 1;j<=k;++j){
        djstla(n+j);
    }
    sort(ans.begin(),ans.end(),cmp);
    if(ans.empty()) {
        cout<<"No Solution";
    }else{
        cout<<"G"<<ans[0].index<<endl;
        ans[0].average += 0.01;
        printf("%.1f %.1f",ans[0].minn,ans[0].average);
    }
    return 0;
}