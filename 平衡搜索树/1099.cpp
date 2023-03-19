
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int n;
vector<int>f;
vector<int>ans;
vector<int>Map;
inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

struct node{
    int left,right;
    int height;
    int val = -1 ;
}e[110];


int index = 0;
void inOrder(int root){
    if(root == -1) return;
    if(e[root].left!=-1) inOrder(e[root].left);
    e[root].val = f[index];
    ++index;
    if(e[root].right!=-1) inOrder(e[root].right);
}


void bfs(){
    queue<int>q;
    q.push(0);
    int temszie = 1;
    while (!q.empty()){
        for(int i = 0;i<temszie;++i){
            int u = q.front();q.pop();
            ans.emplace_back(e[u].val);
            if(e[u].left!=-1) q.push(e[u].left);
            if(e[u].right!=-1) q.push(e[u].right);
        }
        temszie = q.size();
    }
}
int main()
{
    n = read();
    for(int i = 0;i<n;++i){
        e[i].left = read();e[i].right = read();
    }
    for(int i = 0;i<n;++i){
        int tem =read();
        f.emplace_back(tem);
    }
    sort(f.begin(),f.end());
    inOrder(0);
    bfs();
    cout<<ans[0];
    for(int i = 1;i<ans.size();++i) cout<<" "<<ans[i];
    return 0;
}
