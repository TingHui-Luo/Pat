//
// Created by Dell on 2022-03-20.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n,k;
typedef long long  ll;
vector<ll>sum;
int upper_find(int left,int right,int x){
    while(left<= right){
        ll mid = left + (right- left)/2;
        if(sum[mid] >= x){
            right = mid-1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}
//
//int bound_find(int left,int right,int x){
//    while(left<=right){
//        ll mid = left + (right - left) /2;
//        if(sum[mid] < x){
//            left = mid + 1;
//        }else if(sum[mid] > x){
//            right = mid -1;
//        }else if(sum[mid] == x){
//            return mid;
//        }
//    }
//    return -1;
//}
//
//int bound_find(int left,int right,int x){
//    while(left<=right){
//        ll mid = left + (right - left) /2;
//        if(sum[mid] < x){
//            left = mid + 1;
//        }else if(sum[mid] > x){
//            right = mid -1;
//        }else if(sum[mid] == x){
//            right = mid -1;
//        }
//    }
//    return left;
//}
//
//
//int bound_find(int left,int right,int x){
//    while(left<=right){
//        ll mid = left + (right - left) /2;
//        if(sum[mid] < x){
//            left = mid + 1;
//        }else if(sum[mid] > x){
//            right = mid -1;
//        }else if(sum[mid] == x){
//            left = mid + 1;
//        }
//    }
//    if(right < 0 || num[right] != x) return -1;
//    return right;
//}
//
//
//int bound_find(int left,int right,int x){
//    while(left <= right) {
//        //只修改了判断的条件，相当于将小于等于归为一类。
//        if(array[mid] <= target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return left
//}
//
//
//int bound_find(int left,int right,int x){
//    while(left <= right) {
//        //只修改了判断的条件，相当于将小于等于归为一类。
//        if(array[mid] < target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return left
//}
//
//int bound_find(int left,int right,int x){
//    while(left <= right) {
//        //只修改了判断的条件，相当于将小于等于归为一类。
//        if(array[mid] <= target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return left
//}
//
//
//int bound_find(int left,int right,int x){
//    while(left <= right) {
//        //只修改了判断的条件，相当于将大于等于归为一类。
//        if(array[mid] >=  target)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return right;
//}
//
//int bound_find(int left,int right,int x){
//    while(left <= right) {
//        //只修改了判断的条件，相当于将大于等于归为一类。
//        if(array[mid] >  target)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return right;
//}


int main(){
    cin>>n>>k;
    for(int i = 0;i<n;++i){
        ll tem;cin>>tem;
        if(i == 0){
            sum.push_back(tem);
        }else{
            sum.push_back(sum[i-1]+tem);
        }
    }
    int neark = 1e8;
    for(int i = 0;i<n;++i){
        int j = upper_find(i,n-1,(i == 0?0+k:sum[i-1]+k));
        if(sum[j] - (i==0?0:sum[i-1] ) == k){
            neark = k;
            break;
        }else if(j <= n-1 && sum[j] - (i==0?0:sum[i-1] ) < neark){
            neark = sum[j] - (i==0?0:sum[i-1] );
        }
    }

    for(int i = 0;i<n;++i){
        int j = upper_find(i,n,i == 0?0+neark:sum[i-1]+neark);

        if((sum[j] - (i==0?0:sum[i-1] ))== neark){
            cout<<i+1<<"-"<<j+1<<endl;
        }
    }

    return 0;
}