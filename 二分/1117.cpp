
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
vector<int>f;
int check(int x){
    int num = 0;
    for(int i:f){
        if(i>x) ++ num;
    }
    return num;
}
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }
    int left = 1,right = n;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(check(mid)>mid){
            left = mid + 1;
        }else if(check(mid) == mid){
            left = mid + 1;
        }
        else {
            right = mid -1;
        }
    }
    cout<<right;
    return 0;
}