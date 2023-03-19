//
// Created by Dell on 2022-03-28.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int>Map;

int n,m,ans;
int main(){
    cin>>n>>m;

    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            int tem;cin>>tem;
            Map[tem] += 1;
            if(Map[tem] > n*m/2){
                ans = tem;
            }
        }
    }
    cout<<ans;
    return 0;
}