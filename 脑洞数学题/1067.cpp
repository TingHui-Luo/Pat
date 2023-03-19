//
// Created by Dell on 2022-04-02.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace  std;

int n;
vector<int>Map(500000,0);
int main(){
    cin>>n;

    int count = 0;
    for(int i = 0;i<n;++i){
        int tem;cin>>tem;

        Map[tem]  = i;
        if(tem != i && tem!=0){
            ++count;
        }
    }
    int k = 1,ans = 0;
    while(count){
        if(Map[0] == 0){
            while(k<n){
                if(Map[k] !=k){
                    swap(Map[k],Map[0]);
                    ++ans;
                    break;
                }
                ++k;
            }
        }
        while(Map[0]!=0){
            swap(Map[0],Map[Map[0]]);
            ++ans;
            --count;
        }
    }


    cout<<ans;
    return  0;
}