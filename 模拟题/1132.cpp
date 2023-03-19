

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

int n,m;
int zhuan(string s){
    int ans = 0;
    for(char c:s){
        ans = ans * 10 + c-'0';
    }
    return ans;
}
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        string s ;
        cin>>s;
        string s1 = s.substr(0,s.length()/2);
        string s2 = s.substr(s.length()/2);
        int a = zhuan(s1),b = zhuan(s2),A = zhuan(s);

        if(a*b != 0 && (A%(a*b)) == 0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}