// Created by Dell on 2022-03-13.
//

#include <iostream>
#include <vector>

using namespace std;
int n,base;

vector<int>ans;

void zhuan(int x){
    while(x){
        ans.push_back(x%base);
        x /= base;
    }
}

int main(){
    cin>>n>>base;
    if(n == 0){
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        return 0;
    }
    zhuan(n);
    string sym = "Yes";
    for(int i = 0;i<ans.size()/2;++i){
        if(ans[i] == ans[ans.size()-i-1]) continue;
        else{
            sym = "No";
            break;
        }
    }
    cout<<sym<< endl;
    for(int i = ans.size()-1;i>=0;--i){
        if(i!=0)cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    return 0;
}