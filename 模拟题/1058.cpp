//
// Created by Dell on 2022-03-28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>f1,f2;
int zhuan(string s){
    int ans = 0;
//    cout<<s;
    for(auto c:s){
        ans = ans* 10+(c-'0');
    }
//    cout<<ans<<endl;
    return ans;
}
int main(){
    string a,b;
    cin>>a>>b;
    int last = 0;
    for(int i = 0;i<a.size();++i){
        if(a[i] == '.') {f1.push_back(zhuan(a.substr(last,i-last)));last = i+1;}
    }
    f1.push_back(zhuan(a.substr(last,a.size()-last)));
    last = 0;
    for(int i = 0;i<b.size();++i){
        if(b[i] == '.') {f2.push_back(zhuan(b.substr(last,i-last)));last = i+1;}
    }
    f2.push_back(zhuan(b.substr(last,b.size()-last)));


    for(int i = 2;i>=0;--i){
        f1[i] += f2[i];
        if(i == 2) {f1[i-1] += f1[i]/29;f1[i] %= 29;}
        if(i == 1){ f1[i-1] += f1[i]/17;f1[i] %= 17;}
    }
    string ans ="";
    for(int i:f1){
        ans += '.'+ to_string(i);
    }
    cout<<ans.substr(1);
    return 0;
}

