// love babbar 

#include<iostream>
using namespace std;
int BinarySearch(int arr[],int s,int e,int &target){
  int mid=s+(e-s)/2;
  if(s>e){
    return -1;
  }
  if(arr[mid]==target) return mid;
  else if(arr[mid]<target){
    return BinarySearch(arr,mid+1,e,target);
  }
  else{
  return BinarySearch(arr,s,mid-1,target);
  }
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int target=6;
  int s=0; int e=n;
  int ans=BinarySearch(arr,s,e,target);
   if(ans==-1){
    cout<<"Target Not Found";
   }
   else{
    cout<<"Target Element is:"<<arr[ans];
    // cout<<"Target Element is:"<<ans;//index return 
   }
}
