

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m;
int f[300][300];
int main(){
    n = read(); m = read();
    for(int i = 0;i<m;++i){
        int u = read(),v = read();
        f[u][v] = 1;
        f[v][u] = 1;
    }
    int k = read();

    for(int i = 0;i<k;++i){
        int num = read();
        vector<int>nodes;
        nodes.clear();
        map<int,int>Map;
        for(int j=0;j<num;++j){
            int tem = read();
            nodes.emplace_back(tem);
            Map[tem] =1 ;
        }
        int sym = 1;
        for(int u:nodes){
            for(int v:nodes){
                if( u == v) continue;
                if(f[u][v]==0) {sym = 0;break;}
            }
        }
        if(sym == 0) {
            cout<<"Not a Clique"<<endl;
            continue;
        }
        int isMax = 1;
        for(int u:nodes){
            for(int j = 0;j<=210;++j) {
                if (Map[j] || f[j][u] == 0) continue;
                int sy = 1;
                for (int v: nodes) {
                    if (f[v][j] == 0) {
                        sy = 0;
                        break;
                    }
                }
                if(sy){
                    isMax = 0;
                    break;
                }
            }
        }
        if(isMax == 1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"Not Maximal"<<endl;
        }
    }

    return 0;
}

