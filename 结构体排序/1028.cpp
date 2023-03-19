//
// Created by Dell on 2022-03-13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct  student{
    string a,b;
    int c;
};
bool cmp1(const student&a,const student&b){

    return a.a<b.a;
}
bool cmp2(const student&a,const student&b){
    if(a.b==b.b) return a.a<b.a;
    return a.b<b.b;
}
bool cmp3(const student&a,const student&b){
    if(a.b==b.b) return a.a<b.a;
    return a.c<b.c;
}

vector<student>q;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;++i)
    {
        student s;
        cin>>s.a>>s.b>>s.c;
        q.push_back(s);
    }
    if(m == 1){
        sort(q.begin(),q.end(), cmp1);
    }else if(m==2){
        sort(q.begin(),q.end(), cmp2);
    }else {
        sort(q.begin(),q.end(), cmp3);
    }
    for(student tem:q){
        cout<<tem.a<<" "<<tem.b<<" "<<tem.c<<endl;
    }
    return 0;
}