//
// Created by Dell on 2022-03-20.
//
#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main(){
    int n1 ,n2;
    cin>>n1;
    vector<ll>f1,f2,f3,f4;
    for(int i = 0;i<n1;++i){
        ll tem;cin>>tem;
        if(tem>0) f1.push_back(tem);
        else if(tem<0) f4.push_back(tem);
    }
    cin>>n2;
    for(int i = 0;i<n2;++i){
        ll tem;cin>>tem;
        if(tem>0) f2.push_back(tem);
        else if(tem<0) f3.push_back(tem);
    }
    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());
    sort(f3.begin(),f3.end());
    sort(f4.begin(),f4.end());
    int left = f1.size()-1;
    ll ans = 0;
    for(int i = f2.size()-1;i>=0;--i){
            if(left >= 0){
                    ans += f1[left]*f2[i];
                    --left;
            }
    }
    left = 0;
    for(int  i = 0;i<f3.size();++i){
        if(left <f4.size()){
            ans += f4[left]*f3[i];
            ++left;
        }
    }
    cout<<ans;
    return 0;
}