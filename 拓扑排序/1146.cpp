

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
vector<int>in;
int ff[1010][1010];
int main(){
    n = read();m = read();
    in.assign(n+1,0);
    for(int i = 0;i<m;++i){
        int u = read(),v = read();
        in[v]++;
        ff[u][v] = 1;
    }

    vector<int>ans;
    vector<int>f = in;
    int k = read();
    for(int i = 0;i<k;++i){
        int sym = 0;
        in = f;
        for(int j = 0;j<n;++j){
            int tem = read();
            if(in[tem] == 0&&!sym){
                for(int v = 1;v<=n;++v){
                   if(ff[tem][v] == 1) {in[v]--;};
                }
            }else{
                sym = 1;
                continue;
            }

        }
  
        if(sym) ans.emplace_back(i);
    }
    if(ans.size()){
        cout<<ans[0];
        for(int i =1;i<ans.size();++i){
            cout<<" "<<ans[i];
        }
    }else{
        cout<<endl;
    }
    return 0;
}

