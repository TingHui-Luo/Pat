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
using namespace std;
int n,m,k;

inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}

int L;
vector<int>E[1010];

int work(int x){
    int ans = 0;
    int l = L + 1;
    vector<int>vis(n+1,0);
    queue<int>q;
    q.push(x);
    int temSize = 1;
    vis[x] = 1;
    while(!q.empty()&&l){
        --l;
        for(int j = 0;j<temSize;++j) {
            int u = q.front();
            q.pop();
            ++ans;
            for (int i:E[u]) {
                if (vis[i]) continue;
                vis[i] = 1;

                q.push(i);
            }
        }
        temSize = q.size();
    }
    return ans;
}

int main(){
    n = read();L = read();
    for(int i = 0;i<n;++i){
        int num;num = read();
        for(int j = 0;j<num;++j){
            int tem;tem =read();
            E[tem].emplace_back(i+1);
        }
    }

    k = read();
    for(int i = 0;i<k;++i){
        int num;num = read();
        cout<<work(num)-1<< endl;
    }
    return 0;
}