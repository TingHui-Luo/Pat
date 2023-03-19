//
// Created by Dell on 2022-03-06.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n,m;
int f[110][110];
int ru[110];
vector<int>st;
vector<int>vis(110,0);
vector<int>Height[110];
int maxH= 0;
void bfs(int x){
    queue<int> q;
    q.push(x);
    int height = 1;
    int temsize = 1;

    while(!q.empty()){
        for(int i = 0;i<temsize;++i) {
            int u = q.front();
            q.pop();
            for(int j = 1;j<=n;++j){
                if(f[u][j]== 1){
                    Height[height+1].push_back(j);
                    q.push(j);
                    vis[u] = 1;
                }
            }
        }
        ++height;
        maxH = max(height,maxH);
        temsize = q.size();
    }
}

int main(){
    cin>>n>>m;

    for(int i = 0;i<m;++i){
        int id,k;
        cin>>id>>k;
        for(int j = 0;j<k;++j){
            int tem;
            cin>>tem;

            f[id][tem] = 1;
            ++ru[tem];
        }
    }

    for(int i = 1;i<=n;++i){

        if(ru[i] == 0) st.push_back(i);
    }
    for(int tem:st){
        Height[1].push_back(tem);
        bfs(tem);
    }
    for(int i = 1;i<maxH;++i){
        int temans = 0;
        for(int tem:Height[i]){
            if(vis[tem] == 1) ++temans;
        }
        if (i!=maxH-1)cout<<Height[i].size()-temans<<" ";
        else cout<<Height[i].size()-temans;
    }
    return 0;
}
