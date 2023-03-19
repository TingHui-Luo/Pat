//
// Created by Dell on 2022-03-13.
//

#include <iostream>
#include <algorithm>

using namespace std;
int m1[20],m2[20];
string s;
int number[100];
int main(){
    cin>>s;
    reverse(s.begin(),s.end());
    int n = s.size();
    int temn = n;
    for(int i = 0;i<s.size();++i){
        number[i] = s[i] -'0';
        m1[number[i]] +=1;
    }
    int c= 0;
    for(int i =0;i<n;++i){
        number[i] =(number[i]*2 + c);
        c = number[i] /10;
        number[i] %=10;
        m2[number[i]] +=1;
    }

    while(c){
        number[n] =(number[n] + c);
        c = number[n] /10;
        number[n] %=10;
        m2[number[n]] +=1;
        ++n;
    }

        int sym = 1;
        for(int i = 0;i<=9;++i){
            if(m1[i]!=m2[i]) {sym = 0;break;}
        }
        if(sym){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    for(int i = n-1;i>=0;--i){
        cout<<number[i];
    }
    return 0;
}