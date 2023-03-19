

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
vector<int>colors;
map<pair<int,int>,int>Map;
int main(){
    n = read();m = read();
    for(int i = 0;i<m;++i){
        int u =read(), v= read();
        Map[{u,v}] = 1;
    }
    int k = read();
    for(int i = 0;i<k;++i){
        colors.clear();
        map<int,int>MM;
        for(int j = 0;j<n;++j){
            int tem = read();
            colors.emplace_back(tem);
            MM[tem] = 1;
        }
        int sym = 0;
        map<pair<int,int>,int>::iterator it;

//         for(it = Map.begin();it!=Map.end();it++) {
        for(auto it:Map){
            if(colors[it.first.first] == colors[it.first.second]){
                sym = 1;
                break;
            }
        }
//         }
        if(sym) {
            cout<<"No"<<endl;
        }else{
            printf("%d-coloring\n",MM.size());
        }
    }


    return 0;
}
