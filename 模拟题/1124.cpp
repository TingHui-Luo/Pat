
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

int n,m,s;
vector<string>f;
int main(){
    n = read(); m = read(); s = read();
    for(int i = 0;i<n;++i){
        string tem; cin>>tem;
        f.emplace_back(tem);
    }
    vector<string>ans;
    map<string,int>Map;
    s -=1;

    while(s<n){
        string ss = f[s];
        if(Map[ss] != 1){
            ans.emplace_back(ss);
            Map[ss] = 1;
            s = (s + m);

        }else{
            s = (s + 1);
        }
    }
    if(ans.size())
    for(string ss:ans){
        cout<<ss<<endl;
    }else{
        cout<<"Keep going..."<<endl;
    }
    return 0;
}