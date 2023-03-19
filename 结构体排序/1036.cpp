//
// Created by Dell on 2022-03-19.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct lth{
    string name;
    string id;
    int grade;
};
bool cmp(const lth&a,const lth&b){
    return a.grade>b.grade;
}
vector<lth>m;
vector<lth>f;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        string b;
        lth tem;
        cin>>tem.name>>b>>tem.id>>tem.grade;
        if(b == "F"){
            f.push_back(tem);
        }else{
            m.push_back(tem);
        }
    }
    sort(f.begin(),f.end(), cmp);
    sort(m.begin(),m.end(), cmp);
    if(f.size()){
        cout<<f.front().name<<" "<<f.front().id<<endl;
    }else{
        cout<<"Absent"<<endl;
    }

    if(m.size()){
        cout<<m[m.size()-1].name<<" "<<m[m.size()-1].id<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    if(!m.size()||!f.size()){
        cout<<"NA"<<endl;
    }else{
        cout<<f.front().grade-m[m.size()-1].grade<<endl;
    }
    return 0;
}