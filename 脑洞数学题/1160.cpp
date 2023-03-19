

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,maxK,maxM;
typedef long long ll;
struct number{
    int n;
    ll val;
};
vector<number>f;
unordered_map<int,ll>Map;


bool check(ll x){
    if(x<=2) return false;
    for(ll i = 2;i<= sqrt(x);++i){
        if(x%i == 0) return false;
    }
    return true;
}

ll getNum(ll num){
    ll ans = 0;
    ++num;
    while(num){
        ans += num%10;
        num/=10;
    }
    return ans;
}

ll gcd(ll a,ll b){
    return !b?a: gcd(b,a%b);
}

int ismin(int a,int b){ //找最小值
    int ans=0,cnt=0;
    while(b>9){
        ans=ans*10+9;
        cnt++;
        b-=9;
    }
    if(b>1) ans=(b-1)*pow(10,cnt)+ans;
    ans=pow(10,a-1)+ans;
    return ans;
}
int isbig(int a,int b){  //找最大值。
    int ans=0;
    while(b>9){
        ans=ans*10+9;
        b-=9;
        a--;
    }
    if(b) {
        a--;
        ans=ans*10+b;
    }
    while(a--){
        ans*=10;
    }
    return ans;
}

void dfs(int k,int m,ll num,ll sum){

    if(k == 0){
        if(m == 0){



        }
        return;
    }
    if(m<0) return;
    if(maxK == k){
        for(int i = 1;i<=(min(9,m));++i){
            dfs(k-1,m-i,num+Map[k-1]*i,sum+i);
        }
    }else{
        for(int i = 0;i<=(min(9,m));++i){
            dfs(k-1,m-i,num+Map[k-1]*i,sum+i);
        }
    }

}

bool  cmp(const number&a,const number&b){
    if(a.n!=b.n) return a.n<b.n;
    return a.val<b.val;
}
int main(){

    n = read();
    for(int i = 0;i<=9;++i){
        Map[i] = pow(10,i);
    }
    for(int i = 0;i<n;++i){
        int k = read(),m = read();
        maxM = m;
        maxK = k;
        printf("Case %d\n",i+1);
        if(9*k<m){
            printf("No Solution\n");
            continue;
        }
        int minN = ismin(k,m),MaxN = isbig(k,m);
        for(int j = minN;j <= MaxN;++j){
            if(getNum(j-1) == m){
                number a;
                a.val = j;
                a.n = getNum(j);
                if(check(gcd(a.n,maxM))){
                    f.emplace_back(a);
                }
            }
        }
//        dfs(k,m,0,0);
        sort(f.begin(),f.end(),cmp);

        if(f.size()){
            for(auto a:f){
                printf("%d %lld\n",a.n,a.val);
            }
        }else{
            printf("No Solution\n");
        }
        f.clear();

    }
    return 0;
}

