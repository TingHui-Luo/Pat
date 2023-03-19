#include<vector>
#include<iostream>
using namespace std;
int k, n;
vector<int> list;
void post(int v){
    if(v >= n) return;
    post(2 * v + 1);
    post(2 * v + 2);
    printf("%d%c", list[v], v != 0? ' ': '\n');
}
int main(){
    scanf("%d%d", &k, &n);
    list.resize(n);
    for(int i = 0; i < k; ++i){
        list.clear();
        for(int j = 0; j < n; ++j)	scanf("%d", &list[j]);
        int flag = list[0] >= list[1]? 1 : -1;
        for(int j = 0; j <= (n - 1) / 2; ++j){
            int l = 2 * j + 1, r = 2 * j + 2;
            if(flag == 1){
                if(list[l] > list[j] ||(r < n && list[r] > list[j])) flag = 0;
            }
            else if(list[l] < list[j] || (r < n && list[r] < list[j])) flag = 0;
        }
        if(!flag)	printf("Not Heap\n");
        else if(flag == -1)	printf("Min Heap\n");
        else  printf("Max Heap\n");
        post(0);
    }
    return 0;
}