//
// Created by Dell on 2022-03-14.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int>f1;
vector<int>f2;
int n,m;

int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        int tem;cin>>tem;
        f1.push_back(tem);
    }
    cin>>m;
    for(int i = 0;i<m;++i){
        int tem;cin>>tem;
        f2.push_back(tem);
    }
    f1.push_back(1e8);f2.push_back(1e8);
    int left = 0,right = 0,index = (n + m -1 )/2;
    while(left + right < index){
        if(f1[left] < f2[right]){
            ++left;
        }else{
            ++right;
        }
    }
    cout<<min(f1[left],f2[right]);
    return 0;
}
