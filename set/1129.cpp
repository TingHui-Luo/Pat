
#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
struct node{
public:
    int id, count;
    bool operator<(const node&nod) const {
        return count != nod.count ? count > nod.count:id < nod.id;
    }
};

vector<int> lib(50010);
int main() {
    int n, k,id;
    scanf("%d %d", &n, &k);
    set<node> se;
    vector<node> vec;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (i != 0) {
            printf("%d:", id);
            int count = 0;
            for (auto it = se.begin(); it != se.end() && count < k; it++) {
                printf(" %d", (*it).id);
                count++;
            }
            printf("\n");
        }
        auto it = se.find(node{ id,lib[id] });
        if (it != se.end()) {
            se.erase(it);
            lib[id]++;
        }
        lib[id]++;
        se.insert(node{ id,lib[id] });
    }
    return 0;
}


#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

int n,m;

struct ware{
    int times;
    int id;
};
bool cmp  (const ware &a,const ware &b){
    if(a.times!=b.times) return  a.times>b.times;
    return a.id <b.id;
}

int main(){
    n = read();m = read();
    vector<ware>f(n+1);
    vector<string>ans;
    vector<ware>ff;
    ff.clear();
    ans.clear();
    f.clear();
    for(int i = 0;i<n;++i){
        string s;
        int tem = read();
        if(ans.size()) ans[ans.size()-1] = to_string(tem)+": "+ans[ans.size()-1];
        f[tem].times += 1;
        f[tem].id = tem;
        int sym = 0;
            for(ware &a:ff){
                if(a.id == tem) {
                    sym = 1;
                    a.times += 1;
                    break;
                }
            }

        if(!sym){
            ff.emplace_back(f[tem]);
            sort(ff.begin(),ff.end(),cmp);
            if(ff.size()>m){
                ff.erase(ff.begin()+m);
            }
        }
        else{
            sort(ff.begin(),ff.end(),cmp);
        }

        s = to_string(ff[0].id);
        for(int j = 1;j<min(m,int(ff.size()));++j){
            if(ff[j].times == 0) continue;
            s = s + " "+ to_string(ff[j].id);
        }
        ans.emplace_back(s);
    }
    for(int i = 0;i<n-1;++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}