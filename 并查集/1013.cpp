//
// Created by Dell on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m,k,ans;
vector<vector<int>>f(1010);

vector<int>father(1010);
void init(){
    for(int i = 1;i<=n;++i){
        father[i] = i;
    }
    ans = 0;
}


int find(int x){
    int a = x;
    while(x!=father[x]){
        x = father[x];
    }
    while(a!=father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void add(int x,int y){
    x = find(x),y = find(y);
    if(x != y){
        father[x] = y;
    }
}

void work(int vis){
    for(int i = 1;i<=n;++i){
        if(i == vis) continue;
        for(int b:f[i]){
            if(b == vis) continue;
            add(i,b);
        }
    }
    map<int,int>Map;
    Map.clear();


    for(int i = 1;i<=n;++i){
        if(father[i] == i)
            ++ans;
    }
    cout<<ans-2<<endl;
}

int main(){
    cin>>n>>m>>k;

    for(int i = 0;i<m;++i){
        int a,b;
        cin>>a>>b;
        f[a].push_back(b);
    }

    for(int i = 0;i<k;++i) {
        init();
        int tem;
        cin>>tem;

        work(tem);

    }

    return 0;
}