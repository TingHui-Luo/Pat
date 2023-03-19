//
// Created by Dell on 2022-03-13.
//

#include <iostream>
#include <algorithm>

using namespace std;
string s;
int number[1000];
int number2[1000];

int main(){
    cin>>s;
    reverse(s.begin(),s.end());
    int n = s.size();
    for(int i = 0;i<s.size();++i){
        number[i] = s[i] -'0';
        number2[i] = s[n-i-1] -'0';
    }
    int sym = true;
    for(int i = 0;i<=n/2;++i){
        if(number[i]!=number[n-i-1]) {
            sym = false;
            break;
        }
    }

    if(sym){
        for(int i = n-1;i>=0;--i) cout<<number[i];

        cout<<endl<<0;
        return 0;
    }
    int k;
    cin>>k;
    int temk = k;
    while(k) {
        for (int i = 0; i < n; ++i) {
            number[i+1] += (number[i]+number2[i])/10;
            number[i] =  (number[i]+number2[i])%10;
        }

        while (number[n]) {
            number[n+1] = number[n]/10;
            number[n] %= 10;
            ++n;
        }
        for(int i = 0;i<n;++i){
            number2[i] = number[n-i-1];
        }
        --k;
        int sym = true;
        for(int i = 0;i<=n/2;++i){
            if(number[i]!=number[n-i-1]) {
                sym = false;
                break;
            }
        }

        if(sym){
            for(int i = n-1;i>=0;--i) cout<<number[i];

            cout<<endl<<temk - k;
            return 0;
        }
    }
    for(int i = 0;i<n;++i) cout<<number2[i];
    cout<<endl<<temk;
    return 0;
}