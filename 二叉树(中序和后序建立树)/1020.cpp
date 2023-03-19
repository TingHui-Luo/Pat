//
// Created by Dell on 2022-03-13.
//
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
};
int n;
vector<int>Post;
vector<int>In;
node *root1;
node * create(int PostL,int PostR,int InL,int InR){
    if(PostL > PostR) return NULL;
    node * root = new node();
    root->val = Post[PostR];

    int i;
    for( i = InL;i<=InR;++i){
        if(In[i] == Post[PostR]) break;
    }
    i = i - InL;
    root->left = create(PostL,PostL + i -1,InL,i+InL-1);
    root->right = create(PostL + i,PostR-1,InL+i+1,InR);
    return root;
}



vector<int>ans;
void bfs(node *x){
    queue<node*> q;
    q.push(x);
    while(!q.empty()){
        node * tem = q.front();
        q.pop();
        ans.push_back(tem->val);
        if(tem->left!=NULL) q.push(tem->left);
        if(tem->right!=NULL) q.push(tem->right);
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        Post.push_back(tem);
    }
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        In.push_back(tem);
    }
    root1 = create(0,n-1,0,n-1);
    bfs(root1);
    for(int i = 0;i<ans.size();++i){
        if(i!=ans.size()-1) cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    return 0;
}