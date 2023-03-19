#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int l[maxn];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&l[i]);
    }
    int min = 0x7FFFFFFF;
    int m,n;
    for(int i=1;i<=(int)sqrt(N);i++){
        if(N%i == 0){
            if(abs(N/i-i)<min){
                min = N/i-i;
                m = i>N/i?i:N/i;
                n = i>N/i?N/i:i;
            }
        }
    }
    int G[m][n];
    int i=0,cnt=0;
    sort(l,l+N,greater<int>());
    while(cnt<N){
        for(int j=i;j<n-i && cnt<N;j++){
            G[i][j] = l[cnt++];
        }
        for(int j=i+1;j<m-i && cnt<N;j++){
            G[j][n-1-i] = l[cnt++];
        }
        for(int j=n-i-2;j>=i && cnt<N;j--){
            G[m-1-i][j] = l[cnt++];
        }
        for(int j=m-2-i;j>=i+1 && cnt<N;j--){
            G[j][i] = l[cnt++];
        }
        i++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",G[i][j]);
            if(j<n-1)printf(" ");
        }
        printf("\n");
    }

    return 0;
}
