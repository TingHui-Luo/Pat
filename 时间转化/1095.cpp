//
// Created by Dell on 2022-04-10.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c=getchar();}
    while(c>='0'&&c<='9') {x = x*10+c-'0'; c= getchar();}
    return x*y;

}

int zhuan(string s){
    return (s[0]-'0')*10*60*60+ (s[1]-'0')*60*60+(s[3]-'0')*10*60+ (s[4]-'0')*60+(s[6]-'0')*10+ (s[7]-'0');
}

string zhuan(int x){
    string ans = "";
    ans += x/(10*60*60) + '0';
    x %= 10*60*60;
    ans += x/(60*60) + '0';
    x %= 60*60;
    ans += ":";
    ans += x/(10*60) + '0';
    x %= 10*60;
    ans += x/(60) + '0';
    x %= 60;
    ans += ":";
    ans += x/(10) + '0';
    x %= 10;
    ans += x +'0';
    return ans;
}
struct Record{
    string plate;
    int time;
    int sym = 0;
};
vector<Record>f;
vector<Record>f1;
map<string,int>LastIn;
bool cmp(const Record &a,const Record &b){
    return a.time<b.time;
}
vector<int>Time(90000,0);
vector<int>SumTime(90000,0);
map<string,int>Fair;
map<string,int>Stay;
vector<string>ans;
int main(){
    n = read();m =read();
    for(int i = 0;i<n;++i){
        Record a;
        string Ti,Sym;
        cin>>a.plate>>Ti>>Sym;
        a.time = zhuan(Ti);a.sym = (Sym == "in"?1:0);
        f.emplace_back(a);
        Fair[a.plate] = 0;
    }
    sort(f.begin(),f.end(),cmp);
    for(int i = 0;i<f.size();++i){
        Record a = f[i];
        if(Fair[a.plate] == 1 && a.sym == 1) {
            LastIn[a.plate] = i;
            continue;
        }
        if(Fair[a.plate] == 0 && a.sym == 0) continue;
        if(a.sym == 0){
            Fair[a.plate] = 0;
            f1.emplace_back(f[LastIn[a.plate]]);
            f1.emplace_back(a);
            Stay[a.plate] += a.time - f[LastIn[a.plate]].time;
        }else{
            LastIn[a.plate] = i;
            Fair[a.plate] = 1;
        }
    }
    f = f1;
    sort(f.begin(),f.end(),cmp);
    for(Record a:f){

        if(a.sym == 1){
            Time[a.time] += 1;
        }else{
            Time[a.time] -=1;
        }
    }
    SumTime [0] = Time[0];
    for(int i = 1;i<87000;++i){
        SumTime[i] = SumTime[i-1] + Time[i];
    }
    for(int i = 0;i<m;++i){
        string s;cin>>s;
        cout<<SumTime[zhuan(s)]<<endl;
    }
    int maxStay = 0;
    for(auto c:Stay){
        if(c.second>maxStay){
            maxStay = c.second;
            ans.clear();
            ans.emplace_back(c.first);
        }else if(c.second == maxStay){
            ans.emplace_back(c.first);
        }
    }
    sort(ans.begin(),ans.end());
    for(string s:ans){
        cout<<s<<" ";
    }
    cout<<zhuan(maxStay);
    return 0;
}