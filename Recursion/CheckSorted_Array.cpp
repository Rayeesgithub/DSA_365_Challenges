//love babbar

#include<bits/stdc++.h>
using namespace std;
bool checkSort(int arr[],int n,int i){
 if(i==n) return true;
 if(arr[i]>arr[i+1]){
  return false;
 }
 checkSort(arr,n,i+1);
 return true;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  if(checkSort(arr,n,0)){
    cout<<" this is Sorted Array;";
  }
  else{
    cout<<"This is Not Sorted Array";
  }
  return 0;
}
