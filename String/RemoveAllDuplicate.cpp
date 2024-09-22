// Broute Force
#include<bits/stdc++.h>
using namespace std;
void removeDuplicate(string st){
  int n=st.length();
  set<char>s;string ans;

  for(int i=0; i<n;i++){
  if(s.find(st[i])==s.end()){
   ans.push_back(st[i]);
   s.insert(st[i]);
  }
  }
  for(int i=0; i<ans.size();i++){
 cout<<st[i]<<" ";
 }
}
int main(){
 string st="bcabc";
 removeDuplicate(st);
 
}


//optimal Approach
void removeDuplicate(string st){
  int n=st.length();
  string ans; bool mp[26]={false};
for(int i=0; i<n; i++){
if(mp[st[i]-'a']==false){
  ans.push_back(st[i]);
}
mp[st[i]-'a']=true;
}

  for(int i=0; i<ans.size();i++){
 cout<<st[i]<<" ";
 }
}
