// love babbar

#include<iostream>
#include<vector>
using namespace std;
 int findMax(vector<int>&arr,int n){
  int maxi=INT_MIN;
  for(int i=0; i<n; i++){
    // approach1
    // if(arr[i]>maxi){
    //   maxi=arr[i];
    // }

    //approach2
    maxi=max(maxi,arr[i]);
  }
  return maxi;
 }
  int findMin(vector<int>&arr,int n){
  int mini=INT_MAX;
  for(int i=0; i<n; i++){
    // approach1
    // if(arr[i]<mini){
    //   mini=arr[i];
    // }

    // approach2
    mini=min(mini,arr[i]);
  }
  return mini;
 }
int main(){
    vector<int>arr ={1,4,2,6,3,10,5};
    int n=arr.size();
    int maximum=findMax(arr,n);
    int minimum=findMin(arr,n);
    cout<<"Find Maximum Element:"<<maximum<<endl;
    cout<<"FInd Minimum Elemnt :"<<minimum;
   return 0;
}
