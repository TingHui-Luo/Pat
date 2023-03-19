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
int n;
struct node{
    int val;
    int right,left;

}f[21];
int zhuan(string x){
    int ans = 0;
    for(char c:x){
        ans = ans*10 + c-'0';
    }
    return  ans;
}
int root;
vector<int>In(21,0);
vector<int>Out(21,0);
int main(){
    n = read();
    if(n == 1){
        cout<<"Yes"<<0;
        return 0;
    }
    for(int i = 0;i<n;++i){
        string s1,s2;
        cin>>s1>>s2;

        if(s1!="-"){f[i].left= zhuan(s1);In[zhuan(s1)] ++;Out[i]++;}
        else f[i].left = -1;
        if(s2!="-"){f[i].right = zhuan(s2);In[zhuan(s2)] ++;Out[i]++;}
        else f[i].right = -1;

    }
    for(int i = 0;i<n;++i){
        if(In[i] == 0 && Out[i]!= 0) root = i;
    }

    queue<int>q;
    q.push(root);
    int temSize = 1,sym = 0,ok = 0;
    int last = 0;
    while(!q.empty()){

            int u = q.front();
            q.pop();
            last = u;

        int l = f[u].left;
        int r =  f[u].right;
        if (l == -1 && r != -1) { sym = 1;
            break; }
        if (l != -1 && r != -1) {
            if (ok) { sym = 1; break; }
        } else {
            if (ok == 0) ok = 1;
            else {
                if (l != -1 && r == -1) { sym = 1; break; }
            }
        }
        if (l != -1) q.push(l);
        if (r != -1) q.push(r);


    }
    if(sym) {cout<<"NO "<<root;return 0;}
    else{
        cout<<"YES "<<last;return 0;
    }
    return 0;
}
