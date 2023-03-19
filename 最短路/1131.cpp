

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
struct edge{
    int v;
    int sym;
};
vector<edge>Edge[10010];
vector<edge>Pre[10010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> >q;
int st,ft,minn;
void djstla(int st){
    vector<int>dis(10010,1e8);
    vector<int>vis(10010,0);

    dis[st] = 0;
    q.push({0,st});
    while(!q.empty()){
        int u = q.top().second;q.pop();
        if(vis[u])  continue;
        vis[u] = 1;
        for(edge tem:Edge[u]){
            int v = tem.v;
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push({dis[v],v});
                Pre[v].clear();
                tem.v = u;
                Pre[v].emplace_back(tem);
            }else if(dis[v] == dis[u] + 1){
                tem.v = u;
                Pre[v].emplace_back(tem);
            }
        }
    }
    minn = dis[ft];
}
vector<string>ans;
void dfs(int x,int lastSym,vector<string>temAns){
    if(x == st){
        string s2 = to_string(x);
        while(s2.size()!=4) s2 = "0" + s2;
        temAns[temAns.size()-1] = temAns[temAns.size()-1]+ s2;
        if(ans.empty()){
            ans = temAns;
        }else if(temAns.size() < ans.size()){
            ans = temAns;
        }
        return;
    }
    for(edge u:Pre[x]){
//        string s1 = to_string(u.v);
//        while(s1.size()!=4) s1 = "0" + s1;
        string s2 = to_string(x);
        while(s2.size()!=4) s2 = "0" + s2;
        vector<string> temS = temAns;
        if(u.sym != lastSym) {
            temAns[temAns.size()-1] = temAns[temAns.size()-1]+ s2;
            temAns.emplace_back("Take Line#"+ to_string(u.sym)+" from "+s2+" ");
            dfs(u.v,u.sym,temAns);
            temAns = temS;
        }else{
            dfs(u.v,lastSym,temAns);
        }
    }
}
int main(){
    n = read();
    for(int i = 0;i<n;++i){
        int num = read();
        int u = read();
        for(int j = 1;j<num;++j){
            int v = read();
            edge tem;
            tem.v = v;
            tem.sym = i+1;
            Edge[u].emplace_back(tem);
            tem.v = u;
            Edge[v].emplace_back(tem);
            u = v;
        }
    }
    m = read();
    for(int i = 0;i<m;++i){
        for(int j = 0;j<10010;++j) Pre[j].clear();
        ans.clear();
        st = read(),ft = read();
        djstla(st);
        vector<string>tem;
        tem.push_back("");
        dfs(ft,-1,tem);
        cout<<minn<<endl;
        ans.erase(ans.begin());
        for(string &s:ans){
            s = s + " ";
            vector<string> temList;
            int last = 0;
            for(int j = 0;j<s.size();++j){
                if(s[j] == ' '){
                    temList.emplace_back(s.substr(last,j-last));
                    last = j + 1;
                }
            }
            s = temList[0] + " " + temList[1] + " " + temList[2] + " " + temList[4] + " to " + temList[3]+".";
        }
        cout<<ans[ans.size()-1]<<endl;
        for(int j = ans.size()-2;j>=0;--j){
            cout<<ans[j]<<endl;
        }
    }
    return 0;
}