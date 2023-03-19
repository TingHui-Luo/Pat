//
// Created by Dell on 2022-03-29.
//

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,index;
vector<int>f,ans;

void inorder(int x){
    if(x>=n) return;
    inorder(2*x+1);
    ans[x] = f[index++];
    inorder(2*x +2);
}
int main(){
    cin>>n;

    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        f.push_back(tem);
    }
    ans.assign(n,0);
    sort(f.begin(),f.end());
    inorder(0);


    cout<<ans[0];
    for(int i =1;i<n;++i){
        cout<<" "<<ans[i];
    }

    return  0;
}