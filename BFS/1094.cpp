//
// Created by Dell on 2022-04-10.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int mod = 1000000007;
int n,m;
inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c=getchar();}
    while(c>='0'&&c<='9') {x = x*10+c-'0'; c= getchar();}
    return x*y;

}
int maxDeep = 1,maxNum = 1;
vector<int>f[110];
void bfs(){
    queue<int>q;
    q.push(1);
    int temSize = 1,Deep = 1;
    while(!q.empty()){
        for(int i = 0;i<temSize;++i){
            int u = q.front();q.pop();
            for(int v:f[u]){
                q.push(v);
            }
        }
        temSize = q.size();
        Deep += 1;
        if(maxNum<temSize){
            maxNum = temSize;
            maxDeep = Deep;
        }
    }
}
int main(){
    n = read();m =read();
    for(int i = 0;i<m;++i){
        int u = read();
        int num = read();
        for(int j = 0;j<num;++j){
            int v = read();
            f[u].emplace_back(v);
        }
    }
    bfs();
    cout<<maxNum<<" "<<maxDeep;
    return 0;
}