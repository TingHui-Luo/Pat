

//
// Created by Dell on 2022-04-04.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;


string number[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string wei[4] = {"1","Shi","Bai","Qian"};
int main(){
   string s;
   cin>>s;
   if(s == "0") {
       cout<<"ling";
       return 0;
   }
   string ans = "";
   int sym = 0;
   if(s[0] == '-') {
       ans +="Fu";
       sym = 1;
       s = s.substr(1);
   }
   if(s.size() == 9){
       ans += " "+number[s[0]-'0'] + " Yi";
       s = s.substr(1);
   }
   if(s.size()>4){
       string tem = s.substr(0,s.size()-4);
       int all_zeor = 1;

       for(char c:tem) {
           if(c!='0') all_zeor = 0;
       }
       if(all_zeor == 0 ){
           int chusym = 0;
           char lastchar = '-';
           for(int i = 0;i<tem.size();++i){

               if(tem[i] == '0') {
                   if(!chusym) {
                       ans += " ling";
                       chusym = 1;
                   }
               }else{

                   if(i!=tem.size()-1)
                       ans +=" "+number[tem[i] -'0']+" "+wei[tem.size()-i-1];
                   else{
                       ans += " "+number[tem[i] -'0'];
                   }
                   chusym = 1;
               }
               lastchar = tem[i];
           }
       }
       s = s.substr(s.size()-4,4);
      if(all_zeor != 1)  ans += " Wan";
   }
   if(s.size() >0){
       string tem = s;
       int all_zeor = 1;
       for(char c:tem) {
           if(c!='0') all_zeor = 0;
       }
       if(all_zeor == 0 ){
           int chusym = 0,shuzi = 0;
           char lastchar = '-';
           for(int i = 0;i<tem.size();++i){
               if(tem[i] == '0') {
                   if(!chusym) {
                       ans += " ling";
                       chusym = 1;
                   }
               }else{
                   if(lastchar == '0' && shuzi){
                       ans += " ling";
                   }
                   if(i!=tem.size()-1)
                       ans +=" "+number[tem[i] -'0']+" "+wei[tem.size()-i-1];
                   else{
                       ans += " "+number[tem[i] -'0'];
                   }
                   shuzi = 1;
                   chusym = 1;
               }
               lastchar = tem[i];
           }
       }
   }
   if(!sym) ans = ans.substr(1);
   cout<<ans;
    return 0;
}