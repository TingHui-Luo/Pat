//
// Created by Dell on 2022-03-13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    string id;
    int grade;
    int rank;
    int local_number;
    int local_rank;
};
vector<student>q1;
vector<student>q;
bool cmp(const student &a,const student &b){
    if(a.grade == b.grade){
        return a.id<b.id;
    }
    return a.grade>b.grade;
}
int n,m;
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>m;
        q1.clear();
        for(int j = 0;j<m;++j){
            student tem;
            cin>>tem.id>>tem.grade;
            tem.local_number = i+1;
            q1.push_back(tem);
        }
        sort(q1.begin(),q1.end(),cmp);
        int lastRank = 0,lastGrade=-1,gradenumber = 0;
        for(student &a:q1){
            if(a.grade == lastGrade){
                a.local_rank = lastRank;
                ++gradenumber;
            }else{

                lastGrade = a.grade;
                lastRank += gradenumber + 1;
                a.local_rank = lastRank;
                gradenumber = 0;
            }
        }
        for(student a:q1){
            q.push_back(a);
        }
    }
    sort(q.begin(),q.end(),cmp);
    int lastRank = 0,lastGrade=-1,gradenumber = 0;
    for(student &a:q){
        if(a.grade == lastGrade){
            a.rank = lastRank;
            ++gradenumber;
        }else{

            lastGrade = a.grade;
            lastRank += gradenumber + 1;
            a.rank = lastRank;
            gradenumber = 0;
        }
    }
    cout<<q.size()<<endl;
    for(student a:q){
        cout<<a.id<<" "<<a.rank<<" "<<a.local_number<<" "<<a.local_rank<<endl;
    }
    return 0;
}