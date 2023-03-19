

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
map<int,int>Map;
int n;


int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int a = read(),b = read();
        Map[a] = b;
        Map[b] = a;
    }
    int m = read();
    vector<int>f;
    map<int,int>Mapf;
    for(int i = 0;i<m;++i){
        int tem = read();
        f.emplace_back(tem);
        Mapf[tem] = 1;

    }
    set<int>ans;
    for(int i:f){
        if(Map.find(i)!=Map.end() && Mapf[Map[i]] == 1){
            continue;
        }
        ans.insert(i);
    }
    cout<<ans.size()<<endl;
    if(ans.size()){
        string s =  "";
        for(auto c:ans){
            string ss = to_string(c);
            while(ss.size()!=5) ss = "0" + ss;
            s += " " + ss;
        }
        s = s.substr(1);
        cout<<s;
    }else{
        cout<<endl;
    }
    return 0;
}