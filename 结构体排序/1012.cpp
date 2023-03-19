//
// Created by Dell on 2022-03-08.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct student{
    string id;
    int C=0,M=0,E=0;
    double A=0.0;
};

bool operator < (student &a,student &b){
    if(a.A == b.A){
        if(a.C == b.C){
            if(a.M == b.M){
                if(a.E == b.E){
                    return a.id<b.id;
                }else{
                    return a.E>b.E;
                }
            }else{
                return a.M>b.M;
            }
        }else{
            return a.C>b.C;
        }
    }else{
        return a.A>b.A;
    }
}
int n,m;
vector<student>M;
vector<student>C;
vector<student>E;
vector<student>A;

map<string,int>Grade;
map<string,string>sym;

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        string s;
        int a,b,c;
        cin>>s>>a>>b>>c;
        student tems;
        tems.id = s;
        tems.A = float(a+b+c)/3;
        A.push_back(tems);
        tems.A = 0;tems.C = a;
        C.push_back(tems);
        tems.C = 0;tems.M = b;
        M.push_back(tems);
        tems.M = 0;tems.E = c;
        E.push_back(tems);
        Grade[s] = 5e8;

    }
    sort(A.begin(),A.end());
    sort(C.begin(),C.end());
    sort(M.begin(),M.end());
    sort(E.begin(),E.end());
    int last = -1,lastid = 0;
    for(int i =0 ;i<A.size();++i){
        student c = A[i];
        if(last!=-1&&last==c.A){
            if(Grade[c.id]>lastid){
                Grade[c.id] = lastid;
                sym[c.id] = "A";
            }
        }else{
        if(Grade[c.id]>i){
            Grade[c.id] = i;
            sym[c.id] = "A";
        }}
        if(last != c.A){
            last = c.A;
            lastid = i;
        }
    }
    last = -1,lastid = 0;
    for(int i =0 ;i<C.size();++i){
        student c = C[i];
        if(last!=-1&&last==c.C){
            if(Grade[c.id]>lastid){
                Grade[c.id] = lastid;
                sym[c.id] = "C";
            }
        }else{
        if(Grade[c.id]>i){
            Grade[c.id] = i;
            sym[c.id] = "C";
        }}
        if(last != c.C){
            last = c.C;
            lastid = i;
        }
    }
    last = -1,lastid = 0;
    for(int i =0 ;i<M.size();++i){
        student c = M[i];
        if(last!=-1&&last==c.M){
            if(Grade[c.id]>lastid){
                Grade[c.id] = lastid;
                sym[c.id] = "M";
            }
        }else{
        if(Grade[c.id]>i){
            Grade[c.id] = i;
            sym[c.id] = "M";
        }}
        if(last != c.M){
            last = c.M;
            lastid = i;
        }
    }
    last = -1,lastid = 0;
    for(int i =0 ;i<E.size();++i){
        student c = E[i];
        if(last!=-1&&last==c.E){
            if(Grade[c.id]>lastid){
                Grade[c.id] = lastid;
                sym[c.id] = "E";
            }
        }else{
        if(Grade[c.id]>i){
            Grade[c.id] = i;
            sym[c.id] = "E";
        }}
        if(last != c.E){
            last = c.E;
            lastid = i;
        }
    }

    for(int i = 0;i<m;++i){
        string s;
        cin>>s;
        if(Grade.find(s) == Grade.end()){
            cout<<"N/A"<<endl;
        }else{
            cout<<Grade[s]+1<<" "<<sym[s]<<endl;
        }
    }
    return 0;
}
