

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
struct node{
    int val;
    node *left ,*right;
};
void build(node *&x,int val){
    if(x==NULL) {
        x = new node;
        x->val = val;
        x->left = NULL;
        x->right = NULL;
        return;
    }
    if(x->val > val){
        build(x->left,val);
    }else{
        build(x->right,val);
    }
}
unordered_map<int,bool>Map;


int preOrder(node* root,int a,int b) {
    if (root == 0) return 0;
    if ((a <= root->val && b >= root->val) || (a >= root->val && b <= root->val)) return root->val;
    if(a<root->val&&b<root->val)//a,b都在左子树上
        return preOrder(root->left,a,b);
    if(a>root->val&&b>root->val)//a,b都在右子树上
        return preOrder(root->right,a,b);
}

int main(){
    m = read(); n = read();
    vector<int>f;
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
        Map[tem] = 1;
    }
    node * root = NULL;
    for(int i:f){
        build(root,i);
    }

    for(int i = 0;i<m;++i){
        int u = read(),v = read();
        if(Map[u] == 0 || Map[v] == 0){
            cout<<"ERROR: ";
            if(Map[u] ==0&&Map[v] == 0){
                cout<<to_string(u)<<" and "<<to_string(v)<<" are not found.";
            }else if(Map[u] == 0){
                cout<<to_string(u)<<" is not found.";
            }else{
                cout<<to_string(v)<<" is not found.";
            }
            cout<<endl;
            continue;
        }
        int ff = preOrder(root,u,v);

        if(u == ff||v==ff){
            if(u!=ff) swap(u,v);
            cout<<to_string(u)<<" is an ancestor of "<<to_string(v)<<"." <<endl;
            continue;
        }

        cout<<"LCA of "<<to_string(u)<<" and "<<to_string(v)<<" is "<<to_string(ff)<<"."<<endl;
    }

    return 0;
}

