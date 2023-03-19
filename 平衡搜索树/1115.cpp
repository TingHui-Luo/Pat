
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

struct node{
    int val;
    node *left,*right;
};
node * root;
void  build(node *&x,int val){
    if(x == NULL){
        x = new node();
        x->left = x->right = NULL;
        x-> val = val;
        return;
    }
    if(val>x->val) build(x->right,val);
    else build(x->left,val);
}

int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        build(root,tem);
    }
    queue<node*>q;
    map<int,vector<int>>Map;
    q.push(root);
    int temSize = 1;
    int deep = 1;
    while(!q.empty()){
        for(int i = 0;i<temSize;++i){
            node * u = q.front();q.pop();
            Map[deep].emplace_back(u->val);
            if(u->left!=NULL) q.push(u->left);
            if(u->right!=NULL) q.push(u->right);
        }
        ++deep;
        temSize = q.size();
    }
    --deep;
    cout<<Map[deep].size()<<" + "<<Map[deep-1].size()<<" = "<<Map[deep].size()+ Map[deep-1].size();
    return 0;
}