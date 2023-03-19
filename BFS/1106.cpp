#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}
int n ;
double price,r;
vector<int>f[110000];
vector<int>deep(110000,0);
map<int,int>Map;
int main(){

    n = read();
    cin>>price>>r;
    for(int i = 0;i<n;++i){
        int num = read();
        if(num == 0) {
            Map[i] = 1;
        }
        for(int j = 0;j<num;++j){
            int tem = read();
            f[i].emplace_back(tem);
        }
    }
    queue<int>q;
    q.push(0);
    int temSize = 1,mintDeep = 1e8,num = 0;
    while(!q.empty()) {
        for (int i = 0; i < temSize; ++i) {
            int u = q.front();
            q.pop();
            if(f[u].size() == 0) continue;
            for (int v: f[u]) {
                deep[v] = deep[u] + 1;
                if (Map[v] == 1) {
                    if (mintDeep > deep[v]) {
                        mintDeep = deep[v];
                        num = 1;
                    } else if (mintDeep == deep[v]) {
                        num++;
                    }

                }
                q.push(v);
            }
        }
        temSize = q.size();
    }


    printf("%.4lf %d", (price*double (pow(1.0+r/100.0,mintDeep==1e8?0:mintDeep))),num==0?1:num);
    return 0;
}
