//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}

bool check(int x){
    if(x == 1) return false;
    for(int i = 2;i<=sqrt(x);++i){
        if(x%i == 0) return false;
    }
    return true;
}

int n,m;
map<int,int>Map;
int main(){
    n =read();
    m =read();
    while(!check(n)){
        ++n;
    }

    vector<int>vis(n,0);
    vector<int>ans;
    for(int i = 0;i<m;++i){
        int tem;tem = read();
        int j = 0,sym = 0;
        while(j<=n&&!sym){
            if(!vis[(tem+j*j)%n]){
                sym = 1;
                break;
            }
            ++j;
        }
        if(sym){
            vis[(tem +j*j)%n] = 1;
            ans.push_back((tem+j*j)%n);
        }else {
            ans.push_back(-1);
        }
    }
    if(ans[0]<0) cout<<'-';
    else {
        cout<<ans[0];
    }
    for(int i = 1;i<ans.size();++i){
        if(ans[i]<0) cout<<" "<<'-';
        else {
            cout<<" "<<ans[i];
        }
    }

    return 0;
}