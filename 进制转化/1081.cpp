

//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}
vector<ll>fenzi,fenmu;
vector<ll>vis;

ll zhuan(string s){
    ll ans = 0;
    for(ll i = 0;i<s.size();++i){
        ans = ans * 10 + ll(s[i] - '0');
    }
    return ans;
}
long long gcd(ll m, ll n)//辗转相除法求最大公因子
{
    if(m>n) swap(m,n);
    while (n!=0) {
        ll r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main(){
    ll n =read();


    for(ll i = 0;i<n;++i){
        string s;
        cin>>s;
        ll j,sym = 0;
        if(s[0] == '-') {sym =1;
            s = s.substr(1);}
        for(j = 0;j<s.size();++j){
            if(s[j] == '/') break;
        }
        vis.emplace_back(sym);

        fenmu.emplace_back(zhuan(s.substr(j+1)));
        fenzi.emplace_back(zhuan(s.substr(0,j)));

    }

    ll b  = fenmu[0];
    for(ll i = 1;i<fenmu.size();++i){
        b = (b*fenmu[i])/gcd(b,fenmu[i]);
    }

    ll a = 0;
    for(ll i = 0;i<fenzi.size();++i){

        if(vis[i] == 1){


            a -= fenzi[i]* (b/fenmu[i]);

        }else{
            a += fenzi[i]* (b/fenmu[i]);
        }
    }
    ll sym1 = 0;

    if(a <0 ) {
        sym1 = 1;
        a = abs(a);
    };
    ll zhengshu = a/b,fenshu = a%b;
    ll gcdd = gcd(fenshu,b);
    fenshu /= gcdd;
    b /= gcdd;
    if(zhengshu == 0&& fenshu == 0) {
        cout<<0;
        return 0 ;
    }
    if(zhengshu >0){
        if(fenshu!=0) {

            cout << zhengshu << " ";
        }
        else {
            if (sym1) cout << "-";
            cout<<zhengshu;
        }
    }

    if(fenshu!=0) {
        if(sym1 == 1) cout<<"-";
        cout<<fenshu<<"/"<<b;
    }
    return 0;
}