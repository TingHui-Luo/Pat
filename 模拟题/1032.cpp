//
// Created by Dell on 2022-03-17.
//
#include <iostream>
#include <map>

using namespace std;

map<string,int>Map;
map<string,string>f;
int main(){
    string a,b;
    int n;
    cin>>a>>b>>n;
    for(int i = 0;i<n;++i){
        string a,b,c;
        cin>>a>>b>>c;
        f[a] = c;
    }

    while(a!="-1"){
        Map[a] = 1;
        a = f[a];
    }
    string comm;
    while(b!="-1"){
        if(Map.find(b) != Map.end()){
            cout<<b;
            return 0;
        }
        b = f[b];
    }
    cout<<-1;
    return 0;
}

