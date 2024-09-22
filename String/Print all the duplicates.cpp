#include<bits/stdc++.h>
using namespace std;
void removeDuplicate(string st){
  int n=st.length();
 map<char,int>mp;
for(int i=0; i<n; i++){
  mp[st[i]]++;
}
for(auto it:mp){
  cout<<it.first<<":"<<it.second<<endl;
} 
}
int main(){
 string st="bcabc";
 removeDuplicate(st);
 
}
