//
// Created by Dell on 2022-03-28.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int n,maxn;
vector<int>f;
vector<int>initf;
vector<vector<int>>ans;
vector<vector<int>>q;
map<int,int>Map;
vector<int>rank1;
int main(){
    cin>>n>>maxn;
    for(int i = 0;i<n;++i) {
        int tem;cin>>tem;
        f.push_back(tem);
        Map[tem] = i;
    }
    initf.assign(n,0);
    rank1.assign(n,0);
    for(int i = 0;i<n;++i){
        int tem;cin>>tem;
        initf[i] = f[tem];
    }
    vector<int>rf;
    while(initf.size()!=1){
       ans.push_back(initf);


        q.clear();
        vector<int>temq;
        temq.clear();
        for(int i = 0;i<initf.size();++i){
            if((i%maxn == 0 && i!=0)) {
                q.push_back(temq);
                temq.clear();
            }
            temq.push_back(initf[i]);
        }
        if(temq.size())q.push_back(temq);
        rf.clear();
        for(auto c:q){
            sort(c.begin(),c.end());
            rf.push_back(c[c.size()-1]);
        }

        initf = rf;

    }
    ans.push_back(initf);
    int nums = 0;
    for(int i = ans.size()-1;i>=0;--i){
        int temnum = 0;
        for(int j:ans[i]){
//            cout<<j<<" ";
           if(rank1[Map[j]] == 0) {rank1[Map[j]]  =  nums +1;temnum ++;}

        }
//        cout<<endl;
        nums += temnum;
    }
    for(int i = 0;i<rank1.size()-1;++i){
        cout<<rank1[i]<<" ";
    }
    cout<<rank1[rank1.size()-1];
    return 0;
}