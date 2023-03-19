// Created by Dell on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000000;
int prime[maxn];int num = 0;
bool isHe[maxn] = {false};


void getprime(){
    for(int i = 2;i<maxn;++i){
        if(isHe[i]) continue;
        prime[num++] = i;
        for(int j = 2*i;j<maxn;j+=i){
            isHe[j] = 1;
        }
    }
}

string itoaa(int x,int a){
    string ss= "";

    while(x){
        ss += (x%a+'0');
        x /= a;
    }
    reverse(ss.begin(),ss.end());
    return ss;
}
int main(){
    getprime();
    isHe[1] = true;
    int tem;
    while(cin>>tem){
        if(tem<0) return 0;
        int a ;cin>>a;
        int ans = 0;


        string s = itoaa(tem,a);
        reverse(s.begin(),s.end());
//        cout<<s<<endl;
        for(int i=s.length()-1;i>=0;--i){
            ans += pow(a,s.length()-i-1)*(s[i]-'0');
        }
            if(isHe[tem] == false && isHe[ans] == false){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }

    return 0;
}