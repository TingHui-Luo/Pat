#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n;
struct node{
    int val;
    node *left,*right;
};
vector<int>f;


node* build(int left,int right){
    if(left> right) return NULL;
    int minn = 1e8,minId;
    for(int i = left;i<=right;++i){
        if(minn>f[i]){
            minn = f[i];
            minId = i;
        }
    }
    node *  x = new node;
    x->val = minn;
    x->left = build(left,minId-1);
    x->right = build(minId+1,right);
    return x;
}
vector<int>ans;
void bfs(node *x){
    queue<node*>q;
    q.push(x);

    while(!q.empty()){
        node* u = q.front();q.pop();
        ans.emplace_back(u->val);
        if(u->left) {
            q.push(u->left);
        }
        if(u->right){
            q.push(u->right);
        }
    }
}
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);

    }

    node * root = build(0,n-1);
    bfs(root);
    cout<<ans[0];
    for(int i = 1;i<ans.size();++i){
        cout<<" "<<ans[i];
    }
    return 0;
}


