// Created by Dell on 2022-03-23.
//

#include <iostream>
#include <map>


using namespace std;
map<char ,int>Map;


int main(){
    string a,b;
    getline(cin,a,'\n');
    getline(cin,b,'\n');
    swap(a,b);
    map<char,int>::iterator it;
    for(auto c:a){
        Map[c] = 1;
    }
    string ans = "";
    for(auto c:b){
        if(Map[c]) continue;
        ans +=c;
    }

    for(it = Map.begin();it!=Map.end();++it){
        cout<<it->first;
    }
    cout<<ans;

    return 0;
}