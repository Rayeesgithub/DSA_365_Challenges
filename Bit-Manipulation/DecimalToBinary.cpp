//self

#include<bits/stdc++.h>
using namespace std;
void DecimalToBinary(int n,int i){
  int ans=0; int rem=0;
  while(n!=0){
     rem=n%2;
    ans=ans+rem*pow(10,i);
    n=n/2;
    i++;
  }
  cout<<ans;
}
int main(){
  int n;
  cin>>n;
  int i=0;
  DecimalToBinary(n,i);
}
