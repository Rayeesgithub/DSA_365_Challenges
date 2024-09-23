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
