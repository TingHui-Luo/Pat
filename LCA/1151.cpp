#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
vector<int>inOrder,preOrder;
struct node{
    int val;
    node *left = NULL,*right = NULL;
};
unordered_map<int,int>Map;
node * build(int preLeft,int preRight,int inLeft,int inRight){
    if(preLeft>preRight) return NULL;
    node * x = new node;
    x->val = preOrder[preLeft];
    int i = Map[preOrder[preLeft]];
    int len = i - inLeft;
    x->left = build(preLeft+1,preLeft+len,inLeft,inLeft+len-1);
    x->right = build(preLeft+1+len,preRight,inLeft+len+1,inRight);
    return x;
}
unordered_map<int,int>Height;
unordered_map<int,int>father;
void bfs(node *x){
    queue<node*>q;
    q.push(x);
    int temSize = 1,height = 1;
    while(!q.empty()){
        for(int i = 0;i<temSize;++i){
            node *u = q.front();q.pop();
            Height[u->val] = height;
            if(u->left) {q.push(u->left);father[u->left->val] = u->val;}
            if(u->right) {q.push(u->right);father[u->right->val] = u->val;};
        }
        ++height;
        temSize = q.size();
    }
}


int main(){
    m = read(); n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        inOrder.emplace_back(tem);
        Map[tem] = inOrder.size()-1;
    }
    for(int i = 0;i<n;++i){
        int tem = read();
        preOrder.emplace_back(tem);
    }

    node * root = build(0,n-1,0,n-1);
    bfs(root);
    for(int i = 0;i<m;++i){
        int u = read(),v = read();
        int temV = v,temU = u;
        if(Map.find(v)==Map.end()||Map.find(u)==Map.end()){
            if(Map.find(v)==Map.end()&&Map.find(u)==Map.end()){
                printf("ERROR: %d and %d are not found.\n",u,v);
            }else if(Map.find(v)==Map.end()){
                printf("ERROR: %d is not found.\n",v);
            }else{
                printf("ERROR: %d is not found.\n",u);
            }
            continue;
        }
        while(Height[u]!=Height[v]){
            if(Height[u]>Height[v]){
                u = father[u];
            }else{
                v = father[v];
            }
        }
        while(u!=v){
            u = father[u];
            v = father[v];
        }
        if(u == temU || v == temV){
            if(u == temU){
                printf("%d is an ancestor of %d.\n",u,temV);
            }else{
                printf("%d is an ancestor of %d.\n",v,temU);
            }
            continue;
        }else{
            printf("LCA of %d and %d is %d.\n",temU,temV,u);
        }
    }
    return 0;
}