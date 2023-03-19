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
int n ;
vector<int>f(1100);
vector<int>firstHobby(1100);
int find(int x){
    int a = x;
    while(x != f[x]){
        x = f[x];
    }
    while(a != f[a]){
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

int zhuan(string s){
    int x= 0;
    for(char c:s){
        x = x * 10 + c-'0';
    }
    return  x;
}
int main(){
    for(int i = 0;i<1100;++i) {
        f[i] = i;
        firstHobby [i] = -1;
    }
        n = read();
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        int number = zhuan(s.substr(0,s.size()-1));
        for(int j = 0;j<number;++j){
            int tem = read();
            if(firstHobby[tem] == -1) {firstHobby[tem] = i;}
            else {
                if(find(i) != find(firstHobby[tem])){
                    f[find(i)] = find(firstHobby[tem]);
                }
            }
        }

    }

    map<int,int>Map;
    for(int i = 0;i<n;++i){
        Map[find(i)] += 1;
    }
    vector<int>ans;
    for(auto c:Map){
        ans.emplace_back(c.second);
    }
    sort(ans.begin(),ans.end(),greater<>());
    cout<<Map.size()<<endl;
    if(Map.size()){
        cout<<ans[0];
        for(int i = 1;i<ans.size();++i)
        {
            cout<<" "<<ans[i];
        }
    }
    return 0;
}
