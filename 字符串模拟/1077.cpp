//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}

int n;
vector<string>f;
int main(){
    n =read();
    int len = 1e8;
    for(int i = 0;i<n;++i){
        string s;

        getline(cin,s,'\n');
        len = min(int (s.size()),len);
        reverse(s.begin(),s.end());
        f.emplace_back(s);
    }
    string ans = "";
    for(int i = 0;i<len;++i){
        char last = f[0][i];
        int sym = 1;
        for(string s:f){

            if(s[i]!=last) {
                sym = 0;
                break;
            }
        }
        if(sym) {
            ans += last;
        }else{
            break;
        }
    }
    if(ans == "") {
        cout<<"nai";
        return 0;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}