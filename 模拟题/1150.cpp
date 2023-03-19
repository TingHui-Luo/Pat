#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

inline int read(){
    int x = 0, y = 1; char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c=getchar();}
    return x*y;
}
int n,m;
int f[210][210];
int main(){
    n = read();m = read();
    for(int i = 0;i<m;++i){
        int u = read(),v = read(),w = read();
        f[u][v] = f[v][u] = w;
    }
    int k = read();
    int minid ,minans = 1e8;
    for(int i = 0;i<k;++i){
        int st,ft;
        int num = read();
        map<int,int>Map;
        int last = -1;
        int ans = 0;
        int sym = 1;
        for(int j = 0;j<num;++j){

            int tem = read();
            if(last!=-1){
                if(f[last][tem] == 0) {
                    sym = 0;
                }
                ans += f[last][tem];
            }
            Map[tem] = 1;
            if(j == 0) st = tem;
            if(j == num -1) ft = tem;
            last = tem;
        }

        if(sym){
            if(st != ft || Map.size()!=n) {
                printf("Path %d: %d (Not a TS cycle)\n", i + 1, ans);
            }
            else if(num!=n+1){
                printf("Path %d: %d (TS cycle)\n",i+1,ans);
                if(minans > ans){
                    minans = ans;
                    minid = i+1;
                }
            }else{
                printf("Path %d: %d (TS simple cycle)\n", i + 1, ans);
                if(minans > ans){
                    minans = ans;
                    minid = i+1;
                }
            }
        }else{
            printf("Path %d: NA (Not a TS cycle)\n",i+1);
        }
    }
    printf("Shortest Dist(%d) = %d\n",minid,minans);
    return 0;
}