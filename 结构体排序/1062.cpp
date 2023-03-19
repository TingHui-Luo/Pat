//
// Created by Dell on 2022-03-29.
//
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
struct lth{
    int name;
    int Virtue_Grade;
    int Talent_Grade;
};
vector<lth>f[4];

bool cmp(const lth&a,const lth&b){
    if(a.Talent_Grade+ a.Virtue_Grade == b.Talent_Grade + b.Virtue_Grade){
        if(a.Virtue_Grade == b.Virtue_Grade){
            return a.name<b.name;
        }else{
            return  a.Virtue_Grade>b.Virtue_Grade;
        }
    }
    return a.Talent_Grade+ a.Virtue_Grade>b.Talent_Grade + b.Virtue_Grade;
}

int main(){
    cin>>n;
    int L,H;
    cin>>L>>H;
    for(int i = 0;i<n;++i){
        lth a;
        scanf("%d %d %d",&a.name,&a.Virtue_Grade,&a.Talent_Grade);
        if(a.Virtue_Grade<L||a.Talent_Grade<L) continue;
        else if(a.Virtue_Grade>=H&&a.Talent_Grade>=H){
            f[0].push_back(a);
        } else if(a.Talent_Grade<H&&a.Virtue_Grade>=H){
            f[1].push_back(a);
        } else if(a.Virtue_Grade<H&&a.Talent_Grade<H&&a.Virtue_Grade>=a.Talent_Grade){
            f[2].push_back(a);
        } else {
            f[3].push_back(a);
        }
    }

    cout<<f[0].size()+f[1].size()+f[2].size()+f[3].size()<<endl;
    for(int i = 0;i<=3;++i){
        sort(f[i].begin(),f[i].end(),cmp);
        for(lth j:f[i]){

            printf("%d %d %d\n",j.name,j.Virtue_Grade,j.Talent_Grade);
        }
    }
    return  0;
}
