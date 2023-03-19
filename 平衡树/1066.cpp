//
// Created by Dell on 2022-03-28.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

struct node{
    int v,height;
    node *left,*right;
};

void search(node * root,int x){
    if(root == NULL){
        cout<<"-1";
        return;
    }
    if(root->v == x){
        cout<<"1";
        return;
    }else if(root->v<x){
        search(root->right,x);
    }else {
        search(root->left,x);
    }
}

int getMaxHeight(node *x){
    if(x == NULL) return 0;
    else return x->height;
}

void updateHeight(node *&x){
    x->height = max(getHeight(x->left), getHeight(x->right)) +1;
}

void L(node *&root){
    node * tem = root->right;
    root->right = tem->left;
    tem->left = root;
    updateHeight(root);
    updateHeight(tem);
    root = tem;
}

void R(node *&root){
    node * tem = root->left;
    root->left = tem->right;
    tem->right = root;
    updateHeight(root);
    updateHeight(tem);
    root = tem;
}


void insert(node *x,int val){
    if(x == NULL){
        x = new node();
        x->height = 1;
        x->v = val;
        x->right = x->left = NULL;
        return;
    }
    else if(val>x->v){
        insert(x->right,val);
        updateHeight(x);
        if(getHeight(x->right) - getHeight(x->left) == 2){
            if(getHeight(x->right->right) - getHeight(x->right->left) == 1){
                L(x);
            }else{
                R(x->right);
                L(x);
            }
        }
    }else {
        insert(x->left,val);
        updateHeight(x);
        if(getHeight(x->right) - getHeight(x->left) == -2){
            if(getHeight(x->right->right) - getHeight(x->right->left) == -1){
                R(x);
            }else{
                L(x->left);
                R(x);
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    node * root =NULL;
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        insert(root,tem);

    }

    cout<<root->v;
    return 0;
}
