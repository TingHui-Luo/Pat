//
// Created by Dell on 2022-03-07.
//

#include <iostream>
#include <vector>
using namespace std;

vector<char>T;
int main(){
    double ans = 1;

    for(int i = 0;i<3;++i){
        double a,b,c;
        cin>>a>>b>>c;
        a = max(a,b);
        a = max(a,c);
        if (a == b){
            T.push_back('T');
        }else if(a == c){
            T.push_back('L');
        }else{
            T.push_back('W');
        }
        ans *= a;
    }
    for(char c:T){
        cout<<c<<" ";
    }
    printf("%.2f",(ans*0.65 - 1)*2);






    return 0;
}