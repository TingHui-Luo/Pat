//
// Created by Dell on 2022-03-29.
//

#include <iostream>
#include <vector>

using namespace std;
vector<string>f;
string days[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

string ans = "";
int main(){
    int sym =0;
    for(int i = 0;i<4;++i) {
        string s;cin>>s;
        f.push_back(s);
    }
    for(int i = 0;i<min(f[0].size(),f[1].size());++i){
        if(f[0][i] == f[1][i] && ((f[0][i] >= 'A' &&f[0][i]<='Z')||(f[0][i] >= '0' &&f[0][i]<='9'))){
            string a = f[0];
            if(sym == 0 && (f[0][i] >= '0' &&f[0][i]<='9')) continue;
            if(sym == 0 && f[0][i] >'G') continue;
            if(sym && f[0][i] >'N') continue;
            if(sym == 0) {ans += days[a[i]-'A']+" ";sym = 1;}
            else{
                if(!(f[0][i] >= '0' &&f[0][i]<='9'))
                {
                    ans += to_string(a[i]-'A'+10)+":";
                }
                else{

                    string s = "";
                    s += f[0][i];
                    ans+= "0"+s+":";
                }
                break;
            }
        }
    }
    for(int i = 0;i<min(f[2].size(),f[3].size());++i){
        if(f[2][i] == f[3][i]&&((f[2][i]>='a'&&f[2][i]<='z')||(f[2][i]>='A'&&f[2][i]<='Z'))){
            string a = to_string(i);
            while(a.size() != 2) a = "0"+a;
            ans+= a;
            break;
        }
    }
    cout<<ans;
    return 0;
}

