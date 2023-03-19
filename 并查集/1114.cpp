
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
vector<int>f(10010,0);

int find(int x){
    int a = x;
    while(x!=f[x]){
        x = f[x];
    }
    while(a!=f[a]){
        int z =a;
        a = f[a];
        f[z] = a;
    }
    return x;
}

void Union(int x,int y){
    x = find(x),y = find(y);
    if(x!=y){
        f[x] = y;
    }
}


struct lth{
    int Mnumber,area;
}e[10010];
struct anss{
    int numbers;
    int minnId = 1e8;
    int allM;
    int allArea;
    double averageM;
    double averageA;
};
set<int>mf;
map<int,anss>Map;
bool cmp(const anss &a,const anss &b){
    if(a.averageA!=b.averageA) return a.averageA>b.averageA;
    return a.minnId < b.minnId;
}
int main(){
    n = read();
    for(int i = 0;i<10010;++i) f[i] = i;
    for(int i = 0;i<n;++i){
        int u = read(),left = read(),right = read();
        mf.insert(u);
        if(left!=-1) {Union(u,left);mf.insert(left);}
        if(right!=-1) {Union(u,right);mf.insert(right);}
        int numberson = read();
        for(int j = 0;j<numberson;++j){
            int son = read();
            Union(son,u);
            mf.insert(son);
        }
        e[u].Mnumber = read(),e[u].area = read();
    }
    for(int mem:mf){
        int x = find(mem);
        Map[x].minnId = min(Map[x].minnId,mem);
        Map[x].allArea += e[mem].area;
        Map[x].allM += e[mem].Mnumber;
        Map[x].numbers++;
    }
    vector<anss>ff;
    for(auto c:Map){
        ff.emplace_back(c.second);
    }
    for(auto &c:ff){
        c.averageA = double (c.allArea) / c.numbers;
        c.averageM = double  (c.allM) / c.numbers;
    }
    sort(ff.begin(),ff.end(),cmp);
    cout<<ff.size()<<endl;
    for(auto c:ff){
        string s =to_string(c.minnId);
        while(s.size()!=4) {s = "0"+s;}
        cout<<s<<" "<<c.numbers;
        printf(" %.3f %.3f\n",c.averageM,c.averageA);
    }
    return 0;
}