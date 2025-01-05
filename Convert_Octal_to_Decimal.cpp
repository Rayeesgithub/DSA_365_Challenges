#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the any octal Number:";
    cin>>n;
    int i=0; int ans=0;
    while(n!=0){
   int digit=n%10;
   ans+=digit*pow(8,i);
   i++;
   n=n/10;
    }
    cout<<"Octal to Decimal is:"<<ans;
}
