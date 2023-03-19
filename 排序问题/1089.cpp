

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
#include <stack>
using namespace std;
typedef long long ll;

inline ll read(){
    ll x = 0,y = 1;char c= getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1;c = getchar();}
    while(c>='0'&&c<='9') { x = x*10+c - '0';c=getchar();}
    return x*y;
}
ll n;
vector<int>f;
vector<int>ans;
bool check(vector<int> temf){
    for(int i = 0;i<n;++i){
        if(temf[i] != ans[i]) return false;
    }
    return true;
}

void insertSort(){
    vector<int>insert = f;
    int flag = 0;
    for(int i = 1;i<n;++i){
        for(int j = 0;j<i;++j){
            if(insert[j]>insert[i]){
                int tem = insert[i];
                insert.erase(insert.begin()+i);
                insert.insert(insert.begin()+j,1,tem);
                break;
            }
        }

        if(check(insert)){
            flag = 1;
            continue;
        }
        if(flag == 1){
            cout<<"Insertion Sort"<<endl;
            cout<<insert[0];
            for(int j = 1;j<n;++j){
                cout<<" "<<insert[j];
            }
            break;
        }
    }
}

void mergeSort(){
    vector<int>insert = f;
    int flag = 0;
    int t = 1;
    while(t <= n){
        t *= 2;
        for(int i = 0;i<n;i+=t){
            for(int j = i+t/2;j<i+t&&j<n;++j){
                for(int k = i;k<j;++k) {
                    if (insert[k] > insert[j]) {
                        int tem = insert[j];
                        insert.erase(insert.begin() + j);
                        insert.insert(insert.begin() + k, 1, tem);
                        break;
                    }
                }
            }
        }
        if(check(insert)){
            flag = 1;
            continue;
        }
        if(flag == 1){
            cout<<"Merge Sort"<<endl;
            cout<<insert[0];
            for(int j = 1;j<n;++j){
                cout<<" "<<insert[j];
            }
            break;
        }
    }
}

int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }
    for(int i = 0;i<n;++i){
        int tem = read();
        ans.emplace_back(tem);
    }

    insertSort();
    mergeSort();

    return 0;
}
