#include<bits/stdc++.h>
using namespace std;
void Permutation(string s,int i){
  if(i>=s.length()){
    cout<<s<<" ";
  }
  for(int j=i; j<s.length(); j++){
    swap(s[i],s[j]);
    Permutation(s,i+1);
    swap(s[i],s[j]);
  }
}
int main(){
  string s="abc";
  int i=0;
  Permutation(s,i);
}
