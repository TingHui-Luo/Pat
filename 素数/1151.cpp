#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
int zhuan(string s){
    int ans = 0;
    for(char c:s){
        ans = ans * 10 + c-'0';
    }
    return ans;
}
int main(){
    n = read();m = read();
    string s;
    cin>>s;
    for(int i = 0;i<s.size()-m+1;++i){
        string ss = s.substr(i,m);
        int x = zhuan(ss);
        int sym = 0;
        if(x<2) continue;
        for(int j = 2;j*j<=x;++j){
            if(x%j == 0){
                sym = 1;
                break;
            }
        }
        if(sym) continue;
        cout<<ss<<endl;
        return 0;
    }
    cout<<404<<endl;
    return 0;
}
