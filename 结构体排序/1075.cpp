

//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n,m,k;
struct student{
    string id;
    vector<int>score;
    vector<int>grade;
    int sumsolve;
    int sum;
    student(){
        score.assign(6,0);
        grade.assign(6,-1);
        sum = 0;
        id = "";
    }
};
inline int read(){
    int x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y=-1; c = getchar();}
    while(c>='0'&&c<='9') {x = x * 10 + c-'0'; c= getchar();}
    return x*y;
}

vector<student>f;
vector<int>problem_score;
map<string,int>Map;

int zhuan(string s){
    int ans = 0;
    for(char c:s){
        ans = ans * 10 + int (c-'0');
    }
    return ans;
}

bool cmp(const student &a,const student &b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    if(a.sumsolve != b.sumsolve) return a.sumsolve>b.sumsolve;
    return zhuan(a.id) < zhuan(b.id);
}

int main(){
    n =read();m= read();k =read();
    vector<int>vis1(n+1,0);
    vector<int>vis2(n+1,0);
    for(int i = 0;i<m;++i){
        int tem; tem = read();
        problem_score.emplace_back(tem);
    }
    for(int i = 0;i<k;++i){
        string a;
        int b,c;
        cin>>a;
        b = read();c = read();
        if(c == -1) {
            c = 0;
            if(Map.find(a) == Map.end()){
                vis1[f.size()] +=1;
            }else{
                vis1[Map[a]] += 1;
            }

        }
        if(Map.find(a) == Map.end()){
            vis2[f.size()] +=1;
        }else{
            vis2[Map[a]] += 1;
        }

        if(Map.find(a) == Map.end()){

            student ss;
            ss.id = a;

            if(c == problem_score[b-1]) {
                ss.score[b-1] = 1;
            }
            ss.grade[b-1] = c;
            Map[a] = f.size();

            f.emplace_back(ss);

        }else{

            if(c == problem_score[b-1]) {
                f[Map[a]].score[b-1] = 1;
            }
//            if(a == "00001") cout<<b<<" "<<f[Map[a]].grade[b-1]<<" "<<c<<endl;
            f[Map[a]].grade[b-1] = max(f[Map[a]].grade[b-1],c);
        }
    }

    for(student &a:f){
        a.sum = 0;
        a.sumsolve = 0;
        for(auto tem:a.score){
            a.sumsolve += tem;
        }
        for(auto tem:a.grade){
            if(tem>0) a.sum += tem;
        }

    }
    sort(f.begin(),f.end(),cmp);
    int rank = 0,lastall = -1,leijia = 1;
    for(student a:f){
        if(vis1[Map[a.id]] == vis2[Map[a.id]]) continue;
        if(a.sum == lastall) {
            ++leijia;
            cout<<rank<<" "<<a.id<<" "<<a.sum;
            for(int i = 0;i<m;++i){
                if(a.grade[i] !=-1){
                    printf(" %d",a.grade[i]);
                }else{
                    printf(" -");
                }
            }
            printf("\n");
        }else{

            rank += leijia; leijia = 1;
            cout<<rank<<" "<<a.id<<" "<<a.sum;
            for(int i = 0;i<m;++i){
                if(a.grade[i] != -1){
                    printf(" %d",a.grade[i]);
                }else{
                    printf(" -");
                }
            }
            printf("\n");
            lastall = a.sum;
        }
    }
    return 0;
}

