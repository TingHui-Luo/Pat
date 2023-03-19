//
// Created by Dell on 2022-03-29.
//

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
set<int>f[60];
unordered_map<int,unordered_map<int,int>>Map;
inline int read(){
    int x=0,y=1;char c= getchar();
    while(c<'0'||c>'9'){
        if(c == '-') y = -1;
        c= getchar();
    }
    while(c>='0'&&c<='9'){
        x = x*10+c-'0';
        c = getchar();
    }
    return x*y;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;++i){

        int num;
        num = read();
        for(int j = 0;j<num;++j){
            int tem;
            tem = read();
            f[i].insert(tem);
            Map[i][tem] = 1;
        }
    }
    int m;
    cin>>m;
    for(int i = 0;i<m;++i){
        int a,b;
        a = read();b=read();
        int nc = 0;
        for(auto c:f[a-1]){
            if(Map[b-1][c]){
                ++nc;
            }
        }

        double ans = double (nc)/double (f[a-1].size() + f[b-1].size() - nc);
        ans = ans *100.0;
        printf("%.1f%\n",ans);
    }
    return  0;
}