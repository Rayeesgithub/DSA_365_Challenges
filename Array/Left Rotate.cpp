// striver sheet
#include<bits/stdc++.h>
using namespace std;
// approach1
// void leftRotate(int arr[],int n){
//   int temp=arr[0];
//   for(int i=0; i<n-1; i++){
//    arr[i]=arr[i+1];
//   }
//   arr[n-1]=temp;
// }

// second approach
void leftRotate(int arr[],int n){
  int temp=arr[0];
  for(int i=1; i<n; i++){
    arr[i-1]=arr[i];
  }
  arr[n-1]=temp;
}
int main(){
  int arr[]={1,2,3,4,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  leftRotate(arr,n);
  cout<<"after rotate"<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}
