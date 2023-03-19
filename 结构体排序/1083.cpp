

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
typedef long long ll;
int n;
struct student{
    string name;
    string id;
    int grade;
};
vector<student>f;
vector<student>f1;
bool cmp(const student&a,const student& b){
    return a.grade>b.grade;
}
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        student a;
        cin>>a.name>>a.id>>a.grade;
        f1.emplace_back(a);
    }
    int low,high;
    cin>>low>>high;
    for(student a:f1){
        if(a.grade>=low&&a.grade<=high){
            f.emplace_back(a);
        }
    }
    sort(f.begin(),f.end(),cmp);
    if(f.size() == 0) {
        cout<<"NONE";
        return 0;
    }
    for(auto a:f){
        cout<<a.name<<" "<<a.id<<endl;
    }
    return 0;
}