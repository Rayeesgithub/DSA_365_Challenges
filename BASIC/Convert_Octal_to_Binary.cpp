#include<bits/stdc++.h>
using namespace std;
int octalToDecimal(int n){
     int i=0; int ans=0;
    while(n!=0){
   int digit=n%10;
   ans+=digit*pow(8,i);
   i++;
   n=n/10;
    }
    return ans;
}
string DecimalToBinary(int n){
    string ans="";
  while(n!=0){
    int rem=n%2;
   ans=ans+to_string(rem);
    n=n/2;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){
    int n;
    cout<<"enter the any octal Number:";
    cin>>n;
    int ans=octalToDecimal(n);
   cout<<"Octal to Decimal is:"<<ans<<endl;
   string result=DecimalToBinary(ans);
   cout<<"Decimal to Binary is:"<<result;
}
