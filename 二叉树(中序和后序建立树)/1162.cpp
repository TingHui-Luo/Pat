

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
    string val;
    int left,right;
}nodes[50];
int in[50];

string dfs(int index){
    string ans = "";
    if(index == -1) return "";
    if(nodes[index].left==-1&&nodes[index].right!=-1){
        ans = "(" + nodes[index].val + dfs(nodes[index].right) + ")";
        return ans;
    }
    ans += dfs(nodes[index].left);
    ans += dfs(nodes[index].right);

    if(nodes[index].left == -1 && nodes[index].right == -1){
        ans += "(" + nodes[index].val+")";
    }
    else if(nodes[index].val[0]>'9'||nodes[index].val[0]<'0'){
        ans = "(" + ans + nodes[index].val+")";
    }
    return ans;
}

int main(){

    n = read();
    for(int i = 0;i<n;++i){

        cin>>nodes[i+1].val;
        nodes[i+1].left = read();
        nodes[i+1].right = read();
        if(nodes[i+1].left!=-1) in[nodes[i+1].left]++;
        if(nodes[i+1].right!=-1) in[nodes[i+1].right]++;
    }
    int root ;
    for(int i = 1;i<=n;++i){
        if(in[i] == 0)  {
            root = i;
            break;
        }
    }
    printf("%s\n",dfs(root).c_str());
    return 0;
}

