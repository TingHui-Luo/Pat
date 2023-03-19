//
// Created by Dell on 2022-04-02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
double maxn;
struct lth{
    double demand;
    double profit;
    double price;
};

vector<lth>f;

bool cmp(const lth&a,const lth&b){
    return a.price>b.price;
}
int main(){
    cin>>n>>maxn;
    for(int i = 0;i<n;++i){
        lth a;
        cin>>a.demand;
        f.push_back(a);
    }

    for(int i = 0;i<n;++i){
        cin>>f[i].profit;
        f[i].price = f[i].profit/f[i].demand;
    }
    sort(f.begin(),f.end(),cmp);
    int index = 0;
    double ans = 0;
    while(maxn&&index<n){
        if(maxn >= f[index].demand){
            maxn -= f[index].demand;
            ans += f[index].profit;
        }else{
            ans += (maxn/f[index].demand)*f[index].profit;
            maxn = 0;
        }
        ++index;
    }
    printf("%.2f",ans);
    return 0;
}