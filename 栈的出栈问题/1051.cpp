//
// Created by Dell on 2022-03-24.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n,m,k;
int main(){
    cin>>m>>n>>k;
    for(int q = 0;q<k;++q){
        vector<int>f;
        f.clear();
        f.push_back(0);
        for(int j = 0;j<n;++j){
            int tem;cin>>tem;
            f.push_back(tem);
        }
        int i,j;
        i = 1;
        j = 0;
        stack<int>s;
        while (i<=n){
            if(!s.empty()&&s.top() == f[i]){
                ++i;
                s.pop();
            }else{
                if( j == n+1 )break;
                if(s.size() == m) {
                    j = n+1;
                    break;
                }
                s.push(++j);
            }

        }

        if(j == n+1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

// c (n,2*n)/ (n+1)
//按顺序入栈的序列，任意元素 e ，比 e 先入栈的元素，并且比 e 后出栈的元素，一定是降的。

//现在可以随意选一个序列来理解一下什么是 “ 后出先入逆序 ”
//比如序列：3 1 2 4
//
//选择任意元素 e ，这里选择 3
//比 3 后出栈的有三个元素 1 2 4
//其中比 3 先入栈的有两个元素 1 2
//但是 1 2 是正序的，而不是逆序的
//        所以这个序列不是合法出栈序列

//假设入栈的顺序是123456
//即元素i后比i小的都是降序排列（因为入栈的数字代表了进栈先后