

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
#include <stack>
using namespace std;
typedef long long ll;

inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1;c = getchar();}
    while(c>='0'&&c<='9') { x = x*10+c - '0';c=getchar();}
    return x*y;
}

ll gcd(ll a,ll b){
    return !b?a: gcd(b,a%b);
}

void func(ll up,ll down){
    if(down == 0){
        cout<<"Inf";return;
    }
    bool flag = 0;
    if(up>0&&down<0||up<0&&down>0){
        flag = 1;cout<<"(-";
    }
    up = abs(up);down = abs(down);
    ll gcdd = gcd(up,down);
    up /= gcdd; down/= gcdd;
    if(down == 1) cout<<up;
    else{
        if(up/down >0) cout<< up/down <<" ";
        cout<<up%down<<"/"<<down;
    }
    if(flag) cout<<")";
}

int main(){
    ll a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);

    func(a, b); cout << " + "; func(c, d); cout << " = "; func(a*d + b * c, b*d); cout << endl;
    func(a, b); cout << " - "; func(c, d); cout << " = "; func(a*d - b * c, b*d); cout << endl;
    func(a, b); cout << " * "; func(c, d); cout << " = "; func(a * c, b*d); cout << endl;
    func(a, b); cout << " / "; func(c, d); cout << " = "; func(a*d, b*c); cout << endl;
    return 0;
}
