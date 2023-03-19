

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
#include <math.h>
using namespace std;
typedef long long ll;

string s,s1;
map<char,int>Map;

int main(){
    getline(cin,s,'\n');
    getline(cin,s1,'\n');
    for(char c:s1){
        Map[c] = 1;
    }
    vector<char>ans;
    for(char c:s){
        if(Map[c] == 0){
            Map[c] = 1;Map[toupper(c)] = 1;Map[tolower(c)] = 1;
            ans.emplace_back(toupper(c));
        }
    }
    for(char c:ans) cout<<c;
    return 0;
}