#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
long int number = 0, temp = 0;

struct node{
    string address;
    int val;
    string next;
};

string root;
vector<node>ff;
map<string ,string >f;
map<string,int>Map;
int main()
{
    cin>>root;
    int n;
    cin>>n;
    string ss;
    ss.resize(5);
    ss = "-1";
    for(int i = 0;i<n;++i){
        node a;
        a.address.resize(5);a.next.resize(5);
        scanf("%s %d %s",a.address.c_str(),&a.val,a.next.c_str());

        ff.emplace_back(a);
        f[a.address] = a.next;

        Map[a.address] = ff.size()-1;
    }
    vector<node>F,Lost;
    node a;

    F.emplace_back(a);  Lost.emplace_back(a);
    int lastNodeIndex = 0,lastLast =0;
    map<int,int>Incur;
    string temRoot = root;
    while(temRoot.c_str() != ss){
        if(Incur [abs(ff[Map[temRoot]].val)] == 0){
            F[lastNodeIndex].next = ff[Map[temRoot]].address;
            F.emplace_back(ff[Map[temRoot]]);
            lastNodeIndex = F.size()-1;
            Incur[abs(ff[Map[temRoot]].val)] = 1;
        }else{
            Lost[lastLast].next = ff[Map[temRoot]].address;
            Lost.emplace_back(ff[Map[temRoot]]);
            lastLast = Lost.size()-1;
        }
        temRoot = f[temRoot];
    }
    for(int i = 1;i<F.size();++i){
        printf("%s %d %s\n",F[i].address.c_str(),F[i].val,((i==(F.size()-1))?("-1"):(F[i].next)).c_str());

    }
    for(int i = 1;i<Lost.size();++i){
        printf("%s %d %s\n",Lost[i].address.c_str(),Lost[i].val,((i==(Lost.size()-1))?("-1"):(Lost[i].next)).c_str());

    }
    return 0;
}
