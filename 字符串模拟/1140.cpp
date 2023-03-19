

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

int main(){
    n = read();m =read();
    string s = to_string(n);
    for(int i = 1;i<m;++i){
        string ans = "";
        s += "&";
        char last = '*';
        int num = 1;
        for(int j = 0;j<s.size();++j){
            if(s[j ] == last){
                ++num;
            }else{
                if(last!='*')ans +=  last + to_string(num);
                last = s[j];
                num = 1;
            }
        }
        s = ans;
//        cout<<s<<endl;
    }
    printf("%s",s.c_str());
    return 0;
}

