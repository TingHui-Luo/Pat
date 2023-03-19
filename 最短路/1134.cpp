

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m,k;
vector<int>f[100000];

int main(){

    n = read();m = read();

    for(int j = 0;j<m;++j){
        int u =read(),v=read();
        f[u].emplace_back(j);
        f[v].emplace_back(j);
    }
    int k = read();
    for(int i = 0;i<k;++i){
        int num = read();
        map<int,int>Map;
        for(int j = 0;j<num;++j){
            int v = read();
            for(int id:f[v]){
                Map[id] = 1;
            }
        }
        if(Map.size() == m) {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}