//https://geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// striver sheet



#include<bits/stdc++.h>
using namespace std;
void LeaderArr(int arr[],int n,vector<int>&ans){
 int maxi=arr[n-1];
 ans.push_back(maxi);
 for(int i=n-2;i>=0; i--){
  if(arr[i]>maxi){
    ans.push_back(arr[i]);
    maxi=arr[i];
  }
 }
}
int main(){
  int n=6;
  int arr[n]={10, 22, 12, 3, 0, 6};
  vector<int>ans;
  LeaderArr(arr,n,ans);
  for(int i=ans.size()-1; i>=0; i--){
   cout<<ans[i]<<" ";
  }
}
