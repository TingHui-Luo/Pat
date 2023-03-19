// Created by Dell on 2022-03-19.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;
int n;

map<char,char>Map;
vector<string>f;
int main(){

    Map['1'] = '@';Map['0'] = '%';
    Map['l'] = 'L';Map['O'] = 'o';

    cin>>n;



    for(int i = 0;i<n;++i){
        string a,b;
        cin>>a>>b;
        int sym = 0;
        for(char &c:b){
            if(Map.find(c) != Map.end()){
                c = Map[c];
                sym =1;
            }
        }
        if(sym){
            f.push_back(a+" "+b);
        }
    }
    if(f.size()){
        cout<<f.size()<<endl;
        for(auto c:f){
            cout<<c<<endl;
        }
    }else{
        if(n == 1){
            cout<<"There is 1 account and no account is modified";
        }else{
            cout<<"There are "<<n<<" account and no account is modified";
        }
    }

    return 0;
}