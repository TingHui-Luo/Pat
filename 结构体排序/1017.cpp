//
// Created by Dell on 2022-03-10.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int zhuan(string s){
    return ((s[0]-'0')*10 + s[1]-'0')*60*60 + ((s[3]-'0')*10 + s[4]-'0')*60 + ((s[6]-'0')*10 + s[7]-'0');
}

struct lth{
    int startT;
    int sum;
};

vector<queue<int>>wait(11000);

int n,m;
vector<lth>q;
bool cmp (const lth&a,const lth&b){
    return a.startT<b.startT;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        string s;int t;
        cin>>s>>t;
        int temT = zhuan(s);
        lth a;
        a.startT = temT;
        a.sum = t*60;
        q.push_back(a);
    }
    sort(q.begin(),q.end(),cmp);
    int index = 0;
    long long ans  = 0;
    int cnt = 0;
    while(index<n&& index<m&& q[index].startT<=(8*60*60)){
        wait[index].push(q[index].sum);
        ans +=  (8*60*60)-q[index].startT;
        ++index;
        ++cnt;
    }
//    cout<<ans;
//    cout<<q[0].startT;


    for(int i = 8*60*60;i;++i){
        if(index >= n||q[index].startT > 17*60*60 ) break;
        for(int j = 0;j<m;++j){
            if(!wait[j].empty()) {
                int num = wait[j].front();

                wait[j].pop();
                num -= 1;
                if (num == 0) {

                    if(index < n && q[index].startT<=i &&q[index].startT <=17*60*60){

                        wait[j].push(q[index].sum);
                        ans += i-q[index].startT;
                        ++index;
                        ++cnt;
                    }

                } else {
                    wait[j].push(num);
                }
            }else{

                if(index < n && q[index].startT<=i &&q[index].startT <=17*60*60){

                    wait[j].push(q[index].sum);
                    ans += i-q[index].startT;
                    ++index;
                    ++cnt;
                }
            }


        }

    }

    if(cnt < 0){
        printf("%.1f",0);
    }
    else {
        printf("%.1f", (float(ans) / float(cnt) /(60.0)));
    }
        return 0;
}

