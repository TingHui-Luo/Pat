//
// Created by Dell on 2022-04-02.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace  std;
map<vector<int>,int>vectorMap;
int n,m;
vector<int>f;
int sym = 1;
vector<int>ans;
void dfs(int index,int sum,vector<int>tem){
    if(sum > m  || sym == 0||vectorMap[tem]) return;
    if(sum == m){
        ans = tem;
        sym = 0;
        return;
    }
    if(index >=n) return;
    for(int i = index;i<n;++i){
        tem.push_back(f[i]);
        dfs(i+1,sum+f[i],tem);
        tem.pop_back();
    }
    vectorMap[tem] = 1;
}

int main(){
    cin>>n>>m;
    int all = 0;
    for(int i = 0;i<n;++i){
        int tem;cin>>tem;
        f.push_back(tem);
        all += tem;
    }
    if(all < m) {
        cout<<"No Solution";
        return 0;
    }
    sort(f.begin(),f.end());
    vector<int> tem;
    dfs(0,0,tem);
    if(ans.empty()) {
        cout<<"No Solution";
        return 0;
    }
    for(int i = 0;i<ans.size()-1;++i){
        cout<<ans[i]<<" ";
    }
    cout<<ans[ans.size()-1];
    return  0;
}
