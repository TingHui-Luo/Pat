//
// Created by Dell on 2022-03-16.
//

#include <iostream>
#include <vector>
char f[100][100];
using namespace std;
int main() {
    for(int i = 0;i<90;++i){
        for(int j = 0;j<90;++j){
            f[i][j] = ' ';
        }
    }
    string s;
    cin >> s;
    int n = s.size();
    int n1 = n / 3, n2 = n % 3;
    int bottom = n1;
    if (n2 == 0) {
        bottom += 2;
        n1 -= 1;
    } else {
    bottom += n2;
    }
    int index = 0;
    for(int i = 0;i<n1;++i){
        f[i][0] = s[index];
        ++index;
    }
    for(int i = 0;i<bottom;++i){
        f[n1][i] = s[index];
        ++index;
    }
    for(int i = n1-1;i>=0;--i){
        f[i][bottom-1] = s[index];
        ++index;
    }

    for(int i = 0;i<=n1;++i){
        for(int j = 0;j<bottom;++j){
            cout<<f[i][j];
        }
        cout<<endl;
    }
    return 0;
}