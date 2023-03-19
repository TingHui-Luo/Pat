

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

int n,m,k;

string add(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int>num1(2000,0),num2(2000,0);
    for(int i = 0;i<a.size();++i){
        num1[i] = a[i]-'0';

    }
    for(int i = 0;i<b.size();++i){
        num2[i] = b[i]-'0';
    }
    for(int i = 0;i<b.size();++i){
        num1[i+1] += (num1[i] + num2[i])/10;
        num1[i] =  (num1[i] + num2[i])%10;
    }
    int len = b.size();
    while(num1[len]){
        num1[len + 1] += num1[len]/10;
        num1[len] = num1[len]%10;
        ++len;
    }
    string s = "";
    for(int i = len - 1;i>=0;--i){
        s = s + to_string(num1[i]);
    }
    return s;
}
int main(){
    int sym = 0;
    string s;
    cin>>s;
    for(int j = 0;j<s.size()/2;++j){
        if(s[j] != s[s.size()-j-1]) {sym = 1;break;}
    }
    if(sym == 0) {
        cout<<s<< " is a palindromic number.";
        return 0;
    }

    for(int i = 0;i<10;++i){
        string ss = s;
        reverse(ss.begin(),ss.end());

        string ans = add(ss,s);
        cout<<s<<" + "<<ss<<" = " <<ans<<endl;
        s = ans;
        sym = 0;
        for(int j = 0;j<s.size()/2;++j){
            if(s[j] != s[s.size()-j-1]) {sym = 1;break;}
        }

        if(sym == 0) {
            cout<<s<< " is a palindromic number.";
            return 0;
        }
    }
    cout<<"Not found in 10 iterations.";
    return 0;
}