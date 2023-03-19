

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
unordered_map<string,int>Map;
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        Map[s] +=1;

    }
    m = read();
    int ans = 0;
    string anss = "",anss1 = "";
    for(int i = 0;i<m;++i){
        string s;
        cin>>s;
        Map[s] +=1;

        if(anss1 == "") anss1 = s;
        else if(anss1.substr(6,8) > s.substr(6,8)){
            anss1 = s;
        }

        if(Map[s] == 2) {
            ++ans;
            if(anss == "") anss = s;
            else if(anss.substr(6,8) > s.substr(6,8)){
                anss = s;
            }
        }
    }
    if(ans == 0){
        printf("0\n");
        cout<<anss1;
    }else{
        printf("%d\n",ans);
        cout<<anss;
    }
    return 0;
}
