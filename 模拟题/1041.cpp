//
// Created by Dell on 2022-03-20.
//

#include <map>
#include <iostream>
#include <vector>
using namespace std;
map<int,int>Map;
int main(){
    int n;
    cin>>n;
    vector<int>f;
    for(int i = 0;i<n;++i){
        int tem;
        cin>>tem;
        f.push_back(tem);
        Map[tem] +=1;
    }

    int sym = 0;
    for(int a:f) {
        if (Map[a]== 1) {
            cout << a;
            sym = 1;
            break;
        }
    }
    if(!sym){
        cout<<"None";
    }
    return 0;
}