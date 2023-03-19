//
// Created by Dell on 2022-03-28.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;
const int N = 1e5+4;

int c[N];
stack<int>sta;


void add(int x,int val){
    for(int i = x;i<N;i+=(i&(-i))){
        c[i] += val;
    }
}

int sum(int x){
    int sum = 0;
    for(int i =x;i>0;i-=(i&(-i))){
        sum += c[i];
    }
    return sum;
}

int binary_find(int x){
    int left = 0,right = N;
    while (left<=right){
        int mid = left + (right - left)/2;
        if(sum(mid)> x){
            right = mid -1;
        }else if(sum(mid) <=x){
            left = mid+1;
        }
    }
    return left;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        if(s == "Pop"){
            if(sta.empty()) {cout<<"Invalid"<<endl;continue;}
            cout<<sta.top()<<endl;
            add(sta.top(),-1);
            sta.pop();
        }else if(s == "PeekMedian"){
            if(sta.empty()) {cout<<"Invalid"<<endl;continue;}
            cout<<binary_find((sta.size()+1)/2-1)<< endl;
        }else {
            int k;cin>>k;
            sta.push(k);
            add(k,1);
        }
    }
    return 0;
}
