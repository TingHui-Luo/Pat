

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

int n,m,k;
struct student{
    string id;
    int point,midTest=-1,finalTest=-1;
    int grade;
};
map<string,int>F;
vector<student>f;
bool cmp(const student& a,const student& b){
    if(a.grade!=b.grade) return a.grade>b.grade;
    return a.id<b.id;
}
int main(){
    n = read(),m = read(),k =read();
    for(int i = 0;i<n;++i){
        student tem;
        tem.id.resize(20);
        scanf("%s",tem.id.c_str());
        tem.point = read();
        F[tem.id] = f.size();
        f.emplace_back(tem);
    }
    for(int i = 0;i<m;++i){

        student tem;
        tem.id.resize(20);
        scanf("%s",tem.id.c_str());
        tem.midTest = read();
        if(F.find(tem.id) == F.end()) continue;
        f[F[tem.id]].midTest = tem.midTest;
    }
    for(int i = 0;i<k;++i){
        student tem;
        tem.id.resize(20);
        scanf("%s",tem.id.c_str());
        tem.finalTest = read();
        if(F.find(tem.id) == F.end()) continue;
        f[F[tem.id]].finalTest = tem.finalTest;
    }
    vector<student>ans;
    for(student tem:f){
        if(tem.point<200) continue;
        if(tem.midTest>tem.finalTest) {
            tem.grade = int(double(tem.midTest)*0.4 + double (tem.finalTest)*0.6 + 0.5);
        }else{
            tem.grade = tem.finalTest;
        }
        if(tem.grade<60) continue;
        ans.emplace_back(tem);
    }
    sort(ans.begin(),ans.end(),cmp);
    for(student tem:ans){
        printf("%s %d %d %d %d\n",tem.id.c_str(),tem.point,tem.midTest,tem.finalTest,tem.grade);
    }
    return 0;
}