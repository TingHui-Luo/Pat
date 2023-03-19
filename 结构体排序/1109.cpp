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
int n,m ;

struct lth{
    string name;
    int height;
};
vector<lth>f;

bool cmp(const lth &a,const lth &b){
    if(a.height!=b.height) return a.height>b.height;
    return a.name<b.name;
}
int main(){
    n = read();
    m = read();
    int rowNumber = n/m;
    for(int i = 0;i<n;++i){
        string s;cin>>s;
        int he = read();
        lth a;
        a.name = s;
        a.height = he;
        f.emplace_back(a);
    }
    sort(f.begin(),f.end(),cmp);
    int index = 0;
    vector<vector<string>>ans;
    for(int i = 0;i<m;++i){
        if(i == 0){
            rowNumber = n - (m-1)*rowNumber;
        }else{
            rowNumber = n/m;
        }
        vector<string>tem(rowNumber);
        int mid = rowNumber/2 ;
        tem[mid] = f[index++].name;

        int left = mid - 1,right  = mid + 1;
        int temNumber = 1;
        while(temNumber != rowNumber){
            if(left>=0){
                tem[left] = f[index++].name;
                --left;
                ++temNumber;
            }
            if(right<rowNumber){
                tem[right]= f[index++].name;
                ++right;
                ++temNumber;
            }
        }
        ans.push_back(tem);
    }
    for(auto c:ans){
        cout<<c[0];
        for(int i = 1;i<c.size();++i){
            cout<<" "<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
