#include<bits/stdc++.h>
using namespace std;
 void nextPrumtion(int arr[],int n){
  next_permutation(arr,arr+n); // STL Function used
 for(int i=0; i<n; i++){
  cout<<arr[i]<<" ";
 }
 }
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  nextPrumtion(arr,n);
  
}


// optimal Approach'


#include<bits/stdc++.h>
using namespace std;
 void nextPrumtion(int arr[],int n){
  int index=-1;
  for(int i=n-2; i>=-0; i--){
    if(arr[i]<arr[i+1]){
      index=i;
      break;
    }
  }
  if(index=-1){
    reverse(arr,arr+n);
  }
  for(int i=index;i<n-1; i++){
    if(arr[i]>arr[index]){
      swap(arr[i],arr[index]);
      break;
    }
  }
  reverse(arr+1,arr+n);
 for(int i=0; i<n; i++){
  cout<<arr[i]<<" ";
 }
 }
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  nextPrumtion(arr,n);
  
}
