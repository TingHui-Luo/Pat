#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
struct lth{
    string id;
    int score;
};
bool cmp(const lth &a,const lth &b){
    if(a.score!=b.score) return a.score>b.score;
    return a.id<b.id;
}

struct ans3{
    string id;
    int nt;
};
bool cmp1(const ans3 &a,const ans3 &b){
    if(a.nt!=b.nt) return a.nt>b.nt;
    return a.id<b.id;
}
unordered_map<string,vector<lth>>Map1;
unordered_map<string,vector<lth>>Map2;
unordered_map<string,vector<lth>>Map3;
int main(){
    n = read();m = read();
    for(int i = 0;i<n;++i){
        lth a;
        cin>>a.id>>a.score;
        string grade = a.id.substr(0,1),idd= a.id.substr(1,3),dates= a.id.substr(4,6);
        Map1[grade].emplace_back(a);
        Map2[idd].emplace_back(a);
        Map3[dates].emplace_back(a);
    }
    for(int i = 0;i<m;++i){
        int idd = read();
        string a;
        cin>>a;
        printf("Case %d: %d %s\n",i+1,idd,a.c_str());
        if(idd == 1){

            vector<lth>f = Map1[a];
            sort(f.begin(),f.end(),cmp);

            if(f.size()){

                for(int j = 0;j<f.size();++j){
                    printf("%s %d\n",f[j].id.c_str(),f[j].score);
                }
            }else{
                printf("NA\n");
            }
        }else if(idd == 2){
            vector<lth>f = Map2[a];
            int ans = 0;
            for(auto c:f){
                ans+=c.score;
            }
            if(f.size()){
                printf("%d %d\n",f.size(),ans);
            }else{
                printf("NA\n");
            }
        } else{
            vector<lth>f = Map3[a];
            unordered_map<string ,int>Map;
            vector<ans3>ff;
            for(auto c:f){
                c.id = c.id.substr(1,3);
                if(Map[c.id]){
                    ff[Map[c.id]-1].nt ++;
                }else{
                    ans3 anss;
                    anss.nt = 1;
                    anss.id = c.id;
                    ff.emplace_back(anss);
                    Map[c.id] = ff.size();
                }
            }
            sort(ff.begin(),ff.end(),cmp1);
            if(ff.size()){
                for(int j = 0;j<ff.size();++j){
                    printf("%s %d\n",ff[j].id.c_str(),ff[j].nt);
                }
            }else{
                printf("NA\n");
            }
        }
    }
    return 0;
}