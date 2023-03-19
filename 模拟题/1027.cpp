//
// Created by Dell on 2022-03-13.
//
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string zhuan(int num){
    string ans = "";
    while(num){
        if(num%13 > 9){
            ans += (num%13- 10) + 'A';
        }else{
            ans += num%13 +'0';
        }
        num /= 13;
    }
    while(ans.size()<2){
        ans += "0";
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string ans = "#";
    for(int i = 0;i<3;++i){
        int tem;cin>>tem;
        ans += zhuan(tem);

    }
    cout<<ans;
    return 0;
}