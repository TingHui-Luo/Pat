//
// Created by Dell on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n,m,k,q;

vector<int>f;

vector<int>rf;
vector<vector<int>> wait(21);
map<int,int>Map;
int zhuan(string s){
    int ans1 = 0;
    ans1 += ((s[0]-'0')*10 + (s[1] - '0'))*60 + ((s[3]-'0')*10 + (s[4] - '0'));
    return ans1;
}


string zhuan(int ans){
    string s="";
    s += ans / (60*10) +'0';
    ans %= 60 * 10;
    s += ans/(60) + '0';
    ans %= 60;
    s += ":";
    s += ans/(10)+'0';
    ans %=10;
    s += ans +'0';
    return s;
}
int main(){


    cin>>n>>m>>k>>q;
    int index = 1;
    f.push_back(0);rf.push_back(0);
    for(int i = 1;i<=k;++i){
        int tem;
        cin>>tem;
        f.push_back(tem);
        rf.push_back(tem);
        if(index <= n * m&&index <=k)   {wait[(index-1)%n].push_back(i);++index;}
        Map[i] = -1;
    }
//    for(int i = 0;i<n;++i){
//        for(int tem:wait[i]){
//            cout<<tem<<" ";
//        }
//        cout<<endl;
//    }

    for(int i = 0;i<540;++i){
        set<int>bewait;
        bewait.clear();
        for(int j = 0;j<n;++j){
            if(wait[j].size()>0){
//                cout<<j<<" "<<wait[j][0]<<" ";
                f[wait[j][0]] -=1;
                if(f[wait[j][0]] == 0){
                    Map[wait[j][0]] = i;
                    wait[j].erase(wait[j].begin());
                    bewait.insert(j);
                }
            }
            while(!bewait.empty()&&index<=k){
                wait[*bewait.begin()].push_back(index);
                ++index;
                bewait.erase(bewait.begin());
            }
        }
//        cout<<endl;
    }
    for(int j = 0;j<n;++j){
        if(wait[j].size()>0&&rf[wait[j][0]]!=f[wait[j][0]]){
            Map[wait[j][0]] = 539 + f[wait[j][0]];
        }
    }
    for(int i = 0;i<q;++i){
        int tem;
        cin>>tem;
        if(Map[tem] == -1){
            cout<<"Sorry"<<endl;
        }else{
            cout<<zhuan(Map[tem]+1+480)<<endl;
        }
    }

    return 0;
}