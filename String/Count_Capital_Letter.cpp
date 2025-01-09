#include<bits/stdc++.h>
using namespace std;
int countCapital(string &s){
  int count=1;
  for(int i=0; i<s.length();i++){
    if(s[i]>='A' && s[i]<='Z'){
      count++;
    }
  }
  return count;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cout<<"Enter the String:";
    cin>>s;
    int ans=countCapital(s);
    cout<<"Number of Capital Alphabet is:"<<ans<<endl;
  }
}
