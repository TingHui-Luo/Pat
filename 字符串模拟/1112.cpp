
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
string s;
map<char,int>Map;
int main(){
    n = read();
    cin>>s;
    for(int i = 0;i<s.size();++i){
        int right = i;
        while(right+1 < s.size() && s[right+1] == s[i]){
            ++right;
        }
        if((right - i + 1)%n == 0){
            i =  right;
            if(Map[s[i]] == 0) Map[s[i]] = 1;
        }else{
            i = right;
            Map[s[i]] = -1;
        }

    }


    string ans = "";
    for(int i = 0;i<s.size();++i){
        int right = i;

        while(right+1 < s.size() && s[right+1] == s[i]){
            ++right;
        }
        if((right-i+1)%n == 0 && Map[s[i]] == 1){
            for(int j = 0;j<(right-i+1)/n;++j) ans += s[i];
            i = right;

        }else{
            ans += s[i];
        }
    }
    string ans1 = "";
    for(char c:s){
        if(Map[c] == 1){
            ans1+=c;
            Map[c] = 0;
        }
    }

    cout<<ans1<<endl<<ans;
    return 0;
}
