

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
map<int,int>Map;
vector<int>f;
int main(){
     n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
        Map[tem] = 1;
    }

    for(int i = 1;i<=n+1;++i){
        if(Map[i]==0){
            cout<<i;
            return 0;
        }
    }

    return 0;
}

