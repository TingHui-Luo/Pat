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
double zhuan(string s){
    double ans = 0;
    for(char c:s){
        ans =ans *10+ c-'0';
    }
    return ans;
}
vector<string>f;
map<string,int>Map;
int main(){
    n = read();
    double temans = 0.0;
    int number = 0;
    for(int i = 0;i<n;++i) {
        string s = "";
        cin >> s;
        f.emplace_back(s);
        int sym = 0, dian = 0, index = 0,fu = 0;
        for (char c: s)
        {
            if ((!(c <= '9' && c >= '0'))) {
                if (c == '.') {
                    if(dian) sym = 1;
                    dian = index;
                    ++index;
                continue;
                }
                if(c == '-') {
                    if(fu) sym = 1;
                    fu = 1,++index;continue;
                }
                sym = 1;
                break;
            }
            ++index;
        }
        if(sym) continue;
        if(fu){
            s = s.substr(1);
            if(dian) --dian;
        }
        double ans = 0;
        if(dian){
            if(s.size()-dian > 3) continue;
            ans += zhuan(s.substr(0,dian));
            ans += zhuan(s.substr(dian+1))*pow(0.1,s.size()-1-dian);
        }else{
            ans += zhuan(s);
        }

        if(fu) ans = -ans;
        if(ans>1000||ans<-1000) continue;
        temans += ans;
        number++;
        if(fu) s = "-"+s;
        Map[s] = 1;

    }
    for(const string& s1:f){
        if(Map[s1] == 1) continue;
        else {
            cout<<"ERROR: "<<s1<<" is not a legal number"<<endl;
        }
    }
    if(number){
        if(number == 1)cout<<"The average of "<<number<<" number is ";
        else cout<<"The average of "<<number<<" numbers is ";
        printf("%.2lf\n",(temans/number));
    }else{
        cout<<"The average of 0 numbers is Undefined";
    }
    return 0;
}
