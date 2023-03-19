//
// Created by Dell on 2022-03-04.
//
#include <iostream>
#include <string>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int ans = a + b;
    string anss = "";
    string s = to_string(ans);
    if(s[0] == '-') {anss += '-';
    s = s.substr(1);}
    if(s.length()>3&&s.length()<=6){
        s = s.substr(0,s.size()-3) + "," + s.substr(s.size()-3);
    }
    else if(s.length()>6){

        s = s.substr(0,s.size()-6)+","+s.substr(s.size()-6,s.size()-3 - (s.size()-6)) + "," + s.substr(s.size()-3);
    }
    cout<<anss + s;
    return 0;
}
