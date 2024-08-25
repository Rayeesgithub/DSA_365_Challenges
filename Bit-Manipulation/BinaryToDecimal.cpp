//self
#include<bits/stdc++.h>
using namespace std;
int main(){
 string s;
 cin>>s;
  int ans=0; int index=0;
  for(int i=s.length()-1; i>=0; i--){
    int bit=s[i]-'0'; // convert string to integer
    ans=ans+bit*pow(2,index);
    index++;
  }
  cout<<ans;
}
