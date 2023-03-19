#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int n;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

vector<int>f;
vector<int>dpMin;
vector<int>dpMax;
vector<int>ans;

int main()
{
    n = read();
    dpMax.assign(n+1,0);
    dpMin.assign(n+1,1e8);
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }
    dpMax[0] = f[0];
    dpMin[n-1] = f[n-1];
    for(int i = 1;i<n;++i){
        dpMax[i] = max(dpMax[i-1],f[i]);
        dpMin[n-i-1] = min(dpMin[n-i],f[n-i-1]);

    }
    for(int i = 0;i<n;++i){
        if(i == 0){
            if(f[i]<dpMin[i+1]){
                ans.emplace_back(f[i]);
            }
        }
        else if(i == n-1){
            if(f[i]>dpMax[i-1]){
                ans.emplace_back(f[i]);
            }
        }else{
            if(f[i]>dpMax[i-1]&&f[i]<dpMin[i+1]){
                ans.emplace_back(f[i]);
            }
        }

    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    if(ans.size()){
        cout<<ans[0];
        for(int i = 1;i<ans.size();++i){
            cout<<" "<<ans[i];
        }
    }else{
       cout<<endl;
    }

    return 0;
}