//
// Created by Dell on 2022-04-02.
//
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
string s;
map<char,int>Map;
map<string,int>ans;


string Mytolower(string s){
    for(char &c:s){
        c = tolower(c);
    }
    return s;
}
int main(){
    getline(cin,s,'\n');
    for(int i = 0;i<=9;++i){
        Map[char(i+'0')] = 1;
    }

    for(int i = 0;i<=25;++i){
        Map[char(i+'a')] = 1;
        Map[char(i +'A')] = 1;
    }
    string tems = "";
    for(int i = 0;i<s.size();++i){
        if(Map[s[i]]){
            tems += s[i];
        }else{
            if(tems!="") {
                ans[Mytolower(tems)] += 1;
                tems = "";
            }
        }
    }
    if(tems!="") {
        ans[Mytolower(tems)] += 1;
        tems = "";
    }
    map<string,int>::iterator it1;
    string anss;int maxn = 0;
    for(it1 = ans.begin();it1 !=ans.end();++it1){
        if(maxn < it1->second){
            maxn = it1->second;
            anss = it1->first;
        }
    }
    cout<<anss<<" "<<maxn;
    return 0;
}
