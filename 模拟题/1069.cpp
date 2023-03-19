//
// Created by Dell on 2022-04-02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int>f;

int check(vector<int>f){
    int ans = 0;
    for(int i:f){
        ans = ans * 10 + i;
    }
    return ans;
}

int getnum(string s){
    int ans = 0;
    for(char c:s){
        ans = ans * 10 + (c-'0');
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    while(s.size()!=4){
        s = "0" + s;
    }
    for(char c:s){
        f.push_back(c-'0');
    }
    if(f[0] == f[1] && f[1] == f[2] && f[2] ==f[3]){
        cout<<s<<" - "<<s<<" = "<<"0000"<<endl;
        return 0;
    }
    int sym = 0;
    while(check(f)!=6174||!sym){
        sym = 1;
        sort(f.begin(),f.end());
        string s1 = "",s2 = "";
        for(int i = 0;i<4;++i){
            s1 += f[4-i-1]+'0';
            s2 += f[i] + '0';
        }
        int num = getnum(s1) - getnum(s2);
        s = to_string(num);
        while(s.size()!=4){
            s = "0" + s;
        }
        f.clear();
        for(char c:s){
            f.push_back(c-'0');
        }
        cout<<s1<<" - "<<s2<<" = "<<s<<endl;
    }
    return 0;

}