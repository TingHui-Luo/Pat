

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

int n,m,l,T;
int f[1290][150][100];
bool vis[1290][150][100] ={false};
int dx[6] = {0,0,0,0,1,-1},dy[6] = {0,0,1,-1,0,0},dz[6]={1,-1,0,0,0,0};
int ans = 0;
int temans = 1;
struct node{
    int x,y,z;
    node(int x1,int y1,int z1){
        x = x1;
        y = y1;
        z = z1;
    }
};
void bfs(int x,int y,int z){
    queue<node>q;
    node a(x,y,z);
    q.push(a);
    vis[x][y][z] = 1;
    int temsize = 1;
    while(!q.empty()){
        for(int j = 0;j<temsize;++j) {
            x = q.front().x;
            y = q.front().y;
            z = q.front().z;
            q.pop();
            for (int i = 0; i < 6; ++i) {
                int tx = x + dx[i], ty = y + dy[i], tz = z + dz[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || tz < 0 || tz >= l) continue;
                if (vis[tx][ty][tz] || f[tx][ty][tz] == 0)continue;
                ++temans;
                vis[tx][ty][tz] = 1;
                q.push(node(tx, ty, tz));
            }
        }
        temsize = q.size();
    }

}
int main(){
    n = read();
    m = read();
    l = read();
    T = read();
    for(int i = 0;i<l;++i){
        for(int j = 0;j<n;++j){
            for(int k = 0;k<m;++k){
                f[j][k][i] = read();
            }
        }
    }
    for(int i = 0;i<l;++i){
        for(int j = 0;j<n;++j){
            for(int k = 0;k<m;++k){
                if(f[j][k][i] != 1|| vis[j][k][i]) continue;

                temans = 1;
                bfs(j,k,i);

                if(temans >=T) ans += temans;
            }
        }
    }
    cout<<ans;
    return 0;
}
