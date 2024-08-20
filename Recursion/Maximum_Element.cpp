// Love Babbar

#include<bits/stdc++.h>
using namespace std;
void findMaxi(int arr[],int n,int i,int& maxi){
  if(i==n){
    return; 
  }
  if(arr[i]>maxi){
    maxi=arr[i];
  }
  findMaxi(arr,n,i+1,maxi);
  }
  // cout<<"Maximum Element"<<maxi;


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int maxi=INT_MIN;
  findMaxi(arr,n,0,maxi);
  cout<<"Maximum Element is:"<<maxi;
  return 0;
}
