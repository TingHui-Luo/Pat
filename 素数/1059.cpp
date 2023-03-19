//
// Created by Dell on 2022-03-29.
//

#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll n;
vector<int>prime;
vector<bool>isHe;
void getprime(){
    for(int i = 2;i<=n;++i){
        if(isHe[i] == 0) {
            prime.push_back(i);
            for (int j = 2*i; j <= n; j += i) {
                isHe[j] = true;
            }
        }
    }
}
bool isPrime(int n)
{
    if(n == 1) return false;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0) return false;
    }
    return true;
}

map<int,int>Map;
int main(){
    cin>>n;
    isHe.assign(n+1,0);
    ll temn = n;
    int i = 0;

    while(n!=1){

        for (int i = 2; i <= n; ++i)
        {
            if(isPrime(i) && n % i == 0)
            {
                Map[i]++;
                n /= i;
                break;
            }

        }
    }
    cout<<temn<<"=";
    if(temn == 1) {cout<<1;return 0;}
    int sym = 0;
    for(auto c:Map){
        if(sym) cout<<"*";
        if(c.second>1) cout<<c.first<<"^"<<c.second;
        else cout<<c.first;
        sym =1;
    }
    return 0;
}