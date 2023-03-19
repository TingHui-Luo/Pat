//
// Created by Dell on 2022-03-25.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int>Map;
vector<int>f;

struct node{
    int val;
    int next;
}e[1000000];

int m1 = 1;
int main(){
    int n;
    cin>>n;
    int cc;
    cin>>cc;

    for(int i = 0;i<n;++i){
        int a,b,c;
        cin>>a>>c>>b;
        Map[c] = a;
        e[a].next = b;
        e[a].val = c;

    }

    while(cc != -1){

        f.push_back(e[cc].val);
        cc = e[cc].next;
    }

    sort(f.begin(),f.end());

    if(f.size() == 0) {
        cout << "0 -1";
        return 0;
    }


    printf("%d %05d\n",f.size(),Map[f[0]]);
    for(int i = 0;i<f.size()-1;++i){
        printf("%05d %d %05d\n",Map[f[i]],f[i],Map[f[i+1]]);

    }
    printf("%05d %d %d\n",Map[f[f.size()-1]],f[f.size()-1],-1);
}