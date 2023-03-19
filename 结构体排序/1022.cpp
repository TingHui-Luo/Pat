// Created by Dell on 2022-03-13.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n;

struct book{
    string number;
    string title;
    string author;
    map<string,int>keywords;
    string publisher;
    string publish_year;
};

vector<book>f;
bool cmp(const book &a,const book &b){
    return a.number<b.number;
}
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        book tem;
        cin.get();
        getline(cin,tem.number,'\n');

        getline(cin,tem.title,'\n');
        getline(cin,tem.author,'\n');
        string key;
        getline(cin,key,'\n');
        int last = 0;
        for(int i = 0;i<key.size();++i){
            if(key[i] == ' '||i == key.size()-1){
                if(i == key.size()-1) ++i;
                tem.keywords[key.substr(last,i-last)] = 1;
//                cout<<key.substr(last,i-last);
                last = i+1;

            }
        }

        getline(cin,tem.publisher,'\n');
        cin>>tem.publish_year;
        f.push_back(tem);
    }
    sort(f.begin(),f.end(),cmp);
    int m ;
    cin>>m;cin.get();
    if(m==0) return 0;
    for(int i = 0;i<m;++i){
        string s;
        int cnt =0;
        getline(cin,s,'\n');
        string id = s.substr(0,1);string text = s.substr(3);
        cout<<s<<endl;
        if(id == "1"){
            for(book temb:f){
                if(temb.title == text){
                    ++cnt;

                    cout<<temb.number<<endl;
                }
            }
            if(cnt == 0){
                printf("Not Found\n");
            }
        }else if(id == "2"){
            for(book temb:f){
                if(temb.author == text){
                    ++cnt;
                    cout<<temb.number<<endl;
                }
            }
            if(cnt == 0){
                printf("Not Found\n");
            }
        }else if(id == "4"){
            for(book temb:f){
                if(temb.publisher == text){
                    ++cnt;
                    cout<<temb.number<<endl;
                }
            }
            if(cnt == 0){
                printf("Not Found\n");
            }
        }else if(id == "5"){
            for(book temb:f){
                if(temb.publish_year == text){
                    ++cnt;
                    cout<<temb.number<<endl;
                }
            }
            if(cnt == 0){
                printf("Not Found\n");
            }
        }else{
            for(book temb:f){
                if(temb.keywords.find(text) != temb.keywords.end()){
                    ++cnt;
                    cout<<temb.number<<endl;
                }
            }
            if(cnt == 0){
                printf("Not Found\n");
          
            }
        }
    }
    return 0;
}
