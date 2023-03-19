#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
set<int>ff[100000];
int main(){
    n = read();m = read();
    for(int i = 0;i<n;++i){
        int a,b;
        a = read();b = read();
        ff[a].insert(b);
        ff[b].insert(a);
    }0
    for(int i = 0;i<m;++i){
        int num = read();
        vector<int>f;
        for(int j = 0;j<num;++j){
            int tem = read();
            f.emplace_back(tem);
        }
        int sym = 0;
        for(int u:f){
            if(sym) break;
            for(int v:f){
                if(*ff[u].lower_bound(v) == v){
                    sym = 1;
                    break;
                }
            }
        }
        if(sym){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}