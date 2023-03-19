#include <iostream>
#include <vector>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n;
vector<int>f;
int main(){
    n = read();
    f.emplace_back(0);
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }
    int a=0,b;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if(i == j) continue;
            for(int k = 1;k<3;++k) {
                vector<int> vis(n + 1, 1);
                vector<int>ff = f;
                vis[i] = -1;
                vis[j] = -1;

                int sym = 0,lang = 0;

                for(int t = 1;t<=n;++t){

                    if(ff[t]>0&&vis[abs(ff[t])]==-1){
                        ++sym;

                        if(t == i|| t==j) ++lang;
                    }
                    if(ff[t]<0&&vis[abs(ff[t])] == 1){
                        ++sym;

                        if(t == i|| t==j) ++lang;
                    }
                }
//                cout<<i<<" "<<j<<" "<<sym<<endl;
                if(sym == 2&&lang == 1){
                    a = i,b = j;
                }
            }
            if(a!=0){
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }
    cout<<"No Solution"<<endl;
    return 0;
}