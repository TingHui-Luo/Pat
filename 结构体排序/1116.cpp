
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}
int n;
map<int,int>primes;
vector<int>isHe(10000,0);
void prime(){
    const int maxn = 10000;
    for(int i = 2;i<maxn;++i){
        if(isHe[i]) continue;
        else{
            primes[i] = 1;
            for(int j = 2*i;j<maxn;j+=i){
                isHe[j] = 1;
            }
        }
    }
}

map<int,int>ranks;
map<int,int>checks;
int main(){
    n = read();
    prime();
    for(int i = 0;i<n;++i){
        int tem = read();
        ranks[tem] = i+1;
    }
    int k = read();
    for(int i = 0;i<k;++i){
        int tem = read();
        string s = to_string(tem);
        while(s.size()!=4) s = "0"+s;
        cout<<s<<": ";
        if(ranks.find(tem) == ranks.end()){
            cout<<"Are you kidding?"<<endl;
        }
        else if(checks[tem] == 1){
            cout<<"Checked"<<endl;
        }
        else if(ranks[tem] == 1) {
            cout<<"Mystery Award"<<endl;
            checks[tem] = 1;
        }else if(primes[ranks[tem]] == 1){
            cout<<"Minion"<<endl;
            checks[tem] = 1;
        }else{
            cout<<"Chocolate"<<endl;
            checks[tem] = 1;
        }
    }
    return 0;
}