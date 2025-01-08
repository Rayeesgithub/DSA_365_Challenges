#include<bits/stdc++.h>
using namespace std;
int findGCD(int n,int m){
  int ans=1;
  for(int i=1; i<=min(n,m); i++){
    if(n%i==0 && m%i==0){
      ans=i;
    }
  }
  return ans;
}
void solveFraction(int num1,int den1,int num2,int den2){
  int numerator=num1*den2+num2*den1;
   int denometr=den1*den2;
   int gcd=findGCD(numerator,denometr);
   numerator=numerator/gcd;
   denometr=denometr/gcd;
   cout<<numerator<<"/"<<denometr;
}
int main(){
  int t;
  cin>>t;
  while(t--){
  int num1,den1; int num2,den2;
  cout<<"Enter the numerator or denometer of first fraction:";
  cin>>num1>>den1;
  cout<<"enter the numrator and denometr of seond fraction:";
  cin>>num2>>den2;
  solveFraction(num1,den1,num2,den2);
  cout<<endl;
  }
}
