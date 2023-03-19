

//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;

inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1;c = getchar();}
    while(c>='0'&&c<='9') { x = x*10+c - '0';c=getchar();}
    return x*y;
}
int n;
stack<int>f;
vector<int>preOrder;
vector<int>inOrder;

struct node{
    int val;
    node *left,*right;
};
node *x;
node* build(int preLeft,int preRight, int inLeft, int inRight){
    if(preLeft>preRight) return NULL;
    node *root = new node();
    root->val = preOrder[preLeft];
    int i;
    for(i = inLeft;i<=inRight;++i){
        if(inOrder[i] == preOrder[preLeft]) break;
    }
    i = i - inLeft;
    root->left = build(preLeft+1,preLeft+i,inLeft,inLeft+i-1);
    root->right = build(preLeft+i+1,preRight,inLeft+i+1,inRight);
    return root;
}
vector<int>ans;
void dfs(node * a){
    if(a == NULL) return;
    dfs(a->left);
    dfs(a->right);
    ans.emplace_back(a->val);
    return;
}
int main(){
    n = read();
    for(int i = 0;i<2*n;++i){
        string s;
        cin>>s;
        if(s == "Push"){
            int tem = read();
            preOrder.emplace_back(tem);
            f.push(tem);
        }else{
            int tem = f.top();
            inOrder.emplace_back(tem);
            f.pop();
        }
    }

    x = build(0,n-1,0,n-1);
    dfs(x);
    cout<<ans[0];
    for(int i = 1;i<ans.size();++i){
        cout<<" "<<ans[i];
    }
    return 0;
}
