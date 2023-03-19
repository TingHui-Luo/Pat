

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m;
int t;
bool check(int x){
    for(int i = 2;i<=x/2;++i){
        if(x%i == 0) return false;
    }
    return true;
}
int main(){
     t = read();n = read();m = read();

     while(!check(t)) ++t;
     vector<int>f(t,-1);
        map<int,int>Map;

     for(int i = 0;i<n;++i){
         int tem = read();
         int sym = 0;
         for(int j = 0;j<=t;++j){
             if(f[(j*j+tem%t)%t] == -1) {
                 f[(j*j+tem%t)%t] = tem;
                 sym = 1;

                 break;
             }
         }
         if(!sym) {
             cout<<to_string(tem) <<" cannot be inserted."<<endl;
         }
     }
    int ans = 0;
     for(int i = 0;i<m;++i){
         int tem = read();
         int j;
         for(j = 0;j<=t;++j){
             ++ans;
             if(f[(j*j+tem%t)%t] == tem||f[(j*j+tem%t)%t] == -1) {
                 break;
             }
         }

     }
    printf("%.1f",double (ans)/double (m));
    return 0;
}

