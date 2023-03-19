//
// Created by Dell on 2022-03-06.
//

#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    int ans = 0,nowT = 0;
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        if(tem>nowT){
            ans += (tem-nowT)*6 + 5;

        }else if(tem < nowT){
            ans += (nowT - tem )* 4 + 5;
        }else{
            ans += 5;
        }
        nowT = tem;
    }
    cout<<ans;
    return 0;
}