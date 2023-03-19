//
// Created by Dell on 2022-03-17.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n,threshold;
int m1= 1;
map<int,vector<int>> ansMap;
vector<int> temv;
map<string,int>Map;
map<int,string>Mapint;
vector<vector<int>>f(5010);
map<pair<int,int>,int>edge;
map<int,int>Maphold;
int maxshold = 0;
int maxid,maxhead = 0;
vector<int>father;

int find(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
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
    cin>>n>>threshold;
    father.assign(n+2000,0);
    for(int i = 1;i<=n;++i){
        father[i] = i;
    }
    for(int i = 1;i<=n;++i){

        string a,b;
        int time;
        cin>>a>>b>>time;

        if(Map.find(a) == Map.end()){
            Map[a] = m1;
            Mapint[m1] = a;
            ++m1;
        }
        if(Map.find(b) == Map.end()){
            Map[b] = m1;
            Mapint[m1] = b;
            ++m1;
        }

        add(Map[a],Map[b]);
        f[Map[a]].push_back(Map[b]);
        edge[{Map[a],Map[b]}] = time;

    }


    for(int i = 1;i<=n;++i){
        if(ansMap.find(find(i)) == ansMap.end()){
            temv.clear();
            temv.push_back(i);
            ansMap[find(i)] = temv;
        }else{
            ansMap[find(i)].push_back(i);
        }
    }
    vector<string>ans;
    map<int,vector<int>>::iterator it;
    for(it = ansMap.begin();it!=ansMap.end();++it){
        vector<int>edges = it->second;
        maxshold = 0;maxid = edges.front();maxhead = 0;
        for(int i:edges){
            for(int j:f[i]){
                int w = edge[{i,j}];
                Maphold[j] += w;
                Maphold[i] += w;
                maxshold += w;
                if(maxhead < Maphold[j]){
                    maxhead = Maphold[j];
                    maxid = j;
                }

                if(maxhead < Maphold[i]){
                    maxhead = Maphold[i];
                    maxid = i;
                }
            }
        }
        if(maxshold > threshold && it->second.size() > 2){
            ans.push_back(Mapint[maxid]+" "+ to_string(it->second.size()));
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size() == 0){
        return 0;
    }
    sort(ans.begin(),ans.end());
    for(string s:ans){
        cout<<s<<endl;
    }
    return 0;
}