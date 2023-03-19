#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int n;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

vector<int>f;
vector<int>In(15,0);
vector<int>Out(15,0);
vector<int>inOrder;

struct node{
    int val;
    int left,right;
}e[15];

void invertTree(int x){
    if(x == - 1) return;
    swap(e[x].left,e[x].right);
    invertTree(e[x].left);
    invertTree(e[x].right);
}

void findInOrder(int x){
    if(x == -1) return;
    findInOrder(e[x].left);
    inOrder.emplace_back(x);
    findInOrder(e[x].right);
}

int main()
{
    n = read();
    for(int i = 0;i<n;++i){
        string s1,s2;
        cin>>s1>>s2;
        if(s1 == "-"){
            e[i].left = -1;
        }else{
            Out[i]++;
            In[s1[0]-'0']++;
            e[i].left = s1[0] - '0';
        }

        if(s2 == "-"){
            e[i].right = -1;
        }else{
            Out[i]++;
            In[s2[0]-'0']++;
            e[i].right = s2[0] - '0';
        }

    }
    int root;
    for(int i = 0;i<n;++i){
        if(In[i] == 0 && Out[i] != 0){
            root = i;
        }
    }
    invertTree(root);

    int temRoot = root;
    vector<int>bfsAns;

    queue<int>q;
    q.push(temRoot);
    int temSize = 1;
    while(!q.empty()){
        for(int i = 0;i<temSize;++i){
            int u = q.front();q.pop();
            bfsAns.push_back(u);
            if(e[u].left!=-1) q.push(e[u].left);
            if(e[u].right!=-1) q.push(e[u].right);
        }
        temSize = q.size();
    }
    if(bfsAns.size()) {
        cout << bfsAns[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << bfsAns[i];
        }
        cout << endl;
    }
    findInOrder(root);
    if(inOrder.size()){
    cout<<inOrder[0];
    for(int i = 1;i<n;++i){
        cout<<" "<<inOrder[i];
    }}
    return 0;
}