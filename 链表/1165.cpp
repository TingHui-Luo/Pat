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
    int next;
    int address;
}Nodes[100000];
unordered_map<int,int>index;
int main(){
    int root = read();
    n = read();int k = read();
    for(int i = 0;i<n;++i){
        node a;
        int tem = read();
        Nodes[tem].val = read();Nodes[tem].next = read();
        Nodes[tem].address = tem;
    }
    vector<node>f;
    vector<node>temF;
    int temRoot = root;
    while(temRoot!=-1){
        temF.emplace_back(Nodes[temRoot]);
        if(temF.size() == k){
            for(int i = temF.size()-1;i>=0;--i){
                f.emplace_back(temF[i]);
            }
            temF.clear();
        }
        temRoot = Nodes[temRoot].next;
    }
    if(temF.size()){
        for(int i = temF.size()-1;i>=0;--i){
            f.emplace_back(temF[i]);
        }
        temF.clear();
    }
    reverse(f.begin(),f.end());
    for(int i = 0;i<f.size();++i){
        if(i == f.size()-1) printf("%05d %d %d\n",f[i].address,f[i].val,-1);
        else printf("%05d %d %05d\n",f[i].address,f[i].val,f[i+1].address);
    }

    return 0;
}


