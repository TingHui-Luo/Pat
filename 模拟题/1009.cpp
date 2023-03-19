//
// Created by Dell on 2022-03-06.
//
#include <iostream>
#include <map>
#include <set>

using namespace std;
map<int,double>Map1;
map<int,double>ans;

struct lth{
    int nn;
    double mm;
    bool operator < (const lth& a)const{
        return a.nn<nn;
    }
};

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        double tem;int temn;
        cin>>temn>>tem;
        Map1[temn] += tem;
    }
    cin>>n;
    for(int i = 0;i<n;++i){
        double tem;int temn;
        cin>>temn>>tem;
        for(auto c:Map1){
            ans[c.first+temn] += c.second*tem;
        }
    }
    set<lth>q;
    for(auto c:ans){
        lth l;
        l.nn = c.first;
        l.mm = c.second;
        if(l.mm != 0)
        q.insert(l);
    }
    cout<<q.size();
    for(auto c:q){
        cout<<" "<<c.nn<<" ";
        printf("%.1f",c.mm);
    }

    return 0;
}
