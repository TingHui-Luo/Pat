
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

int n;
vector<int>f(11000,0);
int find(int x){
    int a = x;
    while(x!=f[x]) x= f[x];
    while(a!=f[a]){
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}
set<int>ff;
void Union(int x,int y){
    x = find(x),y = find(y);
    if(x!=y){
        f[x] = y;
    }
}


int main(){
    n = read();

    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        int sum = 0;
        for(char c:s) sum = sum + c - '0';
        ff.insert(sum);
    }
    cout<<ff.size()<<endl;
    string ss = "";
    for(auto c:ff){
        ss += " "+to_string(c);
    }
    cout<<ss.substr(1);
    return 0;
}