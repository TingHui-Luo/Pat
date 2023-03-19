

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

int n,m,k;
int root;

struct node{
    int next;
    int val;
    string id;
}e[1000000];

vector<node>q[4];

int main(){
    root = read(); n = read(); k =read();

    for(int i = 0;i<n;++i){
        int num =read();
        e[num].val = read();
        e[num].next = read();
        string s = to_string(num);
        while(s.size()!=5) s = "0" + s;
        e[num].id = s;
    }
    int x = root;
    while(x!=-1){
        int num = x;
        if(e[num].val < 0) q[1].emplace_back(e[num]);
        else if(e[num].val<=k) q[2].emplace_back(e[num]);
        else q[3].emplace_back(e[num]);
        x = e[x].next;

    }
    vector<node>ans;
    for(node a:q[1]) ans.emplace_back(a);
    for(node a:q[2]) ans.emplace_back(a);
    for(node a:q[3]) ans.emplace_back(a);
    for(int i = 0;i<ans.size();++i){
        if(i!=ans.size()-1)
        cout<<ans[i].id<<" "<<ans[i].val<<" "<<ans[i+1].id<<endl;
        else{
            cout<<ans[i].id<<" "<<ans[i].val<<" "<<to_string(-1)<<endl;
        }
    }
    return 0;
}