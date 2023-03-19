//
// Created by Dell on 2022-03-20.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string>f;
bool cmp(string &a,string &b){

    return a + b < b + a;;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        string a;
        cin>>a;
        f.push_back(a);
    }
    sort(f.begin(),f.end(),cmp);
    string ans = "";
    for(string a:f){
        ans += a;
    }
    while(ans.size()&&ans[0] == '0'){
        ans = ans.substr(1);
    }
    if(ans.size()==0){
        ans ="0";
    }
    cout<<ans;
    return 0;
}