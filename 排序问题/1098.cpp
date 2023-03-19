#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int n;
vector<int>f;
vector<int>ans;
vector<int>Map;
inline int read(){
    int x = 0,y = 1;char c = getchar();
    while(c>'9'||c<'0') {if(c == '-') y = -1; c= getchar();}
    while(c>='0'&&c<='9') {x = x*10 + c-'0'; c= getchar();}
    return x*y;
}

bool check(vector<int> tem){
    for(int i = 0;i<n;++i){

        if(tem[i] != Map[i]) return false;
    }
    return true;
}

void InsertSort(){
    vector<int>temf = f;
    int sym = 0;
    for(int i = 1;i<n;++i){
        for(int j = 0;j<i;++j){
            if(temf[i]<temf[j]){
                int tem = temf[i];
                temf.erase(temf.begin()+ i);
                temf.insert(temf.begin()+j,1,tem);
                break;
            }
        }

        if(check(temf)) {
            sym = 1;
            continue;
        }

        if(sym){
            cout<<"Insertion Sort"<<endl;
            cout<<temf[0];
            for(int j = 1;j<n;++j) cout<<" "<<temf[j];
            return;
        }
    }
}

void adjust_heap(vector<int>&temf,int root,int len){
    int left = root * 2 + 1,right = root * 2 + 2;
    int max = root;
    if(left<len && temf[left] > temf[max]){max = left;}
    if(right<len && temf[right] > temf[max]){max = right;}
    if(max != root){
        swap(temf[max],temf[root]);
        adjust_heap(temf,max,len);
    }
}

void HeapSort(){
    vector<int>temf =f ;
    int sym = 0;

    for(int i = n/2-1;i>=0;--i){adjust_heap(temf,i,n);}
    for(int i = n-1; i > 0; --i)//2. 堆排序, 此时 [1, len] 为一个堆
    {
        swap(temf[0], temf[i]);      //将　堆顶元素(数组首位)　与　堆末元素(数组末位) 互换.
        adjust_heap(temf, 0, i); // 此时堆末元素已经有序(存的是最大值),
        if(check(temf)) {
            sym = 1;
            continue;
        }
        if(sym){
            cout<<"Heap Sort"<<endl;
            cout<<temf[0];
            for(int j = 1;j<n;++j) cout<<" "<<temf[j];
            return;
        }
    }
}

int main()
{

    cin>>n;
    for(int i = 0;i<n;++i){
        int tem = read();
        f.emplace_back(tem);
    }
    for(int i = 0;i<n;++i){
        int tem = read();
        Map.emplace_back(tem);
    }
    InsertSort();
    HeapSort();
    return 0;
}
