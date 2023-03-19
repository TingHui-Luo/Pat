//
// Created by Dell on 2022-03-04.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
map<int,double>Map;
set<int>q;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        int xi;double val;
        cin>>xi>>val;
        q.insert(xi);
        Map[xi] += val;
    }
    cin>>n;
    for(int i = 0;i<n;++i){
        int xi;double val;
        cin>>xi>>val;
        q.insert(xi);
        Map[xi] += val;
    }
    set<int>::reverse_iterator it;
    int ans = 0;
    for(it=q.rbegin();it!=q.rend();it++)
    {
        if(Map[*it] != 0){
           ++ans;
        }
    }
    cout<<ans;

    for(it=q.rbegin();it!=q.rend();it++)
    {

        if(Map[*it]!=0){
            cout<<" "<<*it <<" ";
            printf("%.1f",Map[*it]);
        }
    }
    return 0;
}