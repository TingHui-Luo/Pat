//
// Created by Dell on 2022-03-13.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
struct Play{
    int arriveTime;
    int playTime;
    int serveTime;
    int vip;
};

int zhuan(string x){
    return ((x[0]-'0')*10+(x[1]-'0'))*60*60 +  ((x[3]-'0')*10+(x[4]-'0'))*60 + ((x[6]-'0')*10+(x[7]-'0'));
}

string zhuan(int x){
    string ans = "";
    ans += x/(60*60*10) + '0';
    x %=10*60*60;
    ans += x/(60*60) + '0';
    x %=60*60;
    ans += ":";
    ans += x/(10*60) + '0';
    x %=10*60;
    ans += x/(60) + '0';
    x %=60;
    ans += ":";
    ans += x/(10) + '0';
    x %=10;
    ans += x + '0';
    return ans;
}

bool cmp(const Play&a,const Play&b){
    return a.arriveTime<b.arriveTime;
}
bool cmp1(const Play&a,const Play&b){
    return a.serveTime<b.serveTime;
}
queue<Play>ordinaryQueue;
queue<Play>vipQueue;
int n,m,m1;
vector<int>Tables;
vector<Play>Players;
map<int,int>VipMap;
map<int,int>vis;
vector<int>TableServe;
vector<Play>PlayerServe;
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        Play play;
        string s;cin>>s;
        play.arriveTime = zhuan(s);
//        cout<<zhuan(play.arriveTime )<<endl;
        cin>>play.playTime>>play.vip;
        Players.push_back(play);
    }
    cin>>m>>m1;
    Tables.assign(m+1,0);
    TableServe.assign(m+1,0);

    for(int i = 0;i<m1;++i){
        int tem;cin>>tem;
        VipMap[tem] = 1;
    }

    sort(Players.begin(),Players.end(),cmp);
    for(int i = 0;i<Players.size();++i){
        ordinaryQueue.push(Players[i]);
        if(Players[i].vip == 1){
            vipQueue.push(Players[i]);
        }
    }
    for(int i = 8*60*60;i<21*60*60;++i){
        for(int j = 1;j<=m;++j){
            if(Tables[j] == 0){
                if(VipMap.find(j) == VipMap.end()){
                    while(!ordinaryQueue.empty()&&vis[ordinaryQueue.front().arriveTime] == 1) ordinaryQueue.pop();
                    if(!ordinaryQueue.empty()){
                        Play play = ordinaryQueue.front();
                        if(play.arriveTime>i) continue;
                        ordinaryQueue.pop();
                        if(play.playTime > 2*60)  play.playTime = 2*60;
                        Tables[j] = play.playTime*60;
                        TableServe[j] +=1;
                        play.serveTime = i;
                        PlayerServe.push_back(play);

                        vis[play.arriveTime] = 1;
                    }
                }else{
                    while(!vipQueue.empty()&&vis[vipQueue.front().arriveTime] == 1) vipQueue.pop();
                    while(!ordinaryQueue.empty()&&vis[ordinaryQueue.front().arriveTime] == 1) ordinaryQueue.pop();
                    int sym = 0;
                    if(!vipQueue.empty()){
                        Play play = vipQueue.front();
                        if(play.arriveTime<=i) {
                            if(play.playTime > 2*60)  play.playTime = 2*60;
                            vipQueue.pop();
                            Tables[j] = play.playTime * 60;

                            TableServe[j] += 1;
                            play.serveTime = i;
                            PlayerServe.push_back(play);
                            vis[play.arriveTime] = 1;

                            sym = 1;
                        }
                    }
                    if(!ordinaryQueue.empty()&&!sym){
                        Play play = ordinaryQueue.front();
                        if(play.arriveTime>i) continue;

                        ordinaryQueue.pop();
                        if(play.playTime > 2*60)  play.playTime = 2*60;
                        Tables[j] = play.playTime*60;
                        TableServe[j] +=1;
                        play.serveTime = i;
                        PlayerServe.push_back(play);
//                        cout<<zhuan(play.arriveTime)<<" "<<zhuan(i)<<" "<<j<<"12e"  <<endl;
                        vis[play.arriveTime] = 1;
                    }
                }
            }else{
                Tables[j] -= 1;

                if(Tables[j] == 0){
                    if(VipMap.find(j) == VipMap.end()){
                        while(!ordinaryQueue.empty()&&vis[ordinaryQueue.front().arriveTime]==1) ordinaryQueue.pop();
                        if(!ordinaryQueue.empty()){
                            Play play = ordinaryQueue.front();
                            if(play.arriveTime>i) continue;
                            ordinaryQueue.pop();
                            if(play.playTime > 2*60)  play.playTime = 2*60;
                            Tables[j] = play.playTime*60;
                            TableServe[j] +=1;
                            play.serveTime = i;
                            PlayerServe.push_back(play);
//                            cout<<zhuan(play.arriveTime)<<" "<<zhuan(i)<<" "<<j  <<endl;
                            vis[play.arriveTime] = 1;
                        }
                    }else{
                        while(!vipQueue.empty()&&vis[vipQueue.front().arriveTime] == 1) vipQueue.pop();
                        while(!ordinaryQueue.empty()&&vis[ordinaryQueue.front().arriveTime] == 1) ordinaryQueue.pop();
                        int sym = 0;
                        if(!vipQueue.empty()){
                            Play play = vipQueue.front();
                            if(play.arriveTime<=i) {
                            vipQueue.pop();
                                if(play.playTime > 2*60)  play.playTime = 2*60;
                            Tables[j] = play.playTime*60;
                            TableServe[j] +=1;
                            play.serveTime = i;
                            PlayerServe.push_back(play);
                            vis[play.arriveTime] = 1;
//                            cout<<zhuan(play.arriveTime)<<" "<<zhuan(i)<<" "<<j  <<endl;
                            sym = 1;
                            }
                        }
                        if(!ordinaryQueue.empty()&&!sym){
                            Play play = ordinaryQueue.front();
                            if(play.arriveTime>i) continue;
                            ordinaryQueue.pop();
                            if(play.playTime > 2*60)  play.playTime = 2*60;
                            Tables[j] = play.playTime*60;
                            TableServe[j] +=1;
                            play.serveTime = i;
                            PlayerServe.push_back(play);
//                            cout<<zhuan(play.arriveTime)<<" "<<zhuan(i)<<" "<<j <<endl;
                            vis[play.arriveTime] = 1;
                        }
                    }
                }
            }

        }
    }
    sort(PlayerServe.begin(),PlayerServe.end(),cmp1);
   for(Play c:PlayerServe){
       cout<<zhuan(c.arriveTime)<<" "<<zhuan(c.serveTime)<<" "<<int(float (c.serveTime-c.arriveTime)/float (60) + 0.5)<<endl;
   }
   for(int i = 1;i<TableServe.size();++i){
       if(i!=TableServe.size()-1) cout<<TableServe[i]<<" ";
       else cout<<TableServe[i];
   }
    return 0;
}

//7
//20:40:00 10 0
//20:41:00 10 0
//20:42:00 10 0
//20:42:01 10 0
//20:42:02 10 0
//20:43:00 10 1
//20:44:00 10 1
//3 1
//2
