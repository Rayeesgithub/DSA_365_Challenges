#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter Any decimal Number:";
    cin>>n;
    string ans="";
    while(n!=0){
      int digit=n%8;
      ans+=to_string(digit);
      n=n/8;
    }
    reverse(ans.begin(),ans.end());
    cout<<"Decimal to Octal Number is:"<<ans;
}
