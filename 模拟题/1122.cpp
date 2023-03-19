
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

int n,m;
vector<int>Edge[300];

int main(){
    n = read(); m = read();
    for(int i = 0;i<m;++i){
        int a = read(), b = read();
        Edge[a].emplace_back(b);
        Edge[b].emplace_back(a);
    }
    int k = read();
    for(int i = 0;i<k;++i){
        int num = read();
        vector<int>f;
        map<int,int>Map;
        for(int j = 0;j<num;++j){
            int tem = read();
            f.emplace_back(tem);
        }
        int sym = 1;
        if(f[0]!=f[f.size()-1]) sym = 0;
        else if(f.size() != n+1) sym = 0;
        else {

            for(int j = 1;j<f.size();++j){
                if(!count(Edge[f[j-1]].begin(),Edge[f[j-1]].end(),f[j])){
                    sym = 0;
                    break;
                }
                if(Map[f[j]] == 1) {sym = 0;break;}
            }
        }
        if(Map.size() != n) sym = 0;
        if(n == 1 && num == 1) sym =1;
        if(sym){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}