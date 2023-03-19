//
// Created by Dell on 2022-03-23.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n,m;

vector<int>f;
map<int,int>Map;
int main(){
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        int tem;cin>>tem;
        f.push_back(tem);
        Map[tem] += 1;
    }
    sort(f.begin(),f.end());
    for(int a:f){
        if(Map[m-a]){
            if(a == m-a &&Map[a] == 1) continue;
            cout<<min(a,m-a)<<" "<<max(a,m-a)<<endl;
            return 0;
        }
    }

    cout<<"No Solution"<<endl;
    return 0;
}