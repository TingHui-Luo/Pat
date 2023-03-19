

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m;
vector<int>postOrder;

struct node{
    int val = -1e8;
    node *left=NULL,*right=NULL;
};
void dfs(node * x){
    if(x->val == -1e8) return;
    dfs(x->left);
    dfs(x->right);

    postOrder.emplace_back(x->val);
}
int main(){
    m = read();n = read();
    for(int i = 0;i<m;++i){
        vector<int>f;
        for(int j = 0;j<n;++j){
            int tem = read();
            f.emplace_back(tem);
        }
        queue<node*>q;
        node *root = new node;
        q.push(root);
        int index = 0,temSize = 1;
        while(!q.empty()&&index<f.size()){
            for(int j = 0;j<temSize;++j){
                node * u = q.front();q.pop();
                if(index == f.size()) break;
                u->val = f[index++];
                u->left = new node;
                u->right = new node;
                if(index == f.size()) break;
                q.push(u->left);
                q.push(u->right);
            }
            if(index == f.size()) break;
            temSize = q.size();
        }
        int isMin = 1,isMax = 1;
        while(!q.empty()) q.pop();
        q.push(root);
        temSize = 1;


        while(!q.empty()){
            for(int j = 0;j<temSize;++j){
                node * u = q.front();q.pop();

                if(u->left!=NULL&&u->left->val!=-1e8){
                    q.push(u->left);

                    if(u->val>u->left->val){
                        isMin = 0;
                    }
                    if(u->val<u->left->val){
                        isMax = 0;
                    }
                }
                if(u->right!=NULL&&u->right->val !=-1e8){
                    q.push(u->right);
                    if(u->val>u->right->val){
                        isMin = 0;
                    }
                    if(u->val<u->right->val){
                        isMax = 0;
                    }
                }
            }
            temSize = q.size();
        }
        if(!isMin && !isMax){
            cout<<"Not Heap"<<endl;
        }else{
            if(isMax){
                cout<<"Max Heap"<<endl;
            }else{
                cout<<"Min Heap"<<endl;
            }
        }

        postOrder.clear();
        dfs(root);
        if(postOrder.size()) {
            cout << postOrder[0];
            for (int j = 1; j < postOrder.size(); ++j) {
                cout << " " << postOrder[j];
            }
        }
        cout<<endl;
    }
    return 0;
}


