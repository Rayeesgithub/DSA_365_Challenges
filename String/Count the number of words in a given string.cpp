void solve(string & str){
 int count=0;
 string temp="";

 for(int i=0; i<str.size(); i++){
    if(str[i]!=' '){
        temp+=str[i];
    }

    else {
        count++;
        temp="";
    }
 }
 if(!temp.empty()){
    count++;
 }

 cout<<"Number of words:"<<count;
}


















//
#include<bits/stdc++.h>
using namespace std;
int Countwords(string st){
  int count=1;
  for(int i=0; i<st.length(); i++){
    if(st[i]==' '){
      count++;
    }
  }
  return count;
}
int main(){
 string st="Hi mai Rayees Alam";

 int ans=Countwords(st);
 cout<<"Number of Words:"<<ans;
}
