//
// Created by Dell on 2022-03-31.
//

#include<iostream>

using namespace std;

int main(){

    long long t;
    cin>>t;
    for(int i = 0;i<t;++i){
        long long a, b, c, sum;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: ", t);
        sum = a + b;
        if(a > 0 && b > 0 && sum < 0)
            printf("true\n");
        else if(a < 0 && b < 0 && sum >= 0)
            printf("false\n");
        else if (sum > c)
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}