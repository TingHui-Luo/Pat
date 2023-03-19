//
// Created by Dell on 2022-03-06.
//
#include <iostream>
#include <map>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;

long long int to10(string s, int radix) {
    long long int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i]))
            sum = sum*radix+s[i] - '0';
        else if (isalpha(s[i]))
            sum = sum*radix+s[i] - 'a'+10;
    }
    return sum;
}

long long int getRadix(long long int num1,string str,long long int left,long long int right){
//主要滴代码
    while(left<=right){
        long long  int mid = left + (right -left)/2;
        if(to10(str,mid) == num1){
            return mid;
        }else if(to10(str,mid) > num1||to10(str,mid)<0){
            right = mid - 1;
        }else if(to10(str,mid) < num1){
            left = mid + 1;
        }
    }
    return 0;
}
int getMinRadix(string num2){
//作用：找到num2的最小基数
//例如：num2中最大的权值为b时，最小基数就是b+1=12
    char max='0';
    for (int i = 0; i < num2.length(); ++i)
        if(num2[i]>max)max=num2[i];
    if (max <= '9')return max-'0'+1;
    else return max-'a'+11;
}
int main(){
    string s1,s2;
    ll trg,radis;
    cin>>s1>>s2>>trg>>radis;


    if(trg == 2){
        swap(s1,s2);
    }

    //寻找s2的最小进制
    long long int min_radix = 0;
    for (int i = 0; i < s2.length(); ++i) {
        if (isdigit(s2[i])) {
            if (s2[i] - '0' > min_radix)
                min_radix = s2[i] - '0'+1;
        }
        else if (isalpha(s2[i])) {
            if (s2[i] - 'a' + 10 > min_radix)
                min_radix = s2[i] - 'a' + 10+1;
        }
    }

    ll ans1 = to10(s1,radis);
    auto res=getRadix(ans1,s2,getMinRadix(s2),max(ans1,min_radix));
    if(res==0){
        cout<<"Impossible";return 0;
    }
    cout<<res;
    return 0;
}