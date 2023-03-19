

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
int root;
struct node{
    string val;
    int left,right;
}Nodes[30];
vector<int>Input(30);
string dfs(int x){
    if(x ==-1) return "";
    if(Nodes[x].right!=-1){
        Nodes[x].val = dfs(Nodes[x].left) + Nodes[x].val + dfs(Nodes[x].right);
        if(x!=root){

            Nodes[x].val="("+Nodes[x].val+")";
        }
    }
    return Nodes[x].val;
}
int main(){
    n = read();
    for(int i = 1;i<=n;++i){
        string x;
        cin>>x;
        Nodes[i].val = x;
        Nodes[i].left = read(),Nodes[i].right = read();
        if(Nodes[i].left!=-1) Input[Nodes[i].left]++;
        if(Nodes[i].right!=-1) Input[Nodes[i].right]++;
    }

    for(int i = 1;i<=n;++i){
        if(Input[i] == 0){
            root = i;
            break;
        }
    }
    cout<<dfs(root);
    return 0;
}