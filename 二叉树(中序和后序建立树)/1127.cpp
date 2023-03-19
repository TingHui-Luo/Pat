
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
    int val;
    node *left,*right;
};
vector<int>postOrder;
vector<int>inOrder;

node *build(int postLeft,int postRight,int inLeft,int inRight){
    if(postLeft > postRight) return NULL;
    node * x = new node();
    int i;
    for(i = inLeft;i<=inRight;++i){
        if(inOrder[i] == postOrder[postRight]) break;
    }
    int len = i - inLeft;
    x->val = postOrder[postRight];
    x->left = build(postLeft,postLeft+len-1,inLeft,inLeft+len-1);
    x->right = build(postLeft+len,postRight-1,inLeft+len+1,inRight);
    return x;
}

int main(){
    n = read();

    for(int i = 0;i<n;++i){
        int tem = read();
        inOrder.emplace_back(tem);
    }
    for(int i = 0;i<n;++i){
        int tem = read();
        postOrder.emplace_back(tem);
    }
    node *x = build(0,n-1,0,n-1);

    queue<node*>q;
    int temSize = 1;
    vector<int>ans;
    q.push(x);
    int sym = 0;
    while (!q.empty()){
        vector<int>tem;
        for(int i = 0;i<temSize;++i){
            node * u = q.front();q.pop();
            tem.emplace_back(u->val);
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        if(sym == 1){
            for(int j = 0;j<int(tem.size());++j){
                ans.emplace_back(tem[j]);
            }
        }else{
            for(int j =int(tem.size())-1;j>=0;--j){
                ans.emplace_back(tem[j]);
            }
        }
        sym = (sym + 1)%2;
        temSize = q.size();
    }
    cout<<ans[0];
    for(int i = 1;i<int(ans.size());++i){
        cout<<" "<<ans[i];
    }
    return 0;
}