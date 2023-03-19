

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;

bool check(int x){
    if(x<2) return false;
    for(int i = 2;i<=sqrt(x);++i){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    n = read();
    if(check(n)&&(check(n+6)|| check(n-6))){
        printf("Yes\n");
        if(check(n-6)) {
            printf("%d\n",n-6);
        }else{
            printf("%d\n",n+6);
        }
    }else{
        printf("No\n");
        for(int i = n+1;i<1e9;++i){
            if(check(i)&&(check(i+6)|| check(i-6))){
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}
