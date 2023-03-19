
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
struct node{
    int v,height;
    node *left,*right;
};
node *root;

int getMaxHeight(node *x){
    if(x == NULL) return 0;
    else return x->height;
}

void updateMaxHeight(node *&x){
    x->height = max(getMaxHeight(x->left), getMaxHeight(x->right)) + 1;
}

void R(node *&x){
    node * tem = x->left;
    x->left = tem->right;
    tem->right = x;
    updateMaxHeight(x);
    updateMaxHeight(tem);
    x = tem;
}

void L(node *&x){
    node * tem = x->right;
    x->right = tem->left;
    tem->left = x;
    updateMaxHeight(x);
    updateMaxHeight(tem);
    x = tem;
}

void build(node *&x,int val){
    if(x == NULL){
        x = new node();
        x->v = val;
        x->left = x->right = NULL;
        x->height = 1;
        return;
    }
    if(val<x->v) {
        build(x->left,val);
        updateMaxHeight(x);
        if(getMaxHeight(x->left) - getMaxHeight(x->right) == 2){
            if(getMaxHeight(x->left->left) - getMaxHeight(x->left->right) == 1){
                R(x);
            }else if(getMaxHeight(x->left->left) - getMaxHeight(x->left->right) == -1){
                L(x->left);
                R(x);
            }
        }
    }else{
        build(x->right,val);
        updateMaxHeight(x);
        if(getMaxHeight(x->left) - getMaxHeight(x->right) == -2){
            if(getMaxHeight(x->right->left) - getMaxHeight(x->right->right) == 1){
                R(x->right);
                L(x);
            }else if(getMaxHeight(x->right->left) - getMaxHeight(x->right->right) == -1){
                L(x);
            }
        }
    }
}
int sym = 1,ok = 0;
vector<int>level;
void bfs(node * x){
    queue<node*>q;
    q.push(x);
    int temSize = 1;
    while (!q.empty()){
        for(int i = 0;i<temSize;++i) {
            node *u = q.front();
            q.pop();
            level.emplace_back(u->v);
            if(u->right != NULL && u->left==NULL) {
                sym = 0;
            }else if(u->right!=NULL && u->left!=NULL){
                if(ok) {
                    sym = 0;
                }
            }else {
                if(ok == 0) ok =1;
                else{
                    if(!(u->right == NULL && u->left == NULL)){
                        sym = 0;
                    }
                }
            }
            if (u->left != NULL) q.push(u->left);
            if (u->right != NULL) q.push(u->right);
        }
        temSize = q.size();
    }
}
int main(){
    n = read();

    for(int i = 0;i<n;++i) {
        int tem = read();
        build(root,tem);
    }
    bfs(root);
    cout<<level[0];
    for(int i = 1;i<level.size();++i){
        cout<<" "<<level[i];
    }
    cout<<endl<<((sym == 1)?"YES":"NO");
    return 0;
}