

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m;
struct school{
    string school;
    int A=0,B=0,T=0;
    int grade;
    int number;
};
bool cmp(const school &a,const school &b){
    if(a.grade!=b.grade) return a.grade > b.grade;
    if(a.number !=b.number) return a.number<b.number;
    return a.school < b.school;
}
vector<school>f;
map<string,int>Map;
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        string a,c;
        int b;
        cin>>a;b =  read();cin>>c;

        for(char &cc:c) cc = tolower(cc);
        if(Map.find(c)!=Map.end()){
            if(a[0] == 'A') {
                f[Map[c]].A += b;
            }else if(a[0] == 'B'){
                f[Map[c]].B  +=b;
            }else{
                f[Map[c]].T +=b;
            }
            f[Map[c]].number++;
        }else{
            school tem;
            tem.school = c;
            if(a[0] == 'A') {
                tem.A += b;
            }else if(a[0] == 'B'){
                tem.B  +=b;
            }else{
                tem.T +=b;
            }
            tem.number = 1;
            Map[c] = f.size();
            f.emplace_back(tem);
        }
    }
    for(school &a:f){
        a.grade = a.B/1.5 + a.A + a.T*1.5;
    }
    sort(f.begin(),f.end(),cmp);
    cout<<f.size()<<endl;
    int rank = 0,last = -1,add = 1;
    for(school a:f){
        if(a.grade == last){
            cout<<rank<<" "<<a.school<<" "<<a.grade<<" "<<a.number<<endl;
            ++add;
        }else{
            rank += add;
            cout<<rank<<" "<<a.school<<" "<<a.grade<<" "<<a.number<<endl;
            add = 1;
        }
        last = a.grade;
    }
    return 0;
}

