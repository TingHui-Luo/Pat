

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


struct node{
    int val;
    int color;
    node *left,*right;
};
void build(node *&x,int val){
    if(x == NULL){
        x = new node();

        if(val<0) {
            x->color = 2;
        }else{
            x->color = 1;
        }
        x->val = abs(val);
        x->left = NULL;
        x->right = NULL;
        return;
    }
    if(x->val<abs(val)){
        build(x->right,val);
    }else{
        build(x->left,val);
    }
}
int sym = 1;
vector<int>ans;
void dfs(node *x,int red,int sum){
    if(x == NULL || x->color == 1) ++sum;
    if(x == NULL) {
        ans.emplace_back(sum);
        return;
    }
    if(red == 1 && x->color == 2) sym = 0;
    red = x->color-1;
    dfs(x->left,red,sum);
    dfs(x->right,red,sum);
}
int main(){

    n = read();
    for(int i = 0;i<n;++i){
        m = read();
        node *root = NULL;
        for(int j = 0;j<m;++j){
            int val = read();
            build(root,val);
        }
        if(root->color == 2){
            cout<<"No"<<endl;
            continue;
        }
        sym = 1; ans.clear();
        dfs(root,root->color-1,0);
       
        for(int num:ans){
            if(num!=ans[0]){
                sym = 0;
                break;
            }
        }
        if(sym == 0){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }

    return 0;
}