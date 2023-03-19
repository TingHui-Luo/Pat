

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
vector<int>f;
int isLitter,isGrate;
vector<int>ans;
void dfs(int index){

    ans.emplace_back(f[index]);
    if(index*2>n){
        printf("%d",ans[0]);
        for(int i = 1;i<ans.size();++i){
            printf(" %d",ans[i]);
            if(ans[i] > ans[i-1]) isGrate = 1;
            if(ans[i] < ans[i-1]) isLitter = 1;
        }
        printf("\n");
    }
    if(index*2+1<=n) {
        dfs(index*2+1);
    }
    if(index*2<=n){
        dfs(index*2);
    }
    ans.pop_back();
}
int main(){
    n = read();
    f.emplace_back(0);
    for(int i =0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }

    dfs(1);
    if(isGrate && isLitter) printf("Not Heap\n");
    else if(isGrate) printf("Min Heap\n");
    else printf("Max Heap\n");
    return 0;
}
