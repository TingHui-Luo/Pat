

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
}nodes[100000];
int a,b;
vector<int>f1,f2;
int main(){
    a = read();b = read();
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        nodes[tem].val = read();
        nodes[tem].next = read();
    }
    int len1 = 0,len2 = 0;
    int temA = a,temB = b;
    while(temA!=-1){
        ++len1;
        f1.emplace_back(temA);
        temA = nodes[temA].next;
    }
    while(temB!=-1){
        ++len2;
        f2.emplace_back(temB);
        temB = nodes[temB].next;
    }
    if(len1<len2) {
        swap(a,b);
        swap(f1,f2);
    }
    reverse(f2.begin(),f2.end());
    int index1 = 0,index2 = 0;
    vector<int>ans;
    while(index1<f1.size()&&index2<f2.size()){
        ans.emplace_back(f1[index1++]);
        if(index1 == f1.size()) break;
        ans.emplace_back(f1[index1++]);
        ans.emplace_back(f2[index2++]);
    }
    while(index1<f1.size()){
        ans.emplace_back(f1[index1++]);
    }
    for(int i = 0;i<ans.size();++i){
        if(i == ans.size()-1){
            printf("%05d %d %d\n",ans[i],nodes[ans[i]].val,-1);
        }
        else printf("%05d %d %05d\n",ans[i],nodes[ans[i]].val,ans[i+1]);

    }
    return 0;
}

