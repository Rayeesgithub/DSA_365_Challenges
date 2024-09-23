//Broute Force
void Sortstring(string st){
sort(st.begin(),st.end());
for(int i=0; i<st.length();i++){
  cout<<st[i]<<" ";
}

// approach-2
#include<bits/stdc++.h>
using namespace std;
void Sortstring(string st){
set<char>seen;
for(int i=0; i<st.length(); i++){
  seen.insert(st[i]);
}
for(auto it:seen){
  cout<<it<<" ";
}

 
}
int main(){
 string st="zxcbg";

 Sortstring(st);
 
}
