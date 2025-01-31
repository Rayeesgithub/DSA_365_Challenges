https://www.geeksforgeeks.org/largest-and-smallest-digit-of-a-number/

#include<bits/stdc++.h>
using namespace std;
void findMini_Maxi(int n){
    int mini=INT_MAX; int maxi=INT_MIN;
   while(n!=0){
    int digit=n%10;
    if(digit>maxi){
        maxi=digit;
    }
    else if(digit<mini){
        mini=digit;
    }
    n=n/10;
   }

   cout<<"Maximum Elemnt is:"<<maxi<<" "<<"Minimum Elemnt is:"<<mini;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cout<<"enter the Number:";
        cin>>n;
        findMini_Maxi(n);
    }
}
