#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n;

char f[26][8][6];
int main(){

    for(int i = 0;i<26;++i){
        for(int j = 0;j<7;++j){
            for(int k = 0;k<5;++k){
                f[i][j][k] = getchar();
            }
            getchar();
        }
    }
    string s;
    getline(cin,s);

    vector<string>ans;
    int last = 0;
    for(int i = 0;i<s.size();++i){
        if(s[i]>'Z'||s[i]<'A'){
            if(i==last) {
                last = i+1;
                continue;
            }
            ans.emplace_back(s.substr(last,i - last));
            last = i+1;

        }
    }

    if(last !=s.size()) ans.emplace_back(s.substr(last,s.size() - last));
    int indexans = 0;
    for(const string& ss:ans){
        ++indexans;
        char ff[100][8][6] = {'-'};
        int index = 0;

        for(char c:ss){
            for(int i = 0;i<7;++i) {
                for (int j = 0; j < 5; ++j) {
                    ff[index][i][j] = f[c-'A'][i][j];

                }
            }
            ++index;
        }
        char ans1[8][200];
        for(int i = 0;i<8;++i){
            for(int j = 0;j<200;++j){
                ans1[i][j] = ' ';
            }
        }
        int row = 0;
        for(int i = 0;i<index;++i){
            for(int j=0;j<7;++j){
                for(int k = 0;k<5;++k){
                    ans1[j][k+row] =  ff[i][j][k];

                }

            }
            row += 6;
        }

        for(int i = 0;i<7;++i){   string sss = "";
            for(int j = 0;j<row-1;++j){
                sss += ans1[i][j];

            }
            cout<<sss<<endl;
        }

        if(indexans != ans.size()) cout<<endl;
    }
    return 0;
}


