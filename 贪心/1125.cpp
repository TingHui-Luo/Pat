
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


priority_queue<double,vector<double>,greater<>> q;
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        q.push(tem);
    }
    while(q.size()!=1){
        double u = q.top();q.pop();
        double v = q.top();q.pop();
        q.push((u + v)/2.0);
    }
    cout<<int(q.top());
    return 0;
}