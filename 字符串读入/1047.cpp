#include<bits/stdc++.h>
using namespace std;
map<int,vector<string>> m;
int main() {
    int n,k;cin>>n>>k;
    while(n--){
        string t_name;
        t_name.resize(4);
        scanf("%s",t_name.c_str());
        int c;scanf("%d",&c);
        while(c--){

            int t_id;scanf("%d",&t_id);
            m[t_id].push_back(t_name);
        }
    }
    for(int i=1;i<=k;i++){
        printf("%d %d\n",i,m[i].size());
        sort(m[i].begin(),m[i].end());
        for(auto it:m[i]){
            printf("%s\n",it.c_str());
        }
    }
    return 0;
}
