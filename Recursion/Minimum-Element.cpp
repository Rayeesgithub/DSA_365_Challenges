// Love babbar

#include<bits/stdc++.h>
using namespace std;
void findMaxi(int arr[],int n,int i,int& mini){
  if(i==n){
    return; 
  }
  if(arr[i]<mini){
    mini=arr[i];
  }
  findMaxi(arr,n,i+1,mini);
  }
  // cout<<"Maximum Element"<<maxi;


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int mini=INT_MAX;;
  findMaxi(arr,n,0,mini);
  cout<<"Minimum Element is:"<<mini;
  return 0;
}
