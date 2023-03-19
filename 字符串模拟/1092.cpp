

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
#include <stack>
using namespace std;
typedef long long ll;

inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1;c = getchar();}
    while(c>='0'&&c<='9') { x = x*10+c - '0';c=getchar();}
    return x*y;
}
map<char,int>Map;
int cnt = 0;
int main(){
    string a,b;
    cin>>a>>b;
    for(char c:b){
        Map[c] += 1;
    }
    cnt = b.size();
    for(char c:a){
        if(Map[c]){
            Map[c] -=1;
            --cnt;
        }
    }
    if(cnt == 0) {
        cout<<"Yes "<<a.size() - b.size();
    }else{
        cout<<"No "<<cnt;
    }
    return 0;
}
