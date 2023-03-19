//
// Created by Dell on 2022-03-06.
//

#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int zhuan(string s){
    return ((s[0]-'0')*10 + (s[1]-'0'))*3600 + ((s[3]-'0')*10 + (s[4]-'0'))*60 +((s[6]-'0')*10 + (s[7]-'0'));
}
int maxn = 0,minn = 3600*24;
string ans1,ans2;
int main(){

    int n;
    cin>>n;
    cin.get();
//    stringstream ss;
//    ss << a;
//    ss >> res;
    for(int i = 0;i<n;++i){
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        if(zhuan(s2) < minn){
            ans1 = s1;
            minn = zhuan(s2);
        }
        if(zhuan(s3)>maxn){
            ans2 = s1;
            maxn = zhuan(s3);
        }
    }
    cout<<ans1<<" "<<ans2;

    return 0;
}