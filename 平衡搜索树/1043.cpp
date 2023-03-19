//
// Created by Dell on 2022-03-20.
//

#include<iostream>
#include <vector>
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)    return nullptr;
        if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
        else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
        else    // 当前节点就是要删除的节点
        {
            if (! root->left)   return root->right; // 情况1，欲删除节点无左子
            if (! root->right)  return root->left;  // 情况2，欲删除节点无右子
            TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有
            while (node->left)          // 寻找欲删除节点右子树的最左节点
                node = node->left;
            node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
            root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
        }
        return root;
    }
};

using namespace std;
struct node{
    int val;
    node *left = nullptr;
    node *right = nullptr;
};
node* root;
int n;
void build(node *&root,int data){
    if(root == nullptr){
        root = new node;
        root->val = data;
        root->left = nullptr;root->right = nullptr;
        return;
    }
    if(data < root->val) build(root->left,data);
    else build(root->right,data);
}

vector<int> origin,pre,preM,post,postM;

void preOrder(node *root){
    if(root == nullptr) {
        return;
    }
    pre.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}
void preOrderMirror(node *root){
    if(root == nullptr) {
        return;
    }
    preM.push_back(root->val);
    preOrderMirror(root->right);
    preOrderMirror(root->left);
}

void postOrder(node *root){
    if(root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->val);
}


void postOrderMirror(node *root){
    if(root == nullptr) {
        return;
    }
    postOrderMirror(root->right);
    postOrderMirror(root->left);
    postM.push_back(root->val);
}


int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        build(root,tem);
        origin.push_back(tem);
    }
    preOrder(root);
    preOrderMirror(root);
    postOrder(root);
    postOrderMirror(root);

    if(origin == pre){
        cout<<"YES"<<'\n';
        int sym = 0;
        for(auto c:post){
            if(!sym){ cout<<c;sym = 1;}
            else cout<<" "<<c;
        }
    }else if(origin == preM){
        cout<<"YES"<<'\n';
        int sym = 0;
        for(auto c:postM){
            if(!sym){ cout<<c;sym = 1;}
            else cout<<" "<<c;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}