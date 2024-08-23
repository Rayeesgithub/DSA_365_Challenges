// strver

#include<bits/stdc++.h>
using namespace std;
void findSubsequence(string s, string output,int i){
  if(i==s.length())
   {
    cout<<output<<" "; return;
   }
  // exclude
  findSubsequence(s,output,i+1);
    // include
    //output.push_back(str[i]);
   //output=output+str[i];
  findSubsequence(s,output+s[i],i+1);
}
int main(){
  string s;
  cin>>s;
  string output="";
  findSubsequence(s,output,0);
 
}
