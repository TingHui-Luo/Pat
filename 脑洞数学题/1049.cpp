//
// Created by Dell on 2022-03-23.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
typedef long long ll;
int n;
vector<ll>base;
int main(){
    cin>>n;
    ll ans = 0,high,low,self,p=1;
    ll m = n;
    while(n){
        self = n%10;
        low = m%p;
        high =m/(p*10);
        if(self <1) ans += high*p;
        else if(self == 1) ans += high*p + low +1;
        else ans +=(high + 1) *p;

        p*=10;
        n/=10;
    }
    cout<<ans;
    return 0;
}
