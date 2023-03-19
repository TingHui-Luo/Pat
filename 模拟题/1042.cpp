//
// Created by Dell on 2022-03-20.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int k;
vector<string>f;
vector<int>xi;
char s1[5]={'S','H','C','D','J'};
int main(){
    cin>>k;
    for(int i = 0;i<5;++i){

        for(int j =1;j<=13;++j){
            f.push_back(s1[i] + to_string(j));
        }
    }
    for(int i = 1;i<=11;++i) f.pop_back();
    for(int i = 0;i<54;++i){
        int tem;cin>>tem;
        xi.push_back(tem);
    }
    for(int i = 0;i<k;++i){
        vector<string>f1(54);
        for(int j= 0;j<54;++j){

            f1[xi[j]-1] = f[j];
        }
        f =f1;
    }
    for(int i = 0;i<53;++i){
        cout<<f[i]<<" ";
    }
    cout<<f[53];
    return 0;
}
