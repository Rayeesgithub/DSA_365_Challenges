#include<bits/stdc++.h>
using namespace std;
vector<int> countVowelConst(string &s){
  int v=0; int c=0; 
  for(int j=0; j<s.length();j++){
    if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
      v++;
    
    }
    else{
      c++;
       } 
    }
  
  return {v,c};
}
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cout<<"enter the string:";
    cin>>s;
    vector<int> ans=countVowelConst(s);
     cout<<"vowel:"<<ans[0]<<"  "<<"conspnant:"<<ans[1]<<endl;
  }
}
