

//
// Created by Dell on 2022-04-10.
//
#include <iostream>
#include <vector>

using namespace std;
const int mod = 1000000007;

int main(){
    string s;
    cin>>s;
    int len = s.size();
    vector<int>P(len+1,0);
    vector<int>T(len+1,0);

    if(s[0] == 'P') {
        P[0] = 1;
    }else if(s[0] == 'T'){
        T[0] = 1;
    }

    for(int i = 1;i<len;++i){
        if(s[i] == 'P'){
            P[i] = P[i-1] + 1;
        }else{
            P[i] = P[i-1];
        }

        if(s[i] == 'T'){
            T[i] = T[i-1] + 1;
        }else{
            T[i] = T[i-1];
        }
    }
    long long  ans = 0;
    for(int i = 0;i<len;++i){
        if(s[i] == 'A'){
            ans += P[i]*(T[len-1]-T[i])%mod;
        }
    }
    cout<<ans%mod;
    return 0;
}