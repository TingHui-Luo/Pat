//
// Created by Dell on 2022-04-02.
//

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int sym,sym1;
int main(){
    string s;
    cin>>s;
    if(s[0] == '-') sym =1;
   s =  s.substr(1);
    double ans = 0.0;

    ans += s[0] -'0';
   s =  s.substr(2);
    double xiaoshu = 0.0;
    double q = 0.1;
    int i;

    for(i = 0;i<s.size();++i){
        if(s[i] == 'E' ) break;
        xiaoshu += float (s[i] - '0') * q;
        q *= 0.1;
    }

    int weishu = i,tarilzero = 0;
    for(int j = i-1;j>=0;--j){
        if(s[j] != '0') break;
        ++tarilzero;
    }

//    cout<<ans <<" "<<xiaoshu<<endl;
    ans += xiaoshu;
    s = s.substr(i+1);
    if(s[0] == '-') sym1 = 1;
    s = s.substr(1);
    int exponent = 0;
    for(i = 0;i<s.size();++i){
        exponent = exponent*10 + (s[i] - '0');
    }

    if(sym1){
        ans = ans * (pow(0.1,exponent));
        weishu += exponent + 2;
    }else{
        ans = ans * (pow(10,exponent));
        if(weishu > exponent){
            weishu += 2;
        }else{
            weishu = exponent + 1;
        }
    }
    if(sym) cout<<'-';
    string ss = to_string(ans);
    if(ss.size()<weishu){
        while(ss.size()<weishu)
        ss = ss + '0';
    }else if(ss.size() > weishu){
        ss = ss.substr(0,weishu);
    }
        cout<<ss;
    return  0;
}