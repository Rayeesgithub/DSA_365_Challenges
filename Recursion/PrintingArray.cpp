#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[],int n,int index=0){
  if(index==n) return;
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
  cout<<"printintg Element:";
  printArr(arr,n);
}
