//
// Created by Dell on 2022-03-28.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n,m,k;
struct Edge{
    int v,w;
};
vector<Edge>e[110];
vector<int>f;
vector<int>vis;
int root;
vector<vector<int>>ans;

void dfs(int x,vector<int>temans,int temk){
    if(vis[x]){
        if(temk == k ) ans.push_back(temans);
        return ;
    }
    for(Edge teme:e[x]){
        int i = teme.v;
        temans.push_back(f[i]);
        dfs(i,temans,temk + f[i]);
        temans.pop_back();
    }
}

bool cmp(const vector<int> &a,const vector<int> &b){
    for(int i = 0;i< min(a.size(),b.size());++i){
        if(a[i] == b[i]) continue;
        return a[i]>b[i];
    }
}
int main(){

    cin>>n>>m>>k;
    vis.assign(n+1,1);
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        f.push_back(tem);
    }
    for(int i = 0;i<m;++i){
        int u,num;
        cin>>u>>num;
        vis[u] = 0;
        for(int j = 0;j<num;++j){
            int tem;cin>>tem;
            Edge a;
            a.v = tem;a.w = f[tem];
            e[u].push_back(a);
        }
    }
    vector<int>tem;
    tem.push_back(f[0]);
    dfs(0,tem,f[0]);
    sort(ans.begin(),ans.end(),cmp);
    for(auto a:ans){
        for(int i = 0;i<a.size();++i){
            if(i==a.size()-1) cout<<a[i];
            else cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
