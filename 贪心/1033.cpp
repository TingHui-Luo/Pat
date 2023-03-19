//
// Created by Dell on 2022-03-17.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
double c;
double dis;
double run;
int n;
struct lth{
    double price;
    double dis;

};
vector<lth>f;
bool cmp (const lth & a,const lth &b){
    return a.dis<b.dis;
}

int check(double gas,double nowdis,int index ){
    int minnid = index;double  minnp = f[index].price;
    for(int i = index+1;i<n;++i){

        if(f[i].dis > gas*run + nowdis) {
            break;
        }
        if(f[i].price<minnp){
            minnp = f[i].price;
            minnid = i;
            return minnid;
        }
    }
    return minnid;
}

int main(){
    cin>>c>>dis>>run>>n;
    for(int i = 0;i<n;++i){
        lth a;
        cin>>a.price>>a.dis;
        f.push_back(a);
    }

    sort(f.begin(),f.end(),cmp);
//    for(auto c:f){
//        cout<<c.dis<<" "<<c.price<<endl;
//    }
    double nowdis = 0;double gas = 0;
    int indexGas = 0;
    double money = 0.0;
    double lastbuy = f[0].price;
    while(nowdis < dis && indexGas < n){
        if(f[indexGas].dis> (gas * run + nowdis)){
            break;
        }else{

            gas = gas - (f[indexGas].dis-nowdis)/run;
            nowdis = f[indexGas].dis;
//            cout<<"login"<<nowdis<<" "<<gas<<endl;
            if(nowdis == dis) {
                break;
            }
            int temid = check(c,nowdis,indexGas);

            if( temid == indexGas){
                money += (c - gas)*f[indexGas].price;
                lastbuy = f[indexGas].price;
                gas = c;
            }else{
                double needgas = (f[temid].dis- nowdis)/run;
                if(needgas >gas){
                    money += (needgas - gas)*f[indexGas].price;
                    lastbuy = f[indexGas].price;
                    gas =  needgas;
                }
                indexGas = temid-1;
            }
        }
//        cout<<"leave"<<nowdis<<" "<<gas<<endl;
        ++indexGas;
    }

    if(nowdis + gas*run >= dis){
        printf("%.2f",money-(gas-(dis-nowdis)/run)*lastbuy);
    }else{
        cout<<"The maximum travel distance = ";
        printf("%.2f",nowdis+gas*run);
    }


    return 0;
}


