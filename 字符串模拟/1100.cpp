#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int n;

map<string,int>Map;
string ge[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

void work1(string s){
    int ans = 0;
    for(char c:s){
        ans = ans *10 + (c - '0');
    }
    string anss = "";
    if(ans/13){
        anss = shi[ans/13-1];
        if(ans%13 !=0)   anss =anss + " "+ge[ans%13];;
    }else{
        anss = ge[ans%13];
    }
//    if(ans%13 == 0) anss = anss.substr(1);
    cout<<anss<<endl;
}

void work2(string s){
    int ans = 0;
    int index = -1 ;
    for(int i = 0;i<s.size();++i){
        if(s[i] == ' '){
            index = i;
            break;
        }
    }

    if(index!=-1) {
        string s1 = s.substr(index + 1);
        for (int i = 0; i < 13; ++i) {
            if (ge[i] == s1) {
                ans += i;
                break;
            }
        }
        s = s.substr(0, 3);
        for(int i = 0;i<12;++i){
            if(shi[i] == s){
                ans += (i+1)*13;
                break;
            }
        }
    }else{
        int sym = 0;
        for (int i = 0; i < 13; ++i) {
            if (ge[i] == s) {
                sym = 1;
                ans += i;
                break;
            }
        }
        if(!sym){
            for(int i = 0;i<12;++i){
                if(shi[i] == s){
                    ans += (i+1)*13;
                    break;
                }
            }
        }
    }


    cout<<ans<<endl;
}

int main()
{
    n = read();
    for(int i = 0;i<n;++i){
        string s1;
        getline(cin,s1,'\n');
        if(s1[0]<='9'&&s1[0]>='0'){
            work1(s1);
        }else{
            work2(s1);
        }
    }
    return 0;
}