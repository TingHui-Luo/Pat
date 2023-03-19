

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
unordered_map<int,int>f;
vector<int>postOrder;
vector<int>inOrder;
struct node{
    int val;
    node *left = NULL,*right = NULL;
};
node * build(int postLeft,int postRight,int inLeft,int inRight){
    if(postLeft > postRight) return  NULL;
    node * x = new node;
    x->val = postOrder[postRight];

    int i = f[x->val];
    int len = i - inLeft;
    x->left = build(postLeft,postLeft+len-1,inLeft,inLeft+len-1);
    x->right = build(postLeft+len,postRight-1,inLeft+len+1,inRight);
    return x;
}

int isFull = 1;
unordered_map<int,int>Deep;
map<pair<int,int>,int>brother;
unordered_map<int,int>parent;
unordered_map<int,int>leftChild;
unordered_map<int,int>rightChild;
void bfs(node * x){
    queue<node*>q;
    q.push(x);
    int temSize= 1,deep = 1;

    while(!q.empty()){
        for(int i = 0;i<temSize;++i){
            node * u = q.front();q.pop();
            if((u->left==NULL&&u->right!=NULL)||(u->left!=NULL&&u->right==NULL)) isFull = 0;
            Deep[u->val] = deep;
            if(u->left!=NULL){
                q.push(u->left);
                if(u->right!=NULL)brother[{u->left->val,u->right->val}] = 1;
                parent[u->left->val] = u->val;
                leftChild[u->val] = u->left->val;

            }
            if(u->right!=NULL){
                q.push(u->right);
                if(u->left!=NULL)brother[{u->right->val,u->left->val}] = 1;
                parent[u->right->val] = u->val;
                rightChild[u->val] = u->right->val;
            }
        }
        ++deep;
        temSize = q.size();
    }
}

int zhuan(string s){
    int ans = 0;
    for(char c:s){
        ans = ans * 10 + c - '0';
    }
    return ans;
}
int main(){

    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        postOrder.emplace_back(tem);
    }
    for(int i = 0;i<n;++i){
        int tem = read();
        f[tem] = i;
        inOrder.emplace_back(tem);
    }

    node * root = build(0,n-1,0,n-1);
    bfs(root);
    m = read();
    for(int i = 0;i<m;++i){
        string s;
        getline(cin,s,'\n');
        vector<string>ans;
        int last = 0;
        for(int j = 0;j<s.size();++j){
            if(s[j] == ' '){
                ans.emplace_back(s.substr(last,j-last));
                last = j+1;
            }
        }
        ans.emplace_back(s.substr(last,s.size()-last));

        if(ans.size() == 4){
            if(zhuan(ans[0]) == root->val){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else if(ans.size() == 5){
            if(ans[0] == "It"){
                if(isFull == 1){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }else{
                if(brother[{zhuan(ans[0]), zhuan(ans[2])}]){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }else if(ans.size() == 6){
            if(parent[zhuan(ans[5])] == zhuan(ans[0])){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else if(ans.size() == 8){
            if(Deep[zhuan(ans[0])] == Deep[zhuan(ans[2])]){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else if(ans.size() == 7){
            if (ans[3] == "left") {
                if (leftChild[zhuan(ans[6])] == zhuan(ans[0])) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } else {
                if (rightChild[zhuan(ans[6])] == zhuan(ans[0])) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}

