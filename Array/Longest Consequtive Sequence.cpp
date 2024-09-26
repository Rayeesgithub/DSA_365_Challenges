#include<bits/stdc++.h>
using namespace std;
int LongConsegutive(int arr[],int n){
  sort(arr,arr+n);
  int count=0; int Lengeth=1; int lastSmaller=INT_MIN;
  for(int i=0; i<n; i++){
    if(arr[i]-1==lastSmaller){
      count++;
      lastSmaller=arr[i];
    }
    else if(arr[i]!=lastSmaller){
      count=1;
      lastSmaller=arr[i];
    }
    Lengeth=max(Lengeth,count);
  }
  
  return Lengeth;
}
int main(){
  int n=6;
  int arr[n]={100, 200, 1, 3, 2, 4};
  int ans=LongConsegutive(arr,n);
  cout<<"Longes Consegutive Sequence is:"<<ans;
}
