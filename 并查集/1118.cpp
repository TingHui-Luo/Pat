
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
int  find(int x){
    int a = x;
    while(x!=f[x]) x=f[x];
    while(a!=f[a]){
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

void Union(int x,int y){
    x = find(x),y = find(y);
    if(x!=y){
        f[x] = y;
    }
}
set<int>Mapf;
map<int,int>Map;
int main(){
    for(int i = 0;i<11000;++i) f[i] = i;
    n = read();
    for(int i = 0;i<n;++i){
        int numbers = read();
        int first = 0;
        for(int j = 0;j<numbers;++j){
            int tem = read();
            Mapf.insert(tem);
            if(j == 0) first = tem;
            else{
                Union(first,tem);
            }
        }
    }
    for(auto c:Mapf){
        c = find(c);
        Map[c]+=1;
    }
    cout<<Map.size()<<" "<<Mapf.size()<<endl;




    n = read();
    for(int i = 0;i<n;++i){
        int a = read(),b =read();
        if(find(a) == find(b)) {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}