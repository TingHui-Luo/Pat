
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


int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int k = read();
        vector<int>row(k+1,0);
        map<int,int>zheng;
        map<int,int>fan;
        int sym = 1;
        for(int j = 0;j<k;++j){
            int num = read();
            if(sym == 0) continue;

            if(row[num] == 1 || zheng[j+num] == 1||fan[j-num] == 1) {
                sym = 0;
                continue;
            }
            row[num] = 1;
            zheng[num+j] = 1;
            fan[j-num] = 1;
        }
        if(sym){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}