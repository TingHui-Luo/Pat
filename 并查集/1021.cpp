//
// Created by Dell on 2022-03-13.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>>e(100010);
vector<int>ans;
vector<int>vis;
vector<int>father(100100);
map<int,int>Map;
int maxDeep = 0,temMaxDeep= 0;
int n;

void dfs(int x,int deep){
    temMaxDeep = max(temMaxDeep,deep);
    for(int v:e[x]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v,deep+1);
        vis[v] = 0;
    }
}

int find(int x){
    while(x!=father[x]){
        x = father[x];
    }
    return x;
}

void add(int x,int y){
    x = find(x),y = find(y);
    if(x!=y){
        father[x] = y;
    }
}
int main(){
    cin>>n;
    for(int i =1;i<=n;++i){
        father[i] = i;
    }
    int temn = 0;
    for(int i = 0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
        add(a,b);
    }
    int maxNumer = 0;
    for(int i=1;i<=n;++i){
        if(Map.find(find(i)) == Map.end()){
            Map[find(i)] +=1;
            maxNumer += 1;
        }
    }

    if(maxNumer!=1){
        cout<<"Error: "<<maxNumer<<" components"<<endl;
        return 0;
    }
    for(int i = 1;i<=n;++i){
        vis.assign(n+10,0);
        temMaxDeep = 0;
        vis[i] = 1;
        dfs(i,1);
        if(maxDeep < temMaxDeep){
            ans.clear();
            ans.push_back(i);
            maxDeep = temMaxDeep;
        }else if(maxDeep == temMaxDeep){
            ans.push_back(i);
        }
//        cout<<temMaxDeep<<endl;
    }
    sort(ans.begin(),ans.end());
    for(int i:ans){
        cout<<i<<endl;
    }
    return 0;
}