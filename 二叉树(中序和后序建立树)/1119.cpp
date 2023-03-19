
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

vector<int>PostOrder;
vector<int>PreOrder;
struct node{
    int val;
    node* left,*right;
};
node *x;
int isSpecial = 1;
vector<int>ans;

void build(int Preleft,int Preright,int Postleft,int Postright){
    if(Preleft > Preright) return ;
    if(Preleft == Preright){
        ans.emplace_back(PreOrder[Preleft]);
        return ;
    }
    int  i;
    for(i = Postleft;i<=Postright;++i){
        if(PostOrder[i] == PreOrder[Preleft+1]) break;
    }
    if( i == Postright -1) isSpecial = 0;

    int zeng = i - Postleft;

    build(Preleft+1,Preleft+zeng+1,Postleft,i);
    ans.emplace_back(PreOrder[Preleft]);
    build(Preleft+zeng+2,Preright,i+1,Postright-1);

}

int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        PreOrder.emplace_back(tem);
    }

    for (int i = 0; i < n; ++i) {
        int tem = read();
        PostOrder.emplace_back(tem);
    }
    build(0,n-1,0,n-1);

    cout<<((isSpecial == 1)?"Yes":"No")<<endl<<ans[0];
    for(int i = 1;i<ans.size();++i){
        cout<<" "<<ans[i];
    }
    return 0;
}