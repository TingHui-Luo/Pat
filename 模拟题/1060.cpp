//
// Created by Dell on 2022-03-29.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
int f[2];
string chuli(string x,int index){

    string ans = "";
    int num = 0;
    for(auto c:x){
        if(c=='.') {continue;}
        ans += c;
        ++num;
        if(num == n) break;
    }
    while(ans.size()!=n) ans+="0";
    return ans;
}

int main(){
    cin>>n;
    string a,b;
    cin>>a>>b;
    while(a.size()&&a[0] == '0'){
        a = a.substr(1);
    }
    while(b.size()&&b[0] == '0'){
        b = b.substr(1);
    }
    f[0] = a.size();
    for(int i = 0;i<a.size();++i){
        if(a[i] == '.') {
            if(i!=0) {f[0] = i;break;}
            else{
                a = a.substr(1);

                f[0] = 0;
                while(i<a.size()&&a[i]=='0'){
                    f[0]--;
                    ++i;
                }
                if(i == a.size()) f[0] = 0;
            }
        }
    }
    f[1] = b.size();
    for(int i = 0;i<b.size();++i){
        if(b[i] == '.') {
            if(i!=0) {f[1] = i;break;}
            else{
                b = b.substr(1);
                f[1] = 0;
                while(i<b.size()&&b[i]=='0'){
                    f[1]--;
                    ++i;
                }
                if(i == b.size()) f[1] = 0;
            }
        }
    }
    while(a.size()&&a[0] == '0'){
        a = a.substr(1);
    }
    while(b.size()&&b[0] == '0'){
        b = b.substr(1);
    }
    a = chuli(a,0);
    b = chuli(b,1);
    a = "0."+a+"*10^"+ to_string(f[0]);
    b ="0."+b+"*10^"+ to_string(f[1]);
    if(a == b){
        cout<<"YES"<<" "<<a;
    }else{
        cout<<"NO"<<" "<<a<<" "<<b;
    }
    return 0;
}