//
// Created by Dell on 2022-03-23.
//

#include <iostream>
#include <vector>

using namespace std;

int n,m;
int main(){
    cin>>n;
    vector<int>sum(n+1,0);
    for(int i = 1;i<=n;++i){
        int tem;cin>>tem;
        sum[i] += sum[i-1] + tem;
    }
    cin>>m;
    for(int i = 0;i<m;++i){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        cout<<min((sum[b-1]-sum[a-1]),sum[n]-sum[b-1]+sum[a-1])<<endl;
    }
    return 0;
}