#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
vector<int>f;
//int find(int x){
//    int a = x;
//    while(x!=f[x]){
//        x = f[x];
//    }
//    while(a!=f[x]){
//        int z = a;
//         a = f[a];
//         f[z] = a;
//    }
//    return x;
//}
//
//void Union(int x,int y){
//    x = find(x),y = find(y);
//    if(x!=y){
//        f[x] = y;
//    }
//}
int ff[1000][1000];
int main(){
    n = read();m = read();
//    f.assign(n+1,0);
//    for(int i = 1;i<=n;++i) f[i] = i;
    for(int i = 0;i<m;++i){
        int u = read(), v = read();
        ff[u][v] = ff[v][u] = 1;
    }
    m = read();
    for(int i = 0;i<m;++i){
        int num = read();
        f.clear();
        unordered_map<int,int>Map;
        for(int j = 0;j<num;++j){
            int tem = read();
            f.emplace_back(tem);
            Map[tem] = 1;
        }
        int sym = 1;
        for(int u:f){
            for(int v:f){
                if( u == v) continue;
                if(ff[u][v] == 0) {
                    sym = 0;
                    break;
                }
            }
            if(!sym) break;
        }
        if(!sym){
            printf("Area %d needs help.\n",i+1);
            continue;
        }
        int more = -1;
        for(int j = 1;j<=n;++j){
            if(Map[j]) continue;
            sym = 1;
            for(int v:f){
                if(!ff[j][v]) {
                    sym = 0;
                    break;
                }
            }
            if(sym){
                more = j;
                break;
            }
        }
        if(more!=-1){
            printf("Area %d may invite more people, such as %d.\n",i+1,more);
        }else{
            printf("Area %d is OK.\n",i+1);
        }
    }

    return 0;
}


