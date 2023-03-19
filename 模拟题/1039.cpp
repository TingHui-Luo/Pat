//
// Created by Dell on 2022-03-20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n,m;
map<string,vector<int>>Map;
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int a,n1;
        cin>>a>>n1;
        for(int j = 0;j<n1;++j){
            string s;
            cin>>s;
            if(Map.find(s) == Map.end()){
                vector<int>tem;tem.clear();
                tem.push_back(a);
                Map[s] = tem;
             }else{
                Map[s].push_back(a);
            }
        }
    }
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        cout<<s<<" "<<Map[s].size();
        sort(Map[s].begin(),Map[s].end());
        for(auto c:Map[s]){
            cout<<" "<<c;
        }
        cout<<endl;
    }

    return 0;
}