//
// Created by Dell on 2022-03-06.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>f = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(char ss:s){
        ans += ss-'0';
    }
    string ss = to_string(ans);
    for(int i = 0;i<ss.size();++i){
        if(i!=ss.size()-1){
            cout<<f[ss[i]-'0']<<" ";
        }else{
            cout<<f[ss[i]-'0'];
        }
    }
    return 0;
}