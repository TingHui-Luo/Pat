//
// Created by Dell on 2022-03-28.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
int n,k;
struct people{
    char name[10];
    int age;
    int value;
};
inline  int read(){
    int x = 0,y=1;char c= getchar();
    while(c<'0'||c>'9') {
        if(c == '-') y =-1;
        c= getchar();
    }
    while (c>='0'&&c<='9'){
        x = x*10+c-'0';
        c = getchar();
    }
    return x*y;
}
vector<people>f;
bool cmp(const people&a,const people&b){
    if(a.value == b.value) {
        if(a.age == b.age){
            return strcmp(a.name, b.name) < 0;
        }
        return a.age<b.age;
    }
    return  a.value> b.value;
}
int main(){
    cin>>n>>k;
    for(int i = 0;i<n;++i){

        people tem;
        scanf("%s",tem.name);
        tem.age = read();tem.value= read();

        f.push_back(tem);
    }
    sort(f.begin(),f.end(),cmp);
    for(int i = 0;i<k;++i){
        vector<people>ans;
        int num,age1,age2;
        num = read();
        age1 = read();
        age2 = read();

        for(auto c:f){
            if(c.age>=age1&&c.age<=age2){
                ans.push_back(c);
                if(ans.size()==num) break;
            }
        }
        printf("Case #%d:\n",i+1);
        if(ans.size() == 0) printf("None\n");
        else{
            for(auto c:ans){

                printf("%s %d %d\n",c.name,c.age ,c.value);

            }
        }
    }
    return 0;
}
