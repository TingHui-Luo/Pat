//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}
int n,m,k;
struct student{
    int GE,GI;
    int id;
    double grade;
    vector<int>Prefer;
};
vector<int>ans[110];
bool cmp(const student&a, const student&b){
    if(a.grade!=b.grade) return a.grade>b.grade;
    if(a.GE!=b.GE) return a.GE>b.GE;
    return a.id<b.id;
}
vector<int>Quota;
vector<student>f;
int main(){
    n =read(); m = read(); k = read();
    for(int i = 0;i<m;++i){
        int tem = read();
        Quota.emplace_back(tem);
    }
    for(int i = 0;i<n;++i){
        student a;
        a.GE = read();a.GI =read();
        a.grade = (double (a.GE) + double (a.GI) )/ 2.0;
        for(int j = 0;j<k;++j){
            int tem = read();
            a.Prefer.emplace_back(tem);
        }
        a.id = i;
        f.emplace_back(a);
    }
    sort(f.begin(),f.end(),cmp);
    double lastGrade =-1.0,lastGe = 0.0,lastSchool;
    for(int i = 0;i<n;++i){
        if(lastGrade == f[i].grade && lastGe == f[i].GE){
            for(int school:f[i].Prefer){
                if(Quota[school]>0 || (Quota[school] == 0 && lastSchool == school)){
                    ans[school].emplace_back(f[i].id);
                    if(Quota[school] >0) Quota[school]--;
                    break;
                }
            }
        }else{
            for(int school:f[i].Prefer){
                if(Quota[school]>0){
                    ans[school].emplace_back(f[i].id);
                    lastSchool = school;
                    Quota[school]--;
                    break;
                }
            }
        }

        lastGrade = f[i].grade;
        lastGe = f[i].GE;
    }
    for(int i = 0;i<m;++i){
        sort(ans[i].begin(),ans[i].end());

        if(ans[i].size() == 0) {
            cout<<endl;
        }
        else{
            cout<<ans[i][0];
            for(int j = 1;j<ans[i].size();++j){
                printf(" %d",ans[i][j]);
            }
            cout<<endl;
        }
    }
    return 0;
}