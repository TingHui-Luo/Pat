

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

int n,maxDeep = 0,root;
double price,r;
vector<int>E[100010];
vector<int>Deep(100010,0);
int main(){
    n = read();
    scanf("%lf %lf",&price,&r);
    for(int i = 0;i<n;++i){
        int tem =read();
        if(tem!=-1){
            E[tem].emplace_back(i);
        }else{
            root = i;
        }
    }
    queue<int>q;
    q.push(root);
    Deep[root] = 1;
    int ans = 0;
    int temsize = 1;
    while(!q.empty()){
        for(int i = 0;i<temsize;++i) {
            int u = q.front();
            q.pop();
            for (int v: E[u]) {
                Deep[v] = Deep[u] + 1;
                if(Deep[v] > maxDeep){
                    ans = 1;
                    maxDeep = Deep[v];
                }else if(Deep[v] == maxDeep){
                    ans += 1;
                }
                q.push(v);
            }
        }
        temsize = q.size();
    }
    double anns = price;
    if(maxDeep != 0)
    {anns = pow(1.0+r/100.0,maxDeep-1) * price;}
    printf("%.2lf %d",anns,ans==0?1:ans);
    return 0;
}
