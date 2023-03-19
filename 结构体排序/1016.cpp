//
// Created by Dell on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
vector<int>Time;
vector<string>names;
struct lth{
    string name;
    int startT;
    int sym ;

};

 bool operator < (const lth &a,const lth &b){
    return a.startT>b.startT;
}
unordered_map<string,priority_queue<lth,vector<lth>>>Map;
int zhuan(string s){
    return ((s[0]-'0')*10 + s[1]-'0')*24*60 + ((s[3]-'0')*10 + s[4]-'0')*60 + ((s[6]-'0')*10 + s[7]-'0');
}
#include <sstream>

string doubleToString(const double &val)
{
    char* chCode;
    chCode = new char[20];
    sprintf(chCode, "%.2lf", val);
    std::string str(chCode);
    delete[]chCode;
    return str;
}
string zhuan(int x){
    string ans = "";
    ans += x/(24*60*10) + '0';
    x = x % (24*60*10);
    ans += x/(24*60) + '0';
    x = x %(24*60);
    ans += ":";
    ans += x/(60*10) + '0';
    x = x %(60*10);
    ans += x/(60) + '0';
    x = x %(60);
    ans += ":";
    ans += x/(10) + '0';
    x = x %(10);
    ans += x + '0';
    return ans;
}


double count(int x,int y){
    double money = 0.0;
    for(int i = x;i<y;++i){
        money += float (Time[(i/60)%24])/(100.0);
    }
    return money;
}
int main(){
    for(int i = 0;i<24;++i){
        int tem;
        cin>>tem;
        Time.push_back(tem);
    }
    int n;
    cin>>n;
    string month = "";
    for(int i = 0;i<n;++i){
        string s,T,sy;
        cin>>s>>T>>sy;
        month = T.substr(0,2);
        lth teml;
        teml.startT = zhuan(T.substr(3));
        if(sy == "on-line") teml.sym = 1;
        else teml.sym = 0;
        if(Map.find(s) == Map.end())names.push_back(s);
        Map[s].push(teml);

    }


    sort(names.begin(),names.end());
    for(string c:names){

        int onsym = 0, onT=0 ;           double allMoney = 0.0;
        vector<string>TemAns;
        while(!Map[c].empty()){
            lth teml = Map[c].top();

            if(teml.sym == 1){
                onsym = 1;
                onT = teml.startT;
            }else{
                if(onsym== 1){
                    double money = count(onT,teml.startT);
                    allMoney += money;
                    TemAns.push_back(zhuan(onT)+" "+zhuan(teml.startT)+" "+to_string(teml.startT-onT)+" $"+doubleToString(money));
                    onsym =0;
                }
            }
            Map[c].pop();

        }
        if(allMoney == 0.0) continue;
        cout<<c<<" "<<month<<endl;
        for(string ss:TemAns){
            cout<<ss<<endl;
        }
        cout<<"Total amount: $"; printf("%.2f\n",allMoney);
    }
    return 0;

}