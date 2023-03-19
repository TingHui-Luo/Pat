#include <iostream>
#include <vector>
using namespace std;

inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}
int n ;
vector<double>f;
int main()
{
    n = read();
    double  ans = 0.0;
    for(int i = 0;i<n;++i){
        double tem;
        scanf("%lf",&tem);
        ans += float ((n-i)*(i+1)) * tem;
    }
    printf("%.2lf",ans);
    return 0;
}